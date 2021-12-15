#include "config_bits.h" 
#include "common.h"
#include "common_types.h"
#include "softUART.h"
#include "cmd.h"
#include "init.h"
#include "board.h"

static uint8_t timer1ms = 0;
static uint8_t txBfr[16]="UU\r";

int main(void) 
{
  init(); //tmr1
  bool isMaster = (_MASTER_PIN) ? true : false;
  uint8_t addr = (_SLAVE_2_PIN) ? '2' : '1';
  if (isMaster) addr = 0;
  
  softUART_init(19200); //tmr3, CN1
      
  while (1) {
      ClrWdt();
    
    if (timer1ms) {
        timer1ms = 0;
        
        if (isMaster) {
            static uint16_t tmrSend=0;
            tmrSend++;
            switch (tmrSend) {
            case 100:
                txBfr[0] = '1';
                softUART_send( txBfr, CMD_LENGTH);
                break;
            case 130:
                txBfr[0] = '2';
                softUART_send( txBfr, CMD_LENGTH);
                break;
            case 1000:
                tmrSend = 0;
                break;
            }
        }
        
        uint8_t * rxBfr = {0};
        uint8_t len = softUART_trncv(rxBfr);
        if ( len >= CMD_LENGTH ) 
            if ( cmdParse(rxBfr, txBfr, addr) ) 
                if (!isMaster)
                    softUART_send( txBfr, CMD_RESP_LENGTH);
    }
  }
  
  return 0;
}

void _ISR _NOPSV _T1Interrupt(void) 
{
  timer1ms = 1;
  _T1IF = 0;
}
