#ifndef _ADC_H
#define _ADC_H
extern void adc_init(void);
extern void adc_start(void);
extern void adc_stop(void);
extern unsigned int adc_avg(void);

extern unsigned char adc_flag;
#endif
