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
#include <libpic30.h>

#define datapin 15 // RB15
#define FCY 80000000 // 80MHz
// #define VALUE_10us 0.000001 // 1ms

// #define step_10us = VALUE_10us/(1/(FCY/2));

/**
 * @brief Set the bit object
 * SRC: https://hackernoon.com/bit-manipulation-in-c-and-c-1cs2bux
 * 
 * @param num 
 * @param position 
 * @return int 
 */
int set_bit(int num, int position)
{
	int mask = 1 << position;
	return num | mask;
}

/*
 * 
 */
int main(int argc, char** argv) {
    int data[40] = {0};
    int temp, hum, checksum = 0;

    setup_pll();
    CNPU1bits.CN15PUE = 1; // pull up resistor for RB15
    isMessuringSensorFlag = 0;
    TRISBbits.TRISB14 = 0;
    
    __delay_ms(1000);
    startDHT22();
    T3_setup();
    readData(data);

    int i;
    for (i = 0; i < 40; i++) {
        if (data[i] == 1 && i < 16) {
            temp = set_bit(temp, i);
        }
        if (data[i] == 1 && i >= 16 && i < 32) {
            hum = set_bit(hum, i - 16);
        }
        if (data[i] == 1 && i >= 32 && i < 40) {
            checksum = set_bit(checksum, i - 32); // check because checksum is 16 bits and
                                       // we only write 8 bits
        }
    }


    return (0);
}

