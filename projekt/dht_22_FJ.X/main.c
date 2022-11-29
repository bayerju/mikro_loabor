/* 
 * File:   main.c
 * Author: Julian
 *
 * Created on 28. November 2022, 16:07
 */

#include <stdio.h>
#include <stdlib.h>
#include "p33FJ128GP802.h"
#include "config.h" // sets primary oscillator to 4MHz
#include "timer.h"
#include "global_definitions.h"

#define datapin 15 // RB15

/*
 * 
 */
int main(int argc, char** argv) {
    // pull up resistor for RB15
    CNPU1bits.CN15PUE = 1;
    isMessuringSensorFlag = 0;
    startDHT22();
    if (isWakingSensorFlag == 1) {
    T3_setup();

    }

    return (0);
}

