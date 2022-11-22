/* 
 * File:   ADC.h
 * Author: MarvinK
 *
 * Created on 11. November 2022, 17:36
 */

#ifndef _ADC_H_
#define	_ADC_H_

extern void adc_init(void);
extern void adc_start(void);
extern void adc_stop(void);

extern unsigned char adc_flag;  //ADC ready flag
#endif	/* _init_device_H_ */

