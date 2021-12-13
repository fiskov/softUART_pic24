#ifndef __CRC_H
#define __CRC_H

#include "common.h"
//������� ������� �� 0 �� endPos ����� ����������� CRC, ���������� � endPos++
unsigned char getCrc8forTxString(unsigned char *s, int cnt);

//LRC ��� � MODBUS ASCII
unsigned char getLRC(char *s, int cnt);


//CRC-16-CCITT ��� ������� Int (���������)
uint16_t Crc16i(uint16_t *pcBlock, int16_t len);

#endif

