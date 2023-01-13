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

#include "../config/global_definitions.h"
#include "timer.h"

// #define T1_Periode_Ground 1999 // For starting the sensor min. 1ms grounding
#define T1_Periode 0.1*FCY/256-1 // soll alle 2 sekunden das asulesen des sensors auslösen
// 1/FCY wie lange brauche ich für einen schritt
// wie viele schritte brauche ich für 2 sekunden?
// 2s/(1/FCY) = 2*FCY

    
void T1_setup(void) // Aus Moodle
    {
    T1CONbits.TON = 0;      // Disable Timer
    T1CONbits.TCS = 0;      // Select internal clock FCY
    T1CONbits.TGATE = 0;    // Disable Gated Timer mode
    T1CONbits.TCKPS = 0b11; // Select 1:256 Prescaler
    TMR1 = 0x00;            // Clear timer register
    PR1 = T1_Periode;       // Für Rechteck 1kHz t_PR1
    // PR1 = 499;           // F?r Rechteck 2kHz

    IPC0bits.T1IP = 0x01;   // Set Timer1 Interrupt Priority Level
    IFS0bits.T1IF = 0;      // Clear Timer1 Interrupt Flag
    IEC0bits.T1IE = 1;      // Enable Timer1 interrupt
    T1CONbits.TON = 1; // Einschalten des Timers 
    }
    
void __attribute__((__interrupt__, no_auto_psv)) _T1Interrupt(void){
    static int counter = 0; // prescaler is not sufficient for 2 seconds, so we need a counter to count every 0.1 seconds and only run the function every 20th time.
    if (counter >= 20) {
        counter = 0;
        dataValues = readData(data, tempString, humString);
    }
    counter++;
    IFS0bits.T1IF = 0; // Interrupt Flag zurücksetzen
}
