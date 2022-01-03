#ifndef __BOARD_H
#define __BOARD_H

#include <xc.h>

// PIN CONFIG
#define _FREQ_TRIS 	_TRISB15

// Adress pins
#define _MASTER_PIN _RA7
#define _MASTER_TRIS 	_TRISA7
#define _SLAVE_2_PIN _RA6
#define _SLAVE_2_TRIS 	_TRISA6

// debug
#define _DEBUG_PIN   _LATA0
#define _DEBUG_TRIS  _TRISA0


#define reverse_pin(pin) do {if (pin) pin=0; else pin=1;} while(0)
/* a=target variable, b=bit number to act upon 0-n */
#define BIT_SET(a,b) do{a |= (1<<(b)); } while(0)
#define BIT_CLEAR(a,b) do{a &= ~(1<<(b));} while(0)
#define BIT_FLIP(a,b) ((a) ^= (1ULL<<(b)))
#define BIT_CHECK(a,b) (!!((a) & (1ULL<<(b))))        // '!!' to make sure this returns 0 or 1
#define BIT_TOGGLE(X) do { if (X) X=0; else X=1; } while(0)
#define BIT_UPDATE(a,b,X) do{ if(X) a |= (1<<(b)); else a &= ~(1<<(b)); } while(0)


#endif	/* __BOARD_H */
