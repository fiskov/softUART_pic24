/** \file cmd.c
 */
#include "cmd.h"
#include "crc.h"
#include "textfunctions.h"
#include "common_types.h"
#include "string.h"

#define CS_SIZE 2
#define TEST_ANSWER_SIZE 8

static const uint8_t endl[] = "\r\n";

/// Calculate LRC_CheckSum and insert in buffer
static uint16_t cmdInsertLRC(uint8_t bfr[], uint8_t pos)
{
    uint8_t cs = getLRC(bfr, pos);
    bfr[pos] = hex2char(cs >> 4);
    bfr[pos+1] = hex2char(cs & 0xF);
    return pos+2;
}
/// check LRC_CheckSum in buffer
static bool cmdCheckLRC(uint8_t bfr[], uint8_t pos)
{
    uint8_t cs = getLRC(bfr, pos);
    return (bfr[pos] == hex2char(cs >> 4) &&
        bfr[pos+1] == hex2char(cs & 0xF));
}

bool cmdParse(data_t * data)
{
    bool result = false;
    
    if (data->rxLen > CS_SIZE + sizeof(endl))
    {        
        if ( cmdCheckLRC( data->rxBfr, data->rxLen - CS_SIZE - sizeof(endl)) )
        {
            if (data->rxBfr[0] == data->addr) {
                uint8_t pos = 0;
                data->txBfr[pos++] = data->addr;
                data->txBfr[pos++] = ',';
                myIntToStr((char*)&data->txBfr[pos], data->counter, TEST_ANSWER_SIZE-1, true);
                pos += TEST_ANSWER_SIZE-1;
                data->txBfr[pos++] = ',';
                
                pos = cmdInsertLRC(data->txBfr, pos);
                memcpy(&data->txBfr[pos], endl, sizeof(endl)); 
                data->txLen = pos + sizeof(endl);
                result = true;
            }
        }
    }
    
    return result;
}

void cmdMakeTest(uint8_t bfr[], uint8_t addr, uint8_t *length)
{
    uint8_t pos = 0;
    const char data[] = ",hello,";
    
    bfr[pos++] = addr;
    memcpy((char*)&bfr[pos], data, sizeof(data));
    pos = cmdInsertLRC(bfr, sizeof(data)+pos);
    memcpy((char*)&bfr[pos], endl, sizeof(endl));
    
    *length = pos + sizeof(endl);
}

