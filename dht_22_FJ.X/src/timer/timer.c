/**
 * @file timer.c
 * @author Group DHT22
 * @brief Initializing the timer
 * @version 0.1
 * @date 2023-01-09
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "dht.h"
#include "timer.h"
// TODO: Screen shot 6
#define T3_Period 65000         // 1us with 4MHz: 4MHz
                                // Befehlstakt: 2Mhz -> 1/2Mhz = 0.5us -> 10us/0.5us = 20

#define IOLock() __builtin_write_OSCCONL(OSCCON | 0x40);
#define IOUnlock() __builtin_write_OSCCONL( OSCCON & 0xbf);

void T3_setup(void) {
    T3CONbits.TON = 0;          // Disable Timer
    T3CONbits.TCS = 0;          // Select internal instruction cycle clock
    T3CONbits.TGATE = 0;        // Disable Gated Timer mode
    T3CONbits.TCKPS = 0b00;     // Select 1:1 Prescaler
    TMR3 = 0x00;                // Clear timer register
    PR3 = T3_Period;            // Load the period value
    IPC2bits.T3IP = 0x01;       // Set Timer3 Interrupt Priority Level // TODO: can we have two same prioritiylevels?
    IFS0bits.T3IF = 0;          // Clear Timer3 Interrupt Flag
    IEC0bits.T3IE = 0;          // Disable Timer3 interrupt
    T3CONbits.TON = 1;          // Start Timer
}

void initIC2(void) {
    TRISBbits.TRISB5 = 1; // set RB5 as input
    TMR3 = 0;
    IOUnlock();
    RPINR7bits.IC2R = 5; // set IC2 to RB5
    IOLock();
    IC2CONbits.ICSIDL = 1; // stops at idle CPU
	IC2CONbits.ICTMR = 0; // Uses Timer3
	IC2CONbits.ICI = 0b00; // interrupt every capture event
	IC2CONbits.ICM = 0b000; // turn off and wait for it to bie turned on
    IEC0bits.IC2IE = 1;						// enable IC2 interrupt
    IFS0bits.IC2IF = 0;						// clear IC2 interrupt flag
}

void startI2C(void) {
    TMR3 = 0;
    IC2CONbits.ICM = 0b010; // capture on every falling edge
}

void __attribute__((interrupt, shadow, no_auto_psv)) _IC2Interrupt()
{
    static int currentBit = 0;
    int timeAtOne = TMR3;
    if (currentBit < 0) { // to skip the first one if necessary
        TMR3 = 0;
        timeLog[50+currentBit] = timeAtOne;
        currentBit++;
        IFS0bits.IC2IF = 0;	
        return;
    }
    if (currentBit >= 40) {
        currentBit = 0;
        evaluateBitData(data, tempString, humString);
        IC2CONbits.ICM = 0; // disable IC2
    }
    
    if (timeAtOne >= 4000 && timeAtOne < 6000) {
        data[currentBit] = 1;
        timeLog[currentBit] = timeAtOne;
        currentBit++;
    } else if (timeAtOne < 4000) {
        data[currentBit] = 0;
        timeLog[currentBit] = timeAtOne;
        currentBit++;
    } else {
        throwError(ERROR_BIT_EVAL_FAILED);
    }
    
	TMR3 = 0;								// clear timer 3
	IFS0bits.IC2IF = 0;						// clear IC2 interrupt flag

}

// void __attribute__((__interrupt__, no_auto_psv)) _T3Interrupt(void){
// // q: why does this interrupt trigger every 40 to 50 cycles?
// // a:
//     static int currentBit = 0;
//     int test = currentBit;
//     if (currentBit >= 40) {
//         currentBit = 0;
//         evaluateBitData(data, tempString, humString);
//         T3_setup();
//     }
    
//     if (TMR3 > 2000 && TMR3 < 4000) {
//     data[currentBit] = TMR3;
//     TMR3 = 0;
//     currentBit++;
//     } else if (TMR3 > 600 && TMR3 < 2000) {
//     data[currentBit] = TMR3;
//     TMR3 = 0;
//     currentBit++;
//     }

//     IFS0bits.T1IF = 0; // Interrupt Flag zurücksetzen
// }
