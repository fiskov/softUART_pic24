#include "config_bits.h" 
#include "common.h"
#include "common_types.h"
#include "softUART.h"
#include "cmd.h"
#include "init.h"
#include "board.h"
#include "drv_uart.h"

uint16_t timer1ms = 0;

int main(void) 
{
  init(); //tmr1

  uint8_t rx_k[16], tx_k[16] = "hello\r"; 
  uint16_t rxLen_k;
  uartInit_it(1, 19200, rx_k, sizeof(rx_k), &rxLen_k);

  uint8_t rxBfr[16], txBfr[16];
  softUART_config_t cfg = { .rxBfr=rxBfr, .txBfr=txBfr, .isMaster=false, .speed=19200 };
  
  softUART_init(&cfg); //tmr3, CN1
  
  while (1) {
    uint8_t len = softUART_trncv(&timer1ms);
    
    if ( len >= CMD_LENGTH ) 
      if ( cmdParse(rxBfr, txBfr) )
        softUART_send( txBfr, CMD_RESP_LENGTH );
    
    if (timer1ms >= 100) {
        _DEBUG = 1;
        softUART_send( (uint8_t *)"hello\r", 6);
        uartSend(1, tx_k, 6);
        timer1ms = 0;
        _DEBUG = 0;
    }
  }
  
  return 0;
}

void _ISR _NOPSV _T1Interrupt(void) 
{
  timer1ms++;
  _T1IF = 0;
}
