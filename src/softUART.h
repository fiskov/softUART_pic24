/*!
 * 
 * \file SoftUART_driver header.
 */
#ifndef __SOFT_UART_H
#define __SOFT_UART_H

#include "common.h"

#define SOFT_UART_TIMER_NO        3 // timer3
#define SOFT_UART_TIMER_PERIOD    JOIN(PR, SOFT_UART_TIMER_NO)
#define SOFT_UART_TIMER_INT       JOIN3( _T, SOFT_UART_TIMER_NO, IE)
#define SOFT_UART_TIMER_INT_PROC  JOIN3( _T, SOFT_UART_TIMER_NO, Interrupt)
#define SOFT_UART_TIMER_ON        JOIN3(  T, SOFT_UART_TIMER_NO, CONbits.TON)
#define SOFT_UART_TIMER_INT_FLAG  JOIN3( _T, SOFT_UART_TIMER_NO, IF)
#define SOFT_UART_TIMER_TMR        JOIN(TMR, SOFT_UART_TIMER_NO)

#define SOFT_UART_PIN_NO        A3  // pin RA3
#define SOFT_UART_PIN_TX    JOIN(_LAT, SOFT_UART_PIN_NO)
#define SOFT_UART_PIN_RX    JOIN(_R, SOFT_UART_PIN_NO)
#define SOFT_UART_PIN_TRIS  JOIN(_TRIS, SOFT_UART_PIN_NO)
#define SOFT_UART_PIN_CN    _CN29IE

/**
 * Init softUART driver. Should be execute softUART_read() function every 1ms
 * \param baud_rate
 * \param rx_timeout_ms
 */
void softUART_init(uint32_t baud_rate, uint16_t rx_timeout_ms);

/** 
 * receive data
 * \param[out] rxBfr  rx-buffer
 * \param[out] length Byte count if rx-buffer
 *
 * \return True if length > 0
 */
bool softUART_read(uint8_t rxBfr[], uint8_t * length);

/**
 * Transmite data
 * @param txBfr tx-buffer
 * @param length byte for transfer
 */
void softUART_send(uint8_t txBfr[], uint8_t length);

#endif
