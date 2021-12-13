#ifndef __SOFT_UART_H
#define __SOFT_UART_H

#include "common.h"

#define SOFT_UART_SPEED     19200 // bit/s
#define SOFT_UART_RX_TMR 5 //timeout after rx

#define SOFT_UART_TIMER_NO        3 // timer3
#define SOFT_UART_TIMER_PERIOD	JOIN(PR, SOFT_UART_TIMER_NO)

#define SOFT_UART_TIMER_INT       JOIN3( _T, SOFT_UART_TIMER_NO, IE)
#define SOFT_UART_TIMER_INT_PROC  JOIN3( _T, SOFT_UART_TIMER_NO, Interrupt)
#define SOFT_UART_TIMER_ON        JOIN3(  T, SOFT_UART_TIMER_NO, CONbits.TON)
#define SOFT_UART_TIMER_INT_FLAG  JOIN3( _T, SOFT_UART_TIMER_NO, IF)
#define SOFT_UART_TIMER_TMR        JOIN(TMR, SOFT_UART_TIMER_NO)

#define SOFT_UART_PIN_TX    _LATA3
#define SOFT_UART_PIN_RX    _RA3
#define SOFT_UART_PIN_TRIS  _TRISA3
#define SOFT_UART_PIN_CN    _CN29IE

typedef struct {
  uint8_t *rxBfr;
  uint8_t *txBfr;
  bool isMaster;
  uint32_t speed;
} softUART_config_t;

// init softUART: timer, CN-int, 
void softUART_init(softUART_config_t * p_cfg);

// transmite and receive
uint8_t softUART_trncv(uint16_t * timer1ms);

void softUART_send(uint8_t bfr[], uint8_t length);

#endif
