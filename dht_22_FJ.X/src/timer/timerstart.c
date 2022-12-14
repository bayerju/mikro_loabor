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

#include <stdio.h>
#include <stdlib.h>
#include "p33FJ128GP802.h"
#include "global_definitions.h"
#include "timer.h"

#define T1_Periode_Ground 1999 // For starting the sensor min. 1ms grounding

    
void Setup_T1(void) // Aus Moodle
    {
    T1CONbits.TON = 0;      // Disable Timer
    T1CONbits.TCS = 0;      // Select internal clock FCY
    T1CONbits.TGATE = 0;    // Disable Gated Timer mode
    T1CONbits.TCKPS = 0b00; // Select 1:1 Prescaler
    TMR1 = 0x00;            // Clear timer register
    PR1 = T1_Periode_Ground;              // F?r Rechteck 1kHz
    // PR1 = 499;           // F?r Rechteck 2kHz

    IPC0bits.T1IP = 0x01;   // Set Timer1 Interrupt Priority Level
    IFS0bits.T1IF = 0;      // Clear Timer1 Interrupt Flag
    IEC0bits.T1IE = 0;      // Disable Timer1 interrupt
    T1CONbits.TON = 1; // Einschalten des Timers 
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
