// // generated through mplab x  -> production -> set conf bits
// // changed foscsel to pri and poscmd to xt
// // FBS
// #pragma config BWRP = WRPROTECT_OFF     // Boot Segment Write Protect (Boot Segment may be written)
// #pragma config BSS = NO_FLASH           // Boot Segment Program Flash Code Protection (No Boot program Flash segment)
// #pragma config RBS = NO_RAM             // Boot Segment RAM Protection (No Boot RAM)

// // FSS
// #pragma config SWRP = WRPROTECT_OFF     // Secure Segment Program Write Protect (Secure segment may be written)
// #pragma config SSS = NO_FLASH           // Secure Segment Program Flash Code Protection (No Secure Segment)
// #pragma config RSS = NO_RAM             // Secure Segment Data RAM Protection (No Secure RAM)

// // FGS
// #pragma config GWRP = OFF               // General Code Segment Write Protect (User program memory is not write-protected)
// #pragma config GSS = OFF                // General Segment Code Protection (User program memory is not code-protected)

// // FOSCSEL
// #pragma config FNOSC = PRI              // Oscillator Mode (Primary Oscillator (XT, HS, EC))
// #pragma config IESO = ON                // Internal External Switch Over Mode (Start-up device with FRC, then automatically switch to user-selected oscillator source when ready)

// // FOSC
// #pragma config POSCMD = XT              // Primary Oscillator Source (XT Oscillator Mode)
// #pragma config OSCIOFNC = OFF           // OSC2 Pin Function (OSC2 pin has clock out function)
// #pragma config IOL1WAY = ON             // Peripheral Pin Select Configuration (Allow Only One Re-configuration)
// #pragma config FCKSM = CSDCMD           // Clock Switching and Monitor (Both Clock Switching and Fail-Safe Clock Monitor are disabled)

// // FWDT
// #pragma config WDTPOST = PS32768        // Watchdog Timer Postscaler (1:32,768)
// #pragma config WDTPRE = PR128           // WDT Prescaler (1:128)
// #pragma config WINDIS = OFF             // Watchdog Timer Window (Watchdog Timer in Non-Window mode)
// #pragma config FWDTEN = ON              // Watchdog Timer Enable (Watchdog timer always enabled)

// // FPOR
// #pragma config FPWRT = PWR128           // POR Timer Value (128ms)
// #pragma config ALTI2C = OFF             // Alternate I2C  pins (I2C mapped to SDA1/SCL1 pins)

// // FICD
// #pragma config ICS = PGD1               // Comm Channel Select (Communicate on PGC1/EMUC1 and PGD1/EMUD1)
// #pragma config JTAGEN = OFF             // JTAG Port Enable (JTAG is Disabled)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include "config.h"
#include <stdio.h>
#include <stdlib.h>
#include "p33FJ128GP802.h"
#include "timer.h"

#define PR1_1kHz 999
#define PR1_2kHz 499

/*
1kHz rect -> 2kHz timer
F_OSC = 4MHz
F_CY = 2MHz
T_CY  = 5*10^-7s


TImer:
F_Timer = 2kHz
T_Timer = 0.5ms = 5*10^-4s

N = T_TImer/T_CY = 0.5ms/5*10^-7s = 1000
-> PR1_1kHz = N-1 = 1000-1 = 999
-> PR1_2kHz = N/2-1 = 500-1 = 499 da es doppelt so oft ausgeführt werden soll

*/


int main(int argc, char** argv) {
    // use 16bit timer 1 to generate rect signal of 1kHz at portB RB15 and change frequenzy to 2kHz if RB6 is low
    // RB15 is output
    TRISBbits.TRISB15 = 0;
    // RB6 is input
    TRISBbits.TRISB6 = 1;
    // set period register
    setT1(PR1_1kHz);

    int prev_RB6 = 0;


    while(1) {
        // if RB6 is low, change freq to 2kHz
        if(PORTBbits.RB6 == 0 && prev_RB6 == 1) {
            //PR1 = 999;
            setT1(PR1_2kHz);
            prev_RB6 = 0;
        }
        // if RB6 is high, change freq to 1kHz

        if (PORTBbits.RB6 == 1 && prev_RB6 == 0) {
            // PR1 = 1999;
            setT1(PR1_1kHz);
            prev_RB6 = 1;
        }
    }

    return (EXIT_SUCCESS);
}
