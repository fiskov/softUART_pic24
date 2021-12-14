#ifndef __BOARD_H
#define __BOARD_H

#include <xc.h>

//PIN CONFIG
#define _DEBUG 			_RA0    
#define _DEBUG_TRIS 	_TRISA0
#define _DEBUG2 			_RA1    
#define _DEBUG2_TRIS 	_TRISA1
//uart
#define _UART1_TX	_RB7	//pin16
#define _UART1_RX	_RB2	//pin6
#define _UART2_TX	_RB0	//pin4
#define _UART2_RX	_RB1	//pin5

#define _UART1_TX_TRIS	_TRISB7
#define _UART1_RX_TRIS	_TRISB2
#define _UART2_TX_TRIS	_TRISB0	
#define _UART2_RX_TRIS	_TRISB1	

#define reverse_pin(pin) do {if (pin) pin=0; else pin=1;} while(0)
/* a=target variable, b=bit number to act upon 0-n */
#define BIT_SET(a,b) do{a |= (1<<(b)); } while(0)
#define BIT_CLEAR(a,b) do{a &= ~(1<<(b));} while(0)
#define BIT_FLIP(a,b) ((a) ^= (1ULL<<(b)))
#define BIT_CHECK(a,b) (!!((a) & (1ULL<<(b))))        // '!!' to make sure this returns 0 or 1
#define BIT_TOGGLE(X) do { if (X) X=0; else X=1; } while(0)
#define BIT_UPDATE(a,b,X) do{ if(X) a |= (1<<(b)); else a &= ~(1<<(b)); } while(0)


#endif	/* __BOARD_H */
