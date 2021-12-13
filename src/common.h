#ifndef __COMMON_H
#define __COMMON_H

#define XTFREQ          8000000UL         //On-board Crystal frequency
#if defined(__PIC24F16KA102__)
	#define PLLMODE         1               //On-chip PLL setting
#else
	#define PLLMODE         4
#endif
#define FCY             (XTFREQ*PLLMODE/2)        //Instruction Cycle Frequency

#include <libpic30.h>
#include <xc.h>

#include <math.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#define _NOPSV __attribute__((no_auto_psv))

//concat define
#define JOIN_(a, b) a ## b
#define JOIN(a, b) JOIN_(a, b)
#define JOIN3_(a, b, c) a ## b ## c
#define JOIN3(a, b, c) JOIN3_(a, b, c)

#endif	/* COMMON_H */
