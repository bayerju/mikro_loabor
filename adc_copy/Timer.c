/*
 * File:   Timer.c
 * Author: MarvinK
 *
 * Created on 11. November 2022, 17:39
 */


#include "xc.h"
#include "init_device.h"

#define T3_PERIOD 4999  //Timer 3 Periode
#define ON 1
#define OFF 0

long adcValue;

void T3_irq_activation(unsigned char onoff);

void __attribute__((__interrupt__, no_auto_psv)) _T3Interrupt(void){
    LATBbits.LATB14 = LATBbits.LATB14 ^ 1;
    adcValue = ADC1BUF0;
    IFS0bits.T3IF = 0;
}

void T3_init(void){
    T3CONbits.TON = 0;      //disable Timer
    T3CONbits.TCS = 0;      //Select Internal clock FCY
    T3CONbits.TGATE = 0;    //Disable gated Timer mode
    T3CONbits.TCKPS = 0b00; //Select 1:1 Prescaler
    TMR3 = 0x00;            // Clear Timer Register
    PR3 = T3_PERIOD;

    IPC2bits.T3IP = 0x03;      //Set Timer 3 Interrupt Priority Level
    IFS0bits.T3IF = 0;          //Clear Timer 3 Interrupt Flag
    IEC0bits.T3IE = 0;          //Enable Timer 3 Interrupt
}

void T3_irq_activation(unsigned char onoff){
// onoff = 1 --> enable; 0 --> disable
    if(onoff == ON){
        IFS0bits.T3IF = 0; //Clear Timer 3 Interrupt Flag
        IEC0bits.T3IE = 1; //Enable Timer 3 Interrupt
    }
    else{
        IEC0bits.T3IE = 0; //Disable Timer 3 Interrupt
    }
}

void T3_start(void)
{
    T3_irq_activation(ON);
    T3CONbits.TON = 1; //Start timer   
}

void T3_stop(void)
{
    T3_irq_activation(OFF);
    T3CONbits.TON = 0; //Stop timer   
}
