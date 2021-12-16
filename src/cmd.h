#ifndef __CMD_H
#define __CMD_H

#include "common.h"

#define CMD_LENGTH        3
#define CMD_RESP_LENGTH   6

bool cmdParse(uint8_t addr, uint8_t rxBfr[], uint8_t len, uint8_t txBfr[], uint8_t *len_out);

#endif