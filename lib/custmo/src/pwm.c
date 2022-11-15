#include <stdio.h>
#include <stdlib.h>
#include "p33FJ128GP802.h"

void initPwm() {
    OC1CONbits.OCM = 0b000;
    OC1R = 100;
    OC1RS = 500;
    OC1CONbits.OCTSEL = 0;
    OC1CONbits.OCM = 0b110;
    RPOR6bits.RP13R = 18;
    
    T2CONbits.TON = 0;
    T2CONbits.TCS = 0;
    T2CONbits.TGATE = 0;
    T2CONbits.TCKPS = 0b00;
    TMR2 = 0x00;
    PR2 = 500;
    
    
    IPC1bits.T2IP = 0x01;
    IFS0bits.T2IF = 0;
    IEC0bits.T2IE = 1;
    T2CONbits.TON = 1;      
}

void setPwm(int percentage) {
    OC1RS = percentage*5;
}