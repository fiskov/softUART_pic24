#include "init.h"
#include "common.h"
#include "board.h"

void board_init(bool * isMaster, uint8_t * addr)
{
  CLKDIV = 0; // FRC div
  Nop();
  
#if defined(__PIC24F16KA102__)
  AD1PCFG = 0xFFFF; // all pin digital
#else
  ANSA=0;
  ANSB=0; 
#endif

  // Pins init
  _FREQ_TRIS = 1;
  
  _MASTER_TRIS = 1;
  _SLAVE_2_TRIS = 1;  
  
  // tmr1 = 1000 Hz
  PR1 = FCY / 1000; 
  _TON = 1; 
  _T1IE = 1;  
  
  // int1 - counter
  _INT1IE = 1;
  
  // Variables init
  *isMaster = (_MASTER_PIN) ? true : false;
  *addr = '0';
  if (*isMaster == false) 
      *addr = (_SLAVE_2_PIN) ? '2' : '1';
}