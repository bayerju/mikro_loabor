#include <stdio.h>
#include <stdlib.h>
#include "p33FJ128GP802.h"

int main(int argc, char** argv) {
    // read port B RB5 and write inverted value to portB RB15
    // RB5 is input
    TRISBbits.TRISB5 = 1;
    // RB15 is output
    TRISBbits.TRISB15 = 0;
    while(1) {
        PORTBbits.RB15 = !PORTBbits.RB5;
    }    

    return (EXIT_SUCCESS);
}
