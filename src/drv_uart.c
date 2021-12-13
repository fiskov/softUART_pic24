#include "drv_uart.h"
#include "common.h"
#include "board.h"
#include <xc.h>

uart_t uart1 = {.uartN = 1};
uart_t uart2 = {.uartN = 2};


void uartInit_it(uint8_t uartN, uint32_t speed, uint8_t *rxBfr, uint16_t rxSize, uint16_t *rxLen)
{
    if (uartN == 1) {
        _UART1_TX_TRIS = 0; 
        _UART1_RX_TRIS = 1; 
        _U1RXIE = 1;	//rx interrupt
        _U1TXIE = 1;	//tx interrupt
        U1BRG = FCY/speed/16 - 1;
        U1MODEbits.UARTEN = 1;
        U1STAbits.UTXEN = 1;              
    } 
    
    uart_t *uart = (uartN == 1 ? &uart1 : &uart2);
    uart->rx = rxBfr;
    uart->rxSize = rxSize;
    uart->rxLen_p = rxLen;
}

void uartInit_flag(uint8_t uartN,  uint8_t *rxEnd_flag, uint8_t rxEndSymbol)
{
    uart_t *uart = (uartN == 1 ? &uart1 : &uart2);
    
    uart->rxEnd_flag = rxEnd_flag;
    uart->rxEndSymbol = rxEndSymbol;
    uart->rxEnd_flagEn = 1;
}
void uartSend(uint8_t uartN, uint8_t *bfr, uint16_t length)
{
    
	if (uartN == 1) {
		uart1.tx = bfr;
		uart1.txLen = length;
		uart1.txPos = 1;
		U1TXREG = *bfr;  
    } else {
		uart2.tx = bfr;
		uart2.txLen = length;
		uart2.txPos = 1;
		U2TXREG = *bfr;
    }
}


void _ISR _NOPSV _U1TXInterrupt(void) {
    _U1TXIF = 0;
    if (uart1.txPos < uart1.txLen) 
      U1TXREG = uart1.tx[uart1.txPos++]; 
}

void _ISR _NOPSV _U2TXInterrupt(void) {
    _U2TXIF = 0;
    if (uart2.txPos < uart2.txLen) 
      U2TXREG = uart2.tx[uart2.txPos++];    
}

void _ISR _NOPSV _U1RXInterrupt(void) { 
	_U1RXIF = 0; 
	
	char c = U1RXREG;	
    uart1.rx[*(uart1.rxLen_p)] = c;
	if (*(uart1.rxLen_p) < uart1.rxSize-1) 
			(*(uart1.rxLen_p))++;
	
   	if (uart1.rxEnd_flagEn && c == uart1.rxEndSymbol) {
        *(uart1.rxEnd_flag) = 1;
        *(uart1.rxLen_p) = 0; 
    }	
}

void _ISR _NOPSV _U2RXInterrupt(void) { 
	_U2RXIF = 0;
			
	char c = U2RXREG;	
    uart2.rx[*(uart2.rxLen_p)] = c;
	if (*(uart2.rxLen_p) < uart2.rxSize-1) 
		(*(uart2.rxLen_p))++;
	
   	if (uart2.rxEnd_flagEn && c == uart2.rxEndSymbol) {
        *(uart2.rxEnd_flag) = 1;
        *(uart2.rxLen_p) = 0; 
    }
}
