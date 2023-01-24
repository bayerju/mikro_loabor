/**
 * @file timer.c
 * @author Group DHT22
 * @brief Initializing the timer
 * @version 0.1
 * @date 2023-01-09
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "dht.h"
#include "timer.h"
// TODO: Screen shot 6
#define T3_Period 65000         // 1us with 4MHz: 4MHz
                                // Befehlstakt: 2Mhz -> 1/2Mhz = 0.5us -> 10us/0.5us = 20
void T3_setup(void) {
    T3CONbits.TON = 0;          // Disable Timer
    T3CONbits.TCS = 0;          // Select internal instruction cycle clock
    T3CONbits.TGATE = 0;        // Disable Gated Timer mode
    T3CONbits.TCKPS = 0b00;     // Select 1:1 Prescaler
    TMR3 = 0x00;                // Clear timer register
    PR3 = T3_Period;            // Load the period value
    IPC2bits.T3IP = 0x01;       // Set Timer3 Interrupt Priority Level // TODO: can we have two same prioritiylevels?
    IFS0bits.T3IF = 0;          // Clear Timer3 Interrupt Flag
    IEC0bits.T3IE = 0;          // Disable Timer3 interrupt
    T3CONbits.TON = 1;          // Start Timer
}

void T3_setup_gated(void) {
    T3CONbits.TON = 0;          // Disable Timer
    T3CONbits.TCS = 0;          // Select internal instruction cycle clock
    T3CONbits.TGATE = 1;        // Enable Gated Timer mode
    T3CONbits.TCKPS = 0b00;     // Select 1:1 Prescaler
    TMR3 = 0x00;                // Clear timer register
    PR3 = T3_Period;
    __builtin_write_OSCCONL(OSCCON & 0xbf);
    RPINR3bits.T3CKR = 0b00101;
    __builtin_write_OSCCONL(OSCCON | 0x40);
    int testi = RPINR3bits.T3CKR;  
    IPC2bits.T3IP = 0x01;       // Set Timer3 Interrupt Priority Level // TODO: can we have two same prioritiylevels?
    IFS0bits.T3IF = 0;          // Clear Timer3 Interrupt Flag
    int test = PORTBbits.RB5;
    int test1 = RPINR3bits.T3CKR;
    int test2 =  TRISBbits.TRISB5;
    IEC0bits.T3IE = 1;          // Enable Timer3 interrupt
    T3CONbits.TON = 1;          // Start Timer
}

void __attribute__((__interrupt__, no_auto_psv)) _T3Interrupt(void){
// q: why does this interrupt trigger every 40 to 50 cycles?
// a:
    static int currentBit = 0;
    int test = currentBit;
    if (currentBit >= 40) {
        currentBit = 0;
        evaluateBitData(data, tempString, humString);
        T3_setup();
    }
    
    if (TMR3 > 2000 && TMR3 < 4000) {
    data[currentBit] = TMR3;
    TMR3 = 0;
    currentBit++;
    } else if (TMR3 > 600 && TMR3 < 2000) {
    data[currentBit] = TMR3;
    TMR3 = 0;
    currentBit++;
    }

    IFS0bits.T1IF = 0; // Interrupt Flag zurücksetzen
}
