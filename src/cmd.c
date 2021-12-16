#include "cmd.h"
#include "crc.h"

bool cmdParse(uint8_t addr, uint8_t rxBfr[], uint8_t len, uint8_t txBfr[], uint8_t *len_out)
{
  //if (rxBfr[CMD_LENGTH-1] == getCrc8forTxString(rxBfr, CMD_LENGTH-1)) {
    //uint8_t cmd = rxBfr[0];    
    //res = true;
  //}

    if (rxBfr[0] == addr) {
        int i;
        
        for (i=0; i<16; i++)
            txBfr[i] = addr;
        
        txBfr[16] = '\r';  
        *len_out = 17;
        return true;
    }

    return false;
}

