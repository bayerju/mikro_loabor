#include <stdio.h>
#include <stdlib.h>
#include "p33FJ128GP802.h"

void initPwm() {
    __builtin_write_OSCCONL(OSCCONL & 0xbf);
    OC1CONbits.OCM = 0b000;
    OC1R = 100;
    OC1RS = 500;
    OC1CONbits.OCTSEL = 1;
    OC1CONbits.OCM = 0b110;
    TRISBbits.TRISB13 = 0;
    RPOR6bits.RP13R = 18;  // RB13
    __builtin_write_OSCCONL(OSCCONL | 0x40);
    
}

void setPwm(int percentage) {
    OC1RS = percentage*5;
}