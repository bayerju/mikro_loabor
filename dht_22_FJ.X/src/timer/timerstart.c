/**
 * @file timerstart.c
 * @author Group DHT 22
 * @brief Initializes the start timer
 * @version 0.1
 * @date 2023-01-09
 * 
 * @copyright Copyright (c) 2023
 * 
 */


#include "timer.h"

#define T1_Periode 0.1*FCY/256-1    //  should trigger the asulreading of the sensor every 2 seconds
                                    // 2s/(1/FCY) = 2*FCY

// TODO: Screen shot 5 
void T1_setup(void)                 // from moodle
    {
    T1CONbits.TON = 0;              // diesable Timer1
    T1CONbits.TCS = 0;              // select internal clock FCY
    T1CONbits.TGATE = 0;            // disable Gated Timer mode
    T1CONbits.TCKPS = 0b11;         // select 1:256 Prescaler
    TMR1 = 0x00;                    // clear timer register
    PR1 = T1_Periode;               // load the period value 1kHz t_PR1

    IPC0bits.T1IP = 0x01;           // set Timer1 Interrupt Priority Level
    IFS0bits.T1IF = 0;              // clear Timer1 Interrupt Flag
    IEC0bits.T1IE = 1;              // enable Timer1 interrupt
    T1CONbits.TON = 1;              // start Timer1
    }
    
void __attribute__((__interrupt__, no_auto_psv)) _T1Interrupt(void){
    static int counter = 0;     // prescaler is not sufficient for 2 seconds, so we need a counter to
                                // count every 0.1 seconds and only run the function every 20th time.
    if (counter >= 20) {
        counter = 0;
        readData(data);
    }
    counter++;
    IFS0bits.T1IF = 0; // Interrupt Flag zurücksetzen
}
