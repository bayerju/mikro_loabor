#include <stdio.h>
#include <stdlib.h>
#include "p33FJ128GP802.h"
#include "global_definitions.h"

#define T3_Period 19 // 1us with 4MHz: 4MHz -> Befehlstakt: 2Mhz -> 1/2Mhz = 0.5us -> 10us/0.5us = 20

void T3_setup(void) {
    T3CONbits.TON = 0; // Disable Timer
    T3CONbits.TCS = 0; // Select internal instruction cycle clock
    T3CONbits.TGATE = 0; // Disable Gated Timer mode
    T3CONbits.TCKPS = 0b00; // Select 1:1 Prescaler
    TMR3 = 0x00; // Clear timer register
    PR3 = T3_Period; // Load the period value
    IPC2bits.T3IP = 0x01; // Set Timer3 Interrupt Priority Level
    IFS0bits.T3IF = 0; // Clear Timer3 Interrupt Flag
    IEC0bits.T3IE = 1; // Enable Timer3 interrupt
    T3CONbits.TON = 1; // Start Timer
}

void __attribute__((__interrupt__, no_auto_psv)) _T3Interrupt(void){
    /* Interrupt Service Routine code goes here */
    static short int counter = 0;
    static short int recievedBits = 0;
    if (isWakingSensorFlag == 1 && isMessuringSensorFlag == 0) {
        data[counter] = PORTBbits.RB15;
        counter++;
    }
    if (counter >= MAX_DATA_ARRAY_LENGTH && isWakingSensorFlag == 1) {
        evalWakingData(data, MAX_DATA_ARRAY_LENGTH);
        counter = 0;
    }
    if (isMessuringSensorFlag == 1) {
        bitEvalData[counter] = PORTBbits.RB15;
        short int currentBit = evalBit(bitEvalData);
        if (currentBit != -1) {
            measurementBits[counter] = currentBit;
            counter = 0;
            for (int i = 0; i < sizeOf(bitEvalData); i++) {
                bitEvalData[i] = -1;
            }
            recievedBits++;
        }
        counter++;
    }
    if (recievedBits >= 40) {
        counter == 0;
        T3CONbits.TON = 0; // Disable Timer
        IEC0bits.T3IE = 0; // Disable Timer3 interrupt

    }
    
    IFS0bits.T3IF = 0;
}