#include "config_bits.h" 
#include "common.h"
#include "common_types.h"
#include "softUART.h"
#include "cmd.h"
#include "init.h"
#include "board.h"
#include "crc.h"

static uint8_t timer1ms = 0;
static uint8_t txBfr[32]="1???\r", rxBfr[32];

static bool isMaster = false;
static uint8_t addr = 0;
static uint8_t len = 0;

int main(void) 
{
  init(); //tmr1
  isMaster = (_MASTER_PIN) ? true : false;
  addr = (_SLAVE_2_PIN) ? '2' : '1';
  if (isMaster) addr = 0;
  
  softUART_init(38400); //tmr3, CN1
      
  while (1) {
      ClrWdt();
    
    if (timer1ms) {
        timer1ms = 0;
        
        if (isMaster) {
            static uint16_t tmrSend=0;
            tmrSend++;
            switch (tmrSend) {
            case 1:
                txBfr[0] = '1';
                //txBfr[CMD_LENGTH-1] = getCrc8forTxString(txBfr, CMD_LENGTH-1);
                softUART_send( txBfr, 5);
                break;
            case 30:
                txBfr[0] = '2';
                //txBfr[CMD_LENGTH-1] = getCrc8forTxString(txBfr, CMD_LENGTH-1);
                softUART_send( txBfr, 5);
                break;
            case 100:
                tmrSend = 0;
                break;
            }
        }
        
        len = softUART_trncv(rxBfr);
        if ( len && !isMaster)
            if ( cmdParse(addr, rxBfr, len, txBfr, &len) )
                softUART_send( txBfr, len);
    }
  }
  
  return 0;
}

void _ISR _NOPSV _T1Interrupt(void) 
{
  timer1ms = 1;
  _T1IF = 0;
}
