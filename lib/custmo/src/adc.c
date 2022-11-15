#include "p33FJ128GP802.h"

#define N_12 1
#define N_10 0
#define ADC_PRIO 2
#define ON 1
#define OFF 0
#define BUFFER_LENGTH 10

unsigned int adc_buffer[BUFFER_LENGTH];
unsigned char adc_flag = 0;

void adc_init(void) { 
    AD1CON1bits.ADON = 0; 
    AD1CON1bits.AD12B = N_10;

    AD1CON1bits.CHOSA = 0;
    AD1CON1bits.CHONA = 0;

    AD1PCFGLbits.PCFG0 = 0;
    TRISAbits.TRISA0 = 1;
    AD1CON2bits.VCFG = 0b000;
    AD1CON3bits.ADRC = 1;
    AD1CON1bits.SSRC = 0b010;
    AD1CON3bits.SAMC = 0;

    AD1CON1bits.FORM = 0b00;
    AD1CON1bits.ASAM = 1;
    
    AD1CON1bits.ADSIDL = 0;

    IPC3bits.AD1IP = 1;
    IEC0bits.AD1IE = 0;
}

void __attribute__((__interrupt__, no_auto_psv)) _ADC1Interrupt(void) {
    static unsigned char i = 0;
    // IFS0bits.AD1IF = 0;
    adc_buffer[i] = ADC1BUF0;
    i++;
    if (i == BUFFER_LENGTH) {
        i = 0;
    }
    adc_flag = 1;
    IFS0bits.AD1IF = 0;
}

void adc_irq_activation(unsigned char state) {
    if (state == ON) {
        IFS0bits.AD1IF = 0;
        IEC0bits.AD1IE = 1;
    } else {
        IEC0bits.AD1IE = 0;
    }
}

void adc_start(void) {
    adc_irq_activation(ON);
    AD1CON1bits.ADON = 1;
}

void adc_stop(void) {
    adc_irq_activation(OFF);
    AD1CON1bits.ADON = 0;
}

unsigned int adc_avg(void) {
    unsigned int sum = 0;
    unsigned char i = 0;
    for (i = 0; i < BUFFER_LENGTH; i++) {
        sum += adc_buffer[i];
    }
    return ((unsigned int) (sum / BUFFER_LENGTH));
}