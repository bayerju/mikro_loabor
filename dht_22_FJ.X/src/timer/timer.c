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

void enable_T3_interrupts(void) {
    T3CONbits.TON = 0; // Disable Timer
    IEC0bits.T3IE = 1; // Enable Timer3 interrupt
    T3CONbits.TON = 1; // Start Timer
}

void disable_T3_interrupts(void) {
    IEC0bits.T3IE = 0; // Disable Timer3 interrupt
}

void enable_gate(void) {
    T3CONbits.TGATE = 1; // Enable Gated Timer mode
    TMR3 = 0x00; // Clear timer register
    T3CONbits.TON = 1; // Start Timer
}

void disable_gate(void) {
    T3CONbits.TGATE = 0; // Disable Gated Timer mode
}
