#include "init.h"
#include "common.h"
#include "board.h"

void init(void)
{
  CLKDIV = 0; // FRC div
  Nop();
  
#if defined(__PIC24F16KA102__)
  AD1PCFG = 0xFFFF; // all pin digital
#else
  ANSA=0;
  ANSB=0; 
#endif

  //tmr1 = 1000 Hz
  PR1 = FCY / 1000; 
  _TON = 1; 
  _T1IE = 1;  
  
  _DEBUG_TRIS = 0;
}