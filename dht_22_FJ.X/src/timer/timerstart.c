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

#define T1_Periode_Ground 1999  // for starting the sensor min. 1ms grounding

    
void Setup_T1(void)             // from moodle
    {
    T1CONbits.TON = 0;          // diesable Timer1
    T1CONbits.TCS = 0;          // select internal clock FCY
    T1CONbits.TGATE = 0;        // disable Gated Timer mode
    T1CONbits.TCKPS = 0b00;     // select 1:1 Prescaler
    TMR1 = 0x00;                // clear timer register
    PR1 = T1_Periode_Ground;    // load the period value

    IPC0bits.T1IP = 0x01;       // set Timer1 Interrupt Priority Level
    IFS0bits.T1IF = 0;          // clear Timer1 Interrupt Flag
    IEC0bits.T1IE = 0;          // disable Timer1 interrupt
    T1CONbits.TON = 1;          // start Timer 
    }
    
    // Interrut sorgt f?r das Rechtecksignal
    /*void __attribute__((__interrupt__,  no_auto_psv)) _T1Interrupt(void){
        
        static short int counter = 0;
        if (counter == 0){
        TRISBbits.TRISB5 = 0; // output
        PORTBbits.RB5 = 0;
        }
        if (counter >= 20){
        PORTBbits.RB5 = 1;
        TRISBbits.TRISB5 = 1; // input
        isWakingSensorFlag = 1;
        T1CONbits.TON = 0;
        IEC0bits.T1IE = 0;
        T3_setup();
        }
        counter ++;
        
        
        IFS0bits.T1IF = 0;
    }*/
