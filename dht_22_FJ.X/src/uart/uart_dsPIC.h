/**
 * @file uart_dsPIC.h
 * @author Group DHT22
 * @source Jan Haffmueller
 * @brief Providing the UART functions for dsPIC
 * @version 0.1
 * @date 2023-01-09
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef _UART_DSPIC_H_
   #define _UART_DSPIC_H_

extern void CommConfig(void);
extern void CommEnable(void);
extern void CommDisable(void);
extern unsigned char CommTxFull(void);
extern void CommRxFlush(void);
extern void CommRxIntEn(void);
extern void CommRxIntDis(void);
extern void CommTxIntEn(void);
extern void CommTxIntDis(void);
extern void CommTxIntSet(void);

/*
extern void __attribute__ ((interrupt, no_auto_psv)) _U1TXInterrupt(void);
extern void __attribute__ ((interrupt, no_auto_psv)) _U1RXInterrupt(void);
extern unsigned int PulsWidth;*/
#endif // _init_device_H_
