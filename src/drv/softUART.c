#include "softUART.h"
#include "board.h"
#include "string.h"

#define SOFT_BFR_SIZE 32    // 2^n = 8, 16, 32, 64...
#define SOFT_BFR_SIZE_MASK (SOFT_BFR_SIZE-1)

typedef struct {
    uint8_t bfr[SOFT_BFR_SIZE];
    uint8_t bitbfr; 
    int8_t bitpos;
    uint16_t pos, len, tmr;
} softBfr_t;

static softBfr_t rx, tx;

static bool isTx = false;
static uint16_t soft_uart_rx_timeout_ms = 5;

/// Switch driver to transmite mode
static void setPin_mode_tx(void)
{
  SOFT_UART_PIN_CN = 0;	// disable CN0 (RA4)
  SOFT_UART_PIN_TRIS = 0; //output
  SOFT_UART_TIMER_TMR = 0;
  SOFT_UART_TIMER_ON = 1;
  isTx = true;    
}

/// Switch driver to receive mode
static void setPin_mode_rx(void)
{
  SOFT_UART_PIN_TRIS = 1; //input
  _CNIF = 0;	// Clear Interrupt Flag
  SOFT_UART_PIN_CN = 1;	// enable CN0 (RA4)
  _CNIE = 1;	// CN enable
  SOFT_UART_TIMER_ON = 0;
  isTx = false;
}


void softUART_init(uint32_t baud_rate, uint16_t rx_timeout_ms)
{  
  setPin_mode_rx();

  SOFT_UART_TIMER_PERIOD = (FCY / baud_rate);
  soft_uart_rx_timeout_ms = rx_timeout_ms;
  SOFT_UART_TIMER_INT = 1;
  SOFT_UART_TIMER_ON = 1;
}


bool softUART_read(uint8_t rxBfr[], uint8_t *length)
{
    int i;
    bool res = false;
    
    if (rx.len)
        if (rx.tmr++ >= soft_uart_rx_timeout_ms) 
        {            
            for (i=0; i<rx.len; i++)
                rxBfr[i] = rx.bfr[i];
            
            *length = rx.len;
            rx.len = 0;
            
            res = true;
        }
    return res;
}

void softUART_send(uint8_t bfr[], uint8_t length) 
{
    int i;
    for (i=0; i<length; i++) tx.bfr[i]=bfr[i];
    
    tx.pos = 0;
    tx.len = length;
    tx.bitpos = 0;
    setPin_mode_tx();
}

/**
 * Timer interrupt. Transmite or read in poll-mode 
 */
void _ISR _NOPSV SOFT_UART_TIMER_INT_PROC(void){
    SOFT_UART_TIMER_INT_FLAG = 0;
    if (isTx)
    {
        switch (tx.bitpos) {
            case 0: // startBit
                SOFT_UART_PIN_TX = 0; 
                tx.bitbfr = tx.bfr[tx.pos++]; 
            break; 

            default: // data bits
                SOFT_UART_PIN_TX = (tx.bitbfr & 1);
                tx.bitbfr >>= 1; 
            break;

            case 9: // stopBit
                SOFT_UART_PIN_TX = 1; 
                if (tx.pos >= tx.len) 
                    setPin_mode_rx(); 
                else 
                    tx.bitpos = -1;
            break; 
        }
        tx.bitpos++;
        
    } else {
        
        rx.bitbfr >>= 1;
        if (SOFT_UART_PIN_RX)
            rx.bitbfr |= 0x80;        
        
        rx.bitpos--;
        if (rx.bitpos < 0) 
        { // stop-bit
            SOFT_UART_TIMER_ON = 0; // rx-tmr disable;
            SOFT_UART_PIN_CN = 1;
            rx.tmr = 0;
            rx.bitpos = 0;  // wait next byte
            rx.bfr[rx.len] = rx.bitbfr; // write bit_bfr to rx_bfr                        
            rx.len++;
            rx.len &= SOFT_BFR_SIZE_MASK;
        }
    }
}   

/// Change_Notification interrupt -> start timer in Rx-mode 
void _ISR _NOPSV _CNInterrupt(void){
    _CNIF = 0 ; // Clear Interrupt Flag
    
    if ((rx.bitpos == 0) && (SOFT_UART_PIN_RX == 0)) { // '''|...
        SOFT_UART_PIN_CN = 0;	// disable CN0 (RA4)        
        rx.bitpos = 8;
        rx.bitbfr = 0;
        SOFT_UART_TIMER_ON = 1; //start receive = start timer
        SOFT_UART_TIMER_TMR = SOFT_UART_TIMER_PERIOD/2;
    }
}
