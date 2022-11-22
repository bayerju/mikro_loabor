#include <stdio.h>
#include <stdlib.h>
#include "p33FJ128GP802.h"

// define constants
#define T3_PERIOD 499
#define ON 1
#define OFF 0

void T3_init(void) {
    T3CONbits.TON = 0;
    T3CONbits.TCS = 0;

    T3CONbits.TGATE = 0;
    T3CONbits.TCKPS = 0b00;
    TMR3 = 0x00;

    PR3 = T3_PERIOD;

    IPC2bits.T3IP = 0x03;
    IFS0bits.T3IF = 0;
    IEC0bits.T3IE = 1;
}

// void T3_irq_activation(unsigned char state) {
//     if (state == ON) {
//         IFS0bits.T3IF = 0;
//         IEC0bits.T3IE = 1;
//     } else {
//         IEC0bits.T3IE = 0;
//     }
// }

void T3_start(void) {
    // T3_irq_activation(ON);
    T3CONbits.TON = 1;
}

void T3_stop(void) {
    // T3_irq_activation(OFF);
    T3CONbits.TON = 0;
}

void setT1(int period) {
    T1CONbits.TON = 0; // Disable Timer
    T1CONbits.TCS = 0; // Select internal instruction
    // cycle clock
    T1CONbits.TGATE = 0; // Disable Gated Timer mode
    T1CONbits.TCKPS = 0b00; // Select 1:1 Prescaler
    TMR1 = 0x00; // Clear timer register
    PR1 = period; // Load the period value
    IPC0bits.T1IP = 0x01; // Set Timer1 Interrupt Priority Level
    IFS0bits.T1IF = 0; // Clear Timer1 Interrupt Flag
    IEC0bits.T1IE = 1; // Enable Timer1 interrupt
    T1CONbits.TON = 1; // Start Timer
}

void __attribute__((__interrupt__, no_auto_psv)) _T1Interrupt(void){
       /* Interrupt Service Routine code goes here */
    // rect signal on RB15
       PORTBbits.RB15 = !LATBbits.LATB15;
       IFS0bits.T1IF = 0; // Clear Timer1 Interrupt Flag
    //    if(PORTBbits.RB6 == 1) {
    //        PR1 = 999;
    //    }
    //     else {
    //         PR1 = 499;
    //     }
    //    if (LATBbits.LATB15 == 1) {
    //        PORTBbits.RB15 = 0;
    //    } else {
    //        PORTBbits.RB15 = 1;
    //    }
}

void __attribute__((__interrupt__, no_auto_psv)) _T3Interrupt (void) {
    LATBbits.LATB14 = !LATBbits.LATB14;
    IFS0bits.T3IF = 0;
}
