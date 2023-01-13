/**
 * @file uart.h
 * @author Group DHT22
 * @source Jan Haffmueller
 * @brief Providing the UART functions
 * @version 0.1
 * @date 2023-01-09
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef _UART_H_
#define _UART_H_

#include "global_definitions.h"

extern void CommInit(void);
extern void CommPutRxChar(unsigned char data);
extern unsigned char CommGetChar(void);
extern unsigned char CommIsEmpty(void);
extern unsigned char CommGetTxChar(void);
extern void CommPutChar(unsigned char data);
extern void CommPutString(char *str_data);
extern void ChangeValue(int iState, float *a_borderRedHum, float *a_borderYellowHum);

extern void __attribute__ ((interrupt, no_auto_psv)) _U1TXInterrupt(void);
extern void __attribute__ ((interrupt, no_auto_psv)) _U1RXInterrupt(void);
extern unsigned int PulsWidth;
#endif // _init_device_H_
