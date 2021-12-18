#ifndef __CRC_H
#define __CRC_H

#include "stdint.h"

/// Calc CRC8-Dallas
uint8_t getCrc8forTxString(uint8_t *s, int16_t cnt);

/// Calc LRC MODBUS ASCII
uint8_t getLRC(uint8_t *s, int16_t cnt);

/// Calc CRC-16-CCITT for Int16-array
uint16_t Crc16i(uint16_t *pcBlock, int16_t len);

#endif

