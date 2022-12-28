
#define FCY 40000000ULL
#include "PIC_init.h"

void init_system_clock()
{
	// ACHTUNG: neues MIK-Board läuft mit 4MHz, altes (kleines) Board mit 8MHz Quarz F_PLL_in
	// F_PLL_out: F_PLL_in * ( M / (N1*N2) )	ACHTUNG: FCY = F_PLL_out / 2
	CLKDIVbits.ROI = 0;
	CLKDIVbits.DOZE = 0;
	CLKDIVbits.DOZEN = 0;
	CLKDIVbits.FRCDIV = 0;
	CLKDIVbits.PLLPOST = 0;	// 0 - 31 N1=<value>+2
	CLKDIVbits.PLLPRE = 0;	// 0: N2=2 ; 1: N2=4 ; 3: N2=8
	
	PLLFBDbits.PLLDIV = 78; // 0-511 M=<value>+2			// 80MHz -> FCY = 40MHz
	
	while(!OSCCONbits.LOCK);    // wait for PLL ready
}

void init_ports()
{
	AD1PCFGL = 0xFFFF;		// Alle Eingänge digital !!!Dieses Register muss immer gesetzt werden, unterschiedliche initialisierung in DEBUG und RELEASE
	
	TRISB = 0;				// complete PORTB OUT
	
}

