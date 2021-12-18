/** @file main.c
 */
#include "config_bits.h" 
#include "common.h"
#include "common_types.h"
#include "board.h"

#include "softUART.h"
#include "cmd.h"
#include "init.h"

#define SOFTUART_BAUDRATE   19200
#define SOFTUART_TIMEOUT_MS 5

static uint8_t timer1ms = 0;
static data_t data;
  
int main(void) 
{ 
  uint16_t tmrSend = 0;
  
  board_init( &data.isMaster, &data.addr ); //tmr1
  
  softUART_init(SOFTUART_BAUDRATE, SOFTUART_TIMEOUT_MS);
      
  while (1) {
    ClrWdt();
      
    if (timer1ms) {
        timer1ms = 0;
        
        if (data.isMaster) {
            //master send request
            tmrSend++;
            switch (tmrSend) {
                case 1:
                    cmdMakeTest(data.txBfr, '1', &data.txLen);
                    softUART_send(data.txBfr, data.txLen);
                    break;
                case 30:
                    cmdMakeTest(data.txBfr, '2', &data.txLen);
                    softUART_send(data.txBfr, data.txLen);
                    break;
                case 100:
                    tmrSend = 0;
                    break;
            }
        } else {
            // slave read and answer
            if ( softUART_read(data.rxBfr, &data.rxLen) )
                if ( cmdParse(&data) )
                    softUART_send( data.txBfr, data.txLen);
        }
    }
  }
  
  return 0;
}

/// pulse counter
uint16_t counter;
void _ISR _NOPSV _INT1Interrupt(void) 
{
    counter++;
    _INT1IF = 0;
}

/// Interrupt 1000 Hz
void _ISR _NOPSV _T1Interrupt(void) 
{
    timer1ms = 1;

    // Once per second get pulse counter
    static uint16_t timer1000 = 1000;
    if (--timer1000 == 0) 
    {
        data.counter = counter;
        counter = 0;
        
        timer1000 = 1000;
    }
    
    _T1IF = 0;
}
