/** \file cmd.c
 */
#include "cmd.h"
#include "crc.h"

static const uint8_t endl[] = "\r\n";
#define CS_SIZE 2
#define TEST_ANSWER_SIZE 16

/// Return HEX symbol for integer
static char hex2char(uint8_t number){
    char hex[0xF] = "0123456789ABCDEF";
    return hex[number & 0xF];
}

/// Calculate LRC_CheckSum and insert in buffer
static uint16_t cmdInsertLRC(uint8_t bfr[], uint8_t pos)
{    
    uint8_t cs = getLRC((char*)bfr, pos);
    bfr[pos] = hex2char(cs >> 4);
    bfr[pos+1] = hex2char(cs & 0xF);
    return pos+2;
}
/// check LRC_CheckSum in buffer
static bool cmdCheckLRC(uint8_t bfr[], uint8_t pos)
{    
    uint8_t cs = getLRC((char*)bfr, pos);
    return (bfr[pos] == hex2char(cs >> 4) &&
        bfr[pos+1] == hex2char(cs & 0xF));
}

bool cmdParse(uint8_t addr, uint8_t rxBfr[], uint8_t rxLength, uint8_t txBfr[], uint8_t *txLength)
{
    bool result = false;
    
    if (rxLength > CS_SIZE + sizeof(endl))
    {        
        if ( cmdCheckLRC( rxBfr, rxLength - CS_SIZE - sizeof(endl)) )
        {
            if (rxBfr[0] == addr) {
                
                uint8_t pos = 0;
                while (pos < TEST_ANSWER_SIZE)
                    txBfr[pos++] = addr;
                
                pos = cmdInsertLRC(txBfr, pos);
                memcpy(&txBfr[pos], endl, sizeof(endl)); 
                *txLength = pos + sizeof(endl);
                result = true;
            }
        }
    }
    
    return result;
}

void cmdMakeTest(uint8_t bfr[], uint8_t addr, uint8_t *length)
{
    uint8_t pos = 0;
    const char data = "hello";
    
    bfr[pos++] = addr;
    memcpy((char*)&bfr[pos], data, sizeof(data));
    pos = cmdInsertLRC(bfr, sizeof(data)+pos);
    memcpy((char*)&bfr[pos], endl, sizeof(endl));
    
    *length = pos + sizeof(endl);
}

