#ifndef __TEXTFUNCTIONS_H
#define __TEXTFUNCTIONS_H

#include "stdint.h"
#include "stdbool.h"

/// Insert integer to string in radix 10
void myIntToStr(char *bfr, int number, int length, bool leadingZero);

/// Return HEX symbol for integer
char hex2char(uint8_t number);

#endif 
