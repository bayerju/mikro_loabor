#include <stdio.h>
#include <stdlib.h>
#include "p33FJ128GP802.h"
#include "config.h"



/**
 * @brief 
 * Berechnung PLL:
 * Fin = 4MHz
 * FOSC = 80MHz = Fin * (M/(N1*N2))
 * N1 = 2 => FREF = fin/N1 = 2MHz =Y ist ok, da zwischen 0.8 und 8MHz
 * fvco = N2*FOSC => min: N2_min*FOSC = 2*80MHz = 160MHz Ist ok, da es zwischen 100 und 200 MHz ist
 * M = fvco/fref = 160/2 = 80
 * 
 * Parameter:
 * PLLPRE = 0 => N1 = 2
 * PLLPOST = 0 => N2 = 2
 * PLLDIV = 78 => M = 80
 * 
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char** argv) {
    // set plldiv to 78
    PLLFBDbits.PLLDIV = 78;
    // set pllpost to 0
    CLKDIVbits.PLLPOST = 0;
    // set pllpres to 0
    CLKDIVbits.PLLPRE = 0;

    __builtin_write_OSCCONH(0x03);
    __builtin_write_OSCCONL(0x01);

    while (OSCCONbits.COSC != 0b011);
    while (OSCCONbits.LOCK != 1);

    TRISBbits.TRISB15 = 0;
    while(1) {
        PORTBbits.RB15 = 0;
        PORTBbits.RB15 = 1;
    }
}