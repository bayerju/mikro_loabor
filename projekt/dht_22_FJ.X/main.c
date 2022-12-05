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
#include "dht.h"
#include "timer.h"
#include "global_definitions.h"
#include "pll.h"

#define datapin 15 // RB15
#define FCY 80 000 000 // 80MHz

/*
 * 
 */
int main(int argc, char** argv) {
    setup_pll();
    CNPU1bits.CN15PUE = 1; // pull up resistor for RB15
    isMessuringSensorFlag = 0;
    TRISBbits.TRISB14 = 0;
    int i;
    delay_ms(1000);
    startDHT22();
    T3_setup();
    for (i = 0; i> 10000000; i++);
    int test = 0;
    while (1) {
        test++;
    }

    return (0);
}

