/** \file SoftUART_driver header.
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


#define SOFT_UART_PIN_1WIRE_NO        A3  // pin RA3 - single-wire-mode
#define SOFT_UART_PIN_1WIRE_TX    JOIN(_LAT, SOFT_UART_PIN_1WIRE_NO)
#define SOFT_UART_PIN_1WIRE_RX    JOIN(_R, SOFT_UART_PIN_1WIRE_NO)
#define SOFT_UART_PIN_1WIRE_TRIS  JOIN(_TRIS, SOFT_UART_PIN_1WIRE_NO)
#define SOFT_UART_PIN_1WIRE_CN    _CN29IE
#define SOFT_UART_PIN_1WIRE_CNPU    _CN29PUE

#define SOFT_UART_PIN_2WIRE_TX_NO        A2  // pin RA2 - 2-wire-mode
#define SOFT_UART_PIN_2WIRE_TX    JOIN(_LAT,SOFT_UART_PIN_2WIRE_TX_NO)
#define SOFT_UART_PIN_2WIRE_TRIS_TX  JOIN(_TRIS, SOFT_UART_PIN_2WIRE_TX_NO)
#define SOFT_UART_PIN_2WIRE_TX_CNPU    _CN2PUE

#define SOFT_UART_PIN_2WIRE_RX_NO        A1  // pin RA1 - 2wire-mode
#define SOFT_UART_PIN_2WIRE_RX    JOIN(_R, SOFT_UART_PIN_2WIRE_RX_NO)
#define SOFT_UART_PIN_2WIRE_TRIS_RX  JOIN(_TRIS, SOFT_UART_PIN_2WIRE_RX_NO)
#define SOFT_UART_PIN_2WIRE_CN    _CN3IE
#define SOFT_UART_PIN_2WIRE_CNPU    _CN3PUE

/** Wire-mode */
typedef enum {
    SOFT_UART_MODE_1WIRE = 0,
    SOFT_UART_MODE_2WIRE
} softUART_mode_t;

/**
 * Init softUART driver. Should be execute softUART_read() function every 1ms
 * \param baud_rate
 * \param rx_timeout_ms
 */
void softUART_init(uint32_t baud_rate, uint16_t rx_timeout_ms, softUART_mode_t mode_);

/** 
 * Receive data
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

/**
 * Switch mode of softUART
 */
void softUART_switch(softUART_mode_t mode);

#endif
