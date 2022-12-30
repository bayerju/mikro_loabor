/* 
 * File:   main.c
 * Author: Julian
 *
 * Created on 28. November 2022, 16:07
 */

#include <stdio.h>
#include <stdlib.h>
#ifndef __dsPIC33FJ128GP802__
    #define __dsPIC33FJ128GP802__
#endif
     
#include <xc.h>
#include "config.h" // sets primary oscillator to 4MHz
#include "dht.h"
#include "timer.h"
#include "global_definitions.h"
#include "pll.h"
#include <libpic30.h>
#include "PIC_init.h"
#include "i2c_routines.h"
#include "OLED.h"
#include "uart.h"
#include "uart_dsPIC.h"

#define datapin 5 // RB15

#define ROT LATBbits.LATB15
#define GELB LATBbits.LATB13
#define GRUEN LATBbits.LATB14

// #define VALUE_10us 0.000001 // 1ms

// #define step_10us = VALUE_10us/(1/(FCY/2));


// convert int with multiple digits to char array and write to char array c
int intToChar(int num, char *c) {
    int i = 0;
    int j = 0;
    int temp = num;
    int length = 0;
    while (temp != 0) {
        temp = temp / 10;
        length++;
    }
    for (i = length - 1; i >= 0; i--) {
        c[i] = num % 10 + '0';
        num = num / 10;
    }
    return 0;
}

// concat char array to char array
int concatChar(char *c1, char *c2, char *newArray) {
    int i = 0;
    int j = 0;
    int k = 0;
    while (c1[i] != '\0') {
        newArray[k] = c1[i];
        i++;
        k++;
    }
    while (c2[j] != '\0') {
        newArray[k] = c2[j];
        j++;
        k++;
    }
    return 0;
}

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

 void startUartComm() {

 }

 void CommGetString(char *stringArray) {
     int i = 0;
     unsigned char currentInput = 0;
     while (CommIsEmpty() != 1 ) { // sizeof gibt die Größe in Byte zurück und nicht die Anzahl der Elemente, aber da es hier achrs sind, ist das das gleiche.
         currentInput = CommGetChar();
         if (currentInput == '\n' || currentInput == '\r' || currentInput == 'q') {
             return;
         }
         stringArray[i] = currentInput;
         i++;
     }
     return;
 }

 void CommGetSetBorderValue(float *boarder, unsigned char *iState) {
    if (CommIsEmpty() != 1){  // Echo of RX
        char buffer[30] = "The new value is: ";
        char inputBuffer[10] = {0};
        float currentvalue = 0;
        CommGetString(inputBuffer);
        currentvalue = (float)atof(inputBuffer);
        if (currentvalue > 0 && currentvalue < 100) {
            *boarder = currentvalue;
            snprintf(buffer, sizeof(buffer), "%.1f\n", *boarder);
            CommPutString(buffer);
            *iState = 1;
        } else {
            CommPutString("The value is not in the range of 0 to 100. \nPlase try again. \n");
        }
    }
    return;
 }

int main(int argc, char** argv) {
    AD1PCFGL = 0xffff;
    

    setup_pll();
    // CNPU1bits.CN15PUE = 1; // pull up resistor for RB15
    isMessuringSensorFlag = 0;

    // init ampel LEDs
    TRISBbits.TRISB13 = 0;
    TRISBbits.TRISB14 = 0;
    TRISBbits.TRISB15 = 0;


    TRISBbits.TRISB9 = 0;
    PORTBbits.RB9 = 0;
    init_i2c();
    init_OLED();
    CommConfig();               // Configure UART1
    CommInit();
    CommEnable();               // Enable UART1
    
    float boarderRedHum = 70;
    float borderYellowHum = 61;
    
    
    __delay_ms(1000);

    unsigned char iState = 0;
    char inputValue[30] = {0};
    CommPutString("To change the middle border value type x and to change the upper boarder Value type k. \n");
   
    while(1){
            
            switch (iState) {
                case 0: // wait for first input
                    if (CommIsEmpty() != 1){  // Echo of RX
                        iState = CommGetChar();
                    }
                    break;
                case 1:
                    CommPutString("To change the middle border value type x and to change the upper boarder Value type k.\n");
                    iState = 0;
                    break;
                case 120: // x changes the middle boarder value
                    CommPutString("please insert the new value for the middle Boarder for the humidity: \n");
                    iState = 2;
                case 2:
                    CommGetSetBorderValue(&borderYellowHum, &iState);
                    break;
                case 107: // k changes the upper boarder value
                    CommPutString("please insert the new value for the upper Boarder for the humidity: \n");
                    iState = 3;
                case 3:
                    CommGetSetBorderValue(&boarderRedHum, &iState);
                    break;


                default:
                    // if (CommIsEmpty() != 1){  // Echo of RX
                    //     iState = CommGetChar();
                    // }
                    break;
            }

           
        int data[40] = {0};
        int temp = 0, hum = 0; 
        float tempFloat = 0, humFloat = 0;
        int tempByte1 = 0, tempByte2 = 0, humByte1 = 0,humByte2 = 0, checksum = 0;
        char tempString [20] = {0};
        char tempStringDisplay [20] = {0};
        char humStringDisplay [20] = {0};
        char humString [20] = {0};
        char walkingString [20] = {0};
        char walkingStringDisplay [20] = {0};
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
            temp = (tempByte1 << 8) + tempByte2; // TODO: geteilt durch ersetzen f�r Performence
            tempFloat = (float)temp/10;
            hum = (humByte1 << 8) + humByte2;
            humFloat = (float)hum/10;
            snprintf(tempString, sizeof tempString, "%.1f", tempFloat);
            snprintf(humString, sizeof humString, "%.1f", humFloat);
            // intToChar(temp, tempString);
            concatChar("Temperatur: ", tempString, tempStringDisplay);
            concatChar("Feuchtigkeit: ", humString, humStringDisplay);
            concatChar("Walking: ", walkingString, walkingStringDisplay);
        }
        //fb_draw_string_big(35,0,"FH KIEL");
        fb_draw_string(10,0,tempStringDisplay);
        fb_draw_one_line_string(0,3,humStringDisplay);
        // fb_draw_string(0,5,walkingStringDisplay);
        //fb_draw_string(10,16,"Feuchtigkeit: ");
        // Animations
        int i = 0;
        for(i=0;i<128;i++){
            // for (int j = 0; j < 128; j++)
            // {
            //     fb_drawPixel(i,j,1);
            // }
            // fb_drawPixel(i,5,1);
            fb_draw_one_line_string(i,5,walkingStringDisplay);
            fb_show();
        }
        // for(i=63;i>42;i--){
        //     fb_draw_string(i,5,walkingStringDisplay);
        //     fb_show();
        // }
        // for(i=127;i;i--){
        //     fb_draw_string(i,5,walkingStringDisplay);
        //     fb_show();
        // }
        //  for(i=42;i<63;i++){
        //     fb_draw_string(i,5,walkingStringDisplay);
        //     fb_show();
        // }
        // for(i=0;i<128;i++){
        //     fb_draw_string(i,5,walkingStringDisplay);
        //     fb_show();
        // }
        // for(i=63;i>42;i--){
        //     fb_draw_string(i,5,walkingStringDisplay);
        //     fb_show();
        // }
        // for(i=127;i;i--){
        //     fb_draw_string(i,5,walkingStringDisplay);
        //     fb_show();
        // }
        //  for(i=42;i<63;i++){
        //     fb_draw_string(i,5,walkingStringDisplay);
        //     fb_show();
        //  }
        fb_show();

        if (humFloat > boarderRedHum) {
            ROT = 1;
            GRUEN = 0;
            GELB = 0;
        } else if (humFloat > borderYellowHum && humFloat < boarderRedHum) {
            ROT = 0;
            GRUEN = 0;
            GELB = 1;
        } else {
            ROT = 0;
            GRUEN = 1;
            GELB = 0;
        }
        
        __delay_ms(1000)
    };


    return (0);
}
