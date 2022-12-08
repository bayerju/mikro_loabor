// #include "p33FJ128GP802.h"
#include <xc.h>

    void setup_pll_80mhz() {
            // set plldiv to 78
    PLLFBDbits.PLLDIV = 78;
    // set pllpost to 0
    CLKDIVbits.PLLPOST = 0;
    // set pllpres to 0
    CLKDIVbits.PLLPRE = 0;

    __builtin_write_OSCCONH(0x03);
    __builtin_write_OSCCONL(0x01);

    while (OSCCONbits.COSC != 0b011); // Wait for Clock switch to occur
    while (OSCCONbits.LOCK != 1); // Wait for PLL to lock
    }