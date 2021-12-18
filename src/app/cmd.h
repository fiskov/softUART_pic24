/// \file cmd.h
#ifndef __CMD_H
#define __CMD_H

#include "common_types.h"

#define CMD_LENGTH        3
#define CMD_RESP_LENGTH   6

/**
 * Parser for input command
 * @param data - common data-struct
 * @return True if command is correct and address of this MCU
 */
bool cmdParse(data_t * data);

/**
 * Make test data for asking slaves
 * @param bfr
 * @param addr - address of slave MCU
 * @param length[out] - result length
 */
void cmdMakeTest(uint8_t bfr[], uint8_t addr, uint8_t *length);

#endif