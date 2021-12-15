#include "cmd.h"
#include "crc.h"

bool cmdParse(uint8_t rxBfr[], uint8_t txBfr[], uint8_t addr)
{
  bool res = false;
  //if (rxBfr[CMD_LENGTH-1] == getCrc8forTxString(rxBfr, CMD_LENGTH-1)) {
    //uint8_t cmd = rxBfr[0];    
    //res = true;
  //}
  
  if (rxBfr[0] == addr) {
    txBfr[0] = addr;
    txBfr[1] = addr;
    txBfr[2] = addr;
    txBfr[3] = addr;
    txBfr[4] = addr;
    txBfr[5] = '\r';  
    res = true;
  }
  
  memset(rxBfr, 0, CMD_LENGTH);
  return res;
}

