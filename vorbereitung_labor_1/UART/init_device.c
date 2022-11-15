/** 
** 
**
**/

#include "xc.h"	    // Einbinden der prozessor-spezifischen 
                                // Header-Datei

void init_oscillator(void)
{
    PLLFBDbits.PLLDIV  =78;     // :80 pll feedback divider M1  
                                // fosz= M1*(fcrystal/N1)/N2 
                                // fosz=80*4MHz/2/4=40MHz 
                                // fcyle= 40MHz  Tcycle= 25ns
    CLKDIVbits.PLLPOST =0;            // CLKDIV = 0x3040
    CLKDIVbits.PLLPRE  =0;       

    __builtin_write_OSCCONH(0x3);     // Pri Osc mit PLL
    __builtin_write_OSCCONL(0x1);     // Set OSWEN

    while(OSCCONbits.COSC != 0b011);  // wait for PLL als neuer
                                      // Oszillator
    while(OSCCONbits.LOCK != 1);      // wait for PLL is locked
}

void init_ports(void)
{
    TRISA = 0xFF;               // All RAx Pins input (default)
    TRISB = 0xFFFF;             // All RBx Pins input (default)
    AD1PCFGL = 0xFFFF;          // Setzen der Analog-Pins als Digital
    
    // Set Outputs
   	TRISBbits.TRISB5 = 0;       // Setzen des RB5 als Ausgang
  //	TRISBbits.TRISB3 = 0;       // Setzen des RB3 als Ausgang
	

}    
