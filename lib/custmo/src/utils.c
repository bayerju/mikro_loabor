#include "p33FJ128GP802.h"

void setPinB(int pinNumber, int level) {    
    switch(pinNumber) {
        case 0:
            LATBbits.LATB0 = level;
            break;
        case 1:
            LATBbits.LATB1 = level;
            break;
        case 2:
            LATBbits.LATB2 = level;
            break;
        case 3:
            LATBbits.LATB3 = level;
            break;
        case 4:
            LATBbits.LATB4 = level;
            break;
        case 5:
            LATBbits.LATB5 = level;
            break;
        case 6:
            LATBbits.LATB6 = level;
            break;
        case 7:
            LATBbits.LATB7 = level;
            break;
        case 8:
            LATBbits.LATB8 = level;
            break;
        case 9:
            LATBbits.LATB9 = level;
            break;
        case 10:
            LATBbits.LATB10 = level;
            break;
        case 11:
            LATBbits.LATB11 = level;
            break;
        case 12:
            LATBbits.LATB12 = level;
            break;
        case 13:
            LATBbits.LATB13 = level;
            break;
        case 14:
            LATBbits.LATB14 = level;
            break;
        case 15:
            LATBbits.LATB15 = level;
            break;
    }
}