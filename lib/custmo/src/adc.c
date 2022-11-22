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
    AD1CON1bits.ADON = 0; // disable ADC
    AD1CON1bits.AD12B = N_10; // 10 bit ADC

    AD1CON1bits.CHOSA = 0; // select AN0 as input
    AD1CON1bits.CHONA = 0; // select AN0 as input
//    TODO: why not chanel selection?
    // AD1CON2.CHPS = 0; // select CH0
    // AD1CHS0.CH0SA = 9; // select AN9 as input

    AD1PCFGLbits.PCFG0 = 0; // AN0 as analog input
    TRISAbits.TRISA0 = 1; // AN0 as input
    AD1CON2bits.VCFG = 0b000; // AVdd and AVss as reference voltage
    AD1CON3bits.ADRC = 1; // use internal RC clock
    AD1CON1bits.SSRC = 0b010; // use internal counter (Timer interrupt Trigger(Timer 3))
    AD1CON3bits.SAMC = 0; // sample time = 0 Tad

    AD1CON1bits.FORM = 0b00; // integer output
    AD1CON1bits.ASAM = 1; // auto sampling
    
    AD1CON1bits.ADSIDL = 0; // continue operation in idle mode

    IPC3bits.AD1IP = 1; // set ADC interrupt priority
    IEC0bits.AD1IE = 0; // disable ADC interrupt
}

void __attribute__((__interrupt__, no_auto_psv)) _ADC1Interrupt(void) {
    static unsigned char i = 0;
    // IFS0bits.AD1IF = 0;
    adc_buffer[i] = ADC1BUF0; // read the buffer
    i++;
    if (i == BUFFER_LENGTH) {
        i = 0;
    }
    adc_flag = 1; // set flag
    IFS0bits.AD1IF = 0; // Clear the ADC interrupt flag bit
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