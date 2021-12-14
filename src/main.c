#include "config_bits.h" 
#include "common.h"
#include "common_types.h"
#include "softUART.h"
#include "cmd.h"
#include "init.h"
#include "board.h"
#include "drv_uart.h"

static uint8_t timer1ms = 0;
static uint8_t rxBfr[16], txBfr[16];
static uint8_t len = 0;
int main(void) 
{
  init(); //tmr1

  softUART_config_t cfg = { .rxBfr=rxBfr, .txBfr=txBfr, .isMaster=false, .speed=19200 };  
  softUART_init(&cfg); //tmr3, CN1
  
  while (1) {
    
    if (timer1ms)
    {
        timer1ms = 0;
        
        len = softUART_trncv();

        if ( len >= CMD_LENGTH ) 
            //if ( cmdParse(rxBfr, txBfr) ) 
            {
              //_DEBUG = 1; 
              softUART_send( txBfr, CMD_RESP_LENGTH );
              //_DEBUG = 0;
            }
    }
  }
  
  return 0;
}

void _ISR _NOPSV _T1Interrupt(void) 
{
  timer1ms = 1;
  _T1IF = 0;
}
