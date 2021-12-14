#include "softUART.h"
#include "board.h"

typedef struct {
    uint8_t * bfr;
    uint8_t bitbfr; 
    int16_t bitpos;
    uint16_t pos, len, tmr;
} softBfr_t;

static softBfr_t rx = {0}, tx = {0};

static bool isMaster = false, isTx = false;


static void setPin_mode_tx(void)
{
  SOFT_UART_PIN_CN = 0;	// disable CN0 (RA4)
  SOFT_UART_PIN_TRIS = 0; //output
  SOFT_UART_TIMER_TMR = 0;
  SOFT_UART_TIMER_ON = 1;
  Nop();
}
static void setPin_mode_rx(void)
{
  SOFT_UART_PIN_TRIS = 1; //input
  _CNIF = 0;	// Clear Interrupt Flag
  SOFT_UART_PIN_CN = 1;	// enable CN0 (RA4)
  _CNIE = 1;	// CN enable
  SOFT_UART_TIMER_ON = 0;
}


void softUART_init(softUART_config_t * p_cfg)
{
  rx.bfr = p_cfg->rxBfr;
  tx.bfr = p_cfg->txBfr;
  isMaster = p_cfg->isMaster;
  
  setPin_mode_rx();

  SOFT_UART_TIMER_PERIOD = (FCY / p_cfg->speed);
  SOFT_UART_TIMER_INT = 1;
  SOFT_UART_TIMER_ON = 1;  
  SOFT_UART_PIN_PUE = 1;
}


uint8_t softUART_trncv(void)
{
    uint8_t res = 0;
    
    if (rx.len)
        if (rx.tmr++ > SOFT_UART_RX_TMR)
    {
        _DEBUG = 1;
        res = rx.pos;
        //rx.len = 0;
        _DEBUG = 0;
    }
  return res;
}

void softUART_send(uint8_t bfr[], uint8_t length) 
{
    int i;
    for (i=0; i<length; i++) tx.bfr[i]=bfr[i];
    
    tx.pos = 0;
    tx.len = length;
    tx.bitbfr = tx.bfr[tx.pos++];
    setPin_mode_tx();
    isTx = true;    
}

void _ISR _NOPSV SOFT_UART_TIMER_INT_PROC(void){
    SOFT_UART_TIMER_INT_FLAG = 0;
    if (isTx)
    {
        if (tx.pos < tx.len) { 
            if (tx.bitpos == 10) {
                tx.bitpos = 0;
                tx.bitbfr = tx.bfr[tx.pos++]; // get symbol from buffer
            }
        }

        if (tx.bitpos < 10) { // 10 bit = start_bit + 8 + stop_bit
            switch (tx.bitpos) {
                case 0: SOFT_UART_PIN_TX = 0; break; // startBit
                case 9: SOFT_UART_PIN_TX = 1; if (tx.len == tx.pos) setPin_mode_rx(); break; // stopBit
                default: if (tx.bitbfr & 1) SOFT_UART_PIN_TX = 1; else SOFT_UART_PIN_TX = 0;
                         tx.bitbfr >>= 1;
            }
            tx.bitpos++;
        }
    } else {
        rx.bitbfr >>= 1;
        if (SOFT_UART_PIN_RX)
            rx.bitbfr |= 0x80;        
        
        rx.bitpos--;
        if (rx.bitpos < 0) 
        { // stop-bit            
            _DEBUG2=1;
            SOFT_UART_TIMER_ON = 0; // rx-tmr disable;
            SOFT_UART_PIN_CN = 1;
            rx.tmr = 0;
            rx.bitpos = 0;  // wait next byte
            rx.bfr[rx.len++] = rx.bitbfr; // write bit_bfr to rx_bfr                        
            _DEBUG2=0;
        }
    }
}   

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
