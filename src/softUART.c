#include "softUART.h"

typedef struct {
    uint8_t * bfr;
    uint8_t bitbfr;
    uint16_t pos, len, bitpos, tmr;    
} softBfr_t;

static softBfr_t rx, tx;

static bool isMaster = false, isTx = false;


static void setPin_mode_tx(void)
{
  SOFT_UART_PIN_CN = 0;	// dinable CN0 (RA4)
  SOFT_UART_PIN_TRIS = 0; //output
  Nop();
  SOFT_UART_PIN_TX = 1;
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
}


uint8_t softUART_trncv(uint16_t * timer1ms)
{
    uint8_t res = 0;
    if (rx.len && rx.tmr > SOFT_UART_RX_TMR) 
    {
        res = rx.pos;
    }
  return res;
}

void softUART_send(uint8_t bfr[], uint8_t length) 
{
    int i;
    for (i=0; i<length; i++) tx.bfr[i]=bfr[i];
    tx.pos = 0;
    tx.len = length;
    setPin_mode_tx();
    isTx = true;
    SOFT_UART_TIMER_ON = 1;
}

void _ISR _NOPSV SOFT_UART_TIMER_INT_PROC(void){
    SOFT_UART_TIMER_INT_FLAG = 0;
    if (isTx)
    {
        if (tx.len != tx.pos) { 
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
        rx.tmr = 0;

        rx.bitpos--;
        rx.bitbfr >>= 1;
        
        if (SOFT_UART_PIN_RX) 
            rx.bitbfr |= 0x80;
        
        if (!rx.bitpos) 
        { // stop-bit
            SOFT_UART_TIMER_ON = 0; // rx-tmr disable;
            rx.bitpos = 0;  // wait next byte
            rx.bfr[rx.len++] = rx.bitbfr; // write bit_bfr to rx_bfr                        
        }
    }
}   

void _ISR _NOPSV _CNInterrupt(void){
    
    if ((rx.bitpos == 0) && (SOFT_UART_PIN_RX == 1)) { // ...|'''
        rx.bitpos = 8;
        rx.bitbfr = 0;
        SOFT_UART_TIMER_TMR = 0;
        SOFT_UART_TIMER_ON = 1; //start receive = start timer
    }
    _CNIF = 0 ; // Clear Interrupt Flag
}
