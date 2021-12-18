/** 
 * @file Common-types header
 */
#ifndef __COMMON_TYPES_H
#define __COMMON_TYPES_H

#include <stdint.h>
#include <stdbool.h>

typedef struct {
    uint8_t txBfr[32], rxBfr[32];
    uint8_t txLen, rxLen;
    uint16_t counter;
    bool isMaster;
    uint8_t addr;
} data_t;

#endif