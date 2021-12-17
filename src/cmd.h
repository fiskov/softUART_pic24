/// \file cmd.h
#ifndef __CMD_H
#define __CMD_H

#include "common.h"

#define CMD_LENGTH        3
#define CMD_RESP_LENGTH   6

/**
 * Parser for input command
 * @param addr - address this MCU
 * @param rxBfr - buffer for analyze
 * @param rxLength - length of cmd buffer
 * @param txBfr - buffer for answer
 * @param txLength - length of answer buffer
 * @return True if command is correct and address of this MCU
 */
bool cmdParse(uint8_t addr, uint8_t rxBfr[], uint8_t len, uint8_t txBfr[], uint8_t *len_out);

/**
 * Make test data for asking slaves
 * @param bfr
 * @param addr - address of slave MCU
 * @param length[out] - result length
 */
void cmdMakeTest(uint8_t bfr[], uint8_t addr, uint8_t *length);

#endif