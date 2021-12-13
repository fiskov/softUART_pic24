#ifndef __CRC_H
#define __CRC_H

#include "common.h"
//функция считает от 0 до endPos байта однобайтное CRC, записывает в endPos++
unsigned char getCrc8forTxString(unsigned char *s, int cnt);

//LRC как в MODBUS ASCII
unsigned char getLRC(char *s, int cnt);


//CRC-16-CCITT для массива Int (манчестер)
uint16_t Crc16i(uint16_t *pcBlock, int16_t len);

#endif

