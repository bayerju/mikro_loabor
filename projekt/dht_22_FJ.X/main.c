/* 
 * File:   main.c
 * Author: Julian
 *
 * Created on 28. November 2022, 16:07
 */

#include <stdio.h>
#include <stdlib.h>
// #include "p33FJ128GP802.h"
#include <xc.h>
#include "config.h" // sets primary oscillator to 4MHz
#include "dht.h"
#include "timer.h"
#include "global_definitions.h"
#include "pll.h"
#include <libpic30.h>

#define datapin 5 // RB15
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

 int getRecievedByte(int offset, int *data) {
     int byte = 0;
     int i = 0;
     for (i = 0 ; i < 8; i++) {
            if (data[i + offset] == 1) {
                byte = set_bit(byte, 7-i);
            }
        }
     return byte;
 }

/*
 * 
 */
int main(int argc, char** argv) {
    AD1PCFGL = 0xffff;
    

    setup_pll();
    // CNPU1bits.CN15PUE = 1; // pull up resistor for RB15
    isMessuringSensorFlag = 0;
    TRISBbits.TRISB14 = 0;
    TRISBbits.TRISB9 = 0;
    PORTBbits.RB9 = 0;
    
  

    
    
    
    __delay_ms(1000);
   
    while(1){
        int data[40] = {0};
        int temp = 0, hum = 0, tempByte1 = 0, tempByte2 = 0, humByte1 = 0,humByte2 = 0, checksum = 0;
        startDHT22();
        T3_setup();
        readData(data);

        humByte1 = getRecievedByte(0, data);
        humByte2 = getRecievedByte(8, data);
        tempByte1 = getRecievedByte(16, data);
        tempByte2 = getRecievedByte(24, data);
        checksum = getRecievedByte(32, data);
        
        int sum = humByte1 + humByte2 + tempByte1 +tempByte2;
        int low8Bits = sum & 0xFF;
        if (checksum == low8Bits) {
            temp = (tempByte1 << 8) + tempByte2;
            hum = (humByte1 << 8) + humByte2;
        }
        __delay_ms(2000)
    };


    return (0);
}
