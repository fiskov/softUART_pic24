#ifndef __CMD_H
#define __CMD_H

#include "common.h"

#define CMD_LENGTH        4
#define CMD_RESP_LENGTH   8

bool cmdParse(uint8_t rxBfr[], uint8_t txBfr[]);

#endif