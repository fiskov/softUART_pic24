#ifndef __DRV_UART_H
#define __DRV_UART_H

#include "stdint.h"

typedef struct {
    uint8_t *tx, *rx;
    uint16_t txPos, txLen;
    uint16_t rxSize, *rxLen_p;
    uint8_t *rxEnd_flag, rxEnd_flagEn;
    uint8_t rxEndSymbol;
    uint8_t uartN;
} uart_t;

/* //poll mode
void uart_init();

*/

// interrupt mode
void uartInit_it(uint8_t uartN, uint32_t speed, uint8_t *rxBfr, uint16_t rxSize, uint16_t *rxLen);
void uartInit_flag(uint8_t uartN,  uint8_t *rxEnd_flag, uint8_t rxEndSymbol);
void uartSend(uint8_t uartN, uint8_t *bfr, uint16_t length);


#endif	/* __DRV_UART_H */