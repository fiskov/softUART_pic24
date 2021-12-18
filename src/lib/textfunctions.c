#include "textfunctions.h"
#include "stdlib.h"

/// Insert integer to string in radix 10
void myIntToStr(char *bfr, int number, int length, bool leadingZero)
{
    int i, sign=0;
    div_t d;
    if (length>0) 
    {
        for (i=0; i<length-1; i++) 
            bfr[i]=(leadingZero?'0':' ');
        
        if (number < 0) 
            {number = -number; sign=1;}
        
        d = div(number, 10);
        length--;
        bfr[length]= (d.rem) + '0';
        while ( length-- && d.quot && length>0) {
            d = div(d.quot, 10);
            bfr[length] = (d.rem) + '0';
        }
        if (sign) bfr[length] = '-';
    }
}

/// Return HEX symbol for integer
char hex2char(uint8_t number){
    char hex[] = "0123456789ABCDEF";
    return hex[number & 0xF];
}
