/** @file main.c
 */
#include "config_bits.h" 
#include "common.h"

#include "softUART.h"
#include "cmd.h"
#include "init.h"
#include "board.h"
#include "crc.h"

#define SOFTUART_BAUDRATE   19200
#define SOFTUART_TIMEOUT_MS 5

static uint8_t timer1ms = 0;
static uint8_t txBfr[32], rxBfr[32];
uint16_t tmrSend = 0;
bool isMaster = false;  
uint8_t len, addr = 0;
  
int main(void) 
{ 
  board_init( &isMaster, &addr ); //tmr1
  
  softUART_init(SOFTUART_BAUDRATE, SOFTUART_TIMEOUT_MS);
      
  while (1) {
      ClrWdt();
      
    if (timer1ms) {
        timer1ms = 0;
        
        if (isMaster) {
            tmrSend++;
            switch (tmrSend) {
                case 0:
                    cmdMakeTest(txBfr, '1', &len);
                    softUART_send( txBfr, len);
                    break;
                case 30:
                    cmdMakeTest(txBfr, '2', &len);
                    softUART_send( txBfr, len);
                    break;
                case 100:
                    tmrSend = 0;
                    break;
            }
        } else {       
            if ( softUART_read(rxBfr, &len) )
                if ( cmdParse(addr, rxBfr, len, txBfr, &len) )
                    softUART_send( txBfr, len);
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
