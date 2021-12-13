#include "cmd.h"
#include "crc.h"

bool cmdParse(uint8_t rxBfr[], uint8_t txBfr[])
{
  bool res = false;
  if (rxBfr[CMD_LENGTH-1] == getCrc8forTxString(rxBfr, CMD_LENGTH-1))
  {
    uint8_t cmd = rxBfr[0];
    memset(txBfr, 0xff-cmd, CMD_RESP_LENGTH);
    res = true;
  }
  
  memset(rxBfr, 0, CMD_LENGTH);
  return res;
}

