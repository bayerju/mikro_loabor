/* 
 * File:   main.c
 * Author: Julian
 *
 * Created on 28. November 2022, 16:07
 */

#include <stdio.h>
#include <stdlib.h>
     
#include "global_definitions.h"
#include "config.h" // sets primary oscillator to 4MHz
#include "pll.h"
#include "dht.h"
#include "timer.h"
#include "i2c_routines.h"
#include "OLED.h"
#include "uart.h"

#define datapin 5 // RB15

#define ROT LATBbits.LATB15
#define GELB LATBbits.LATB13
#define GRUEN LATBbits.LATB14

// #define VALUE_10us 0.000001 // 1ms

// #define step_10us = VALUE_10us/(1/(FCY/2));

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
            snprintf(buffer, sizeof(buffer), "%.1f\n", (double)*boarder);
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

           
        char tempString [20] = {0};
        char humString [20] = {0};

        int data[40] = {0};
        float tempFloat = 0, humFloat = 0;

        char walkingStringDisplay [20] = "Test";

        startDHT22();
        T3_setup();
        FloatData dataValues = readData(data, tempString, humString);


        fb_draw_string(10,0,tempString);
        fb_draw_one_line_string(0,3,humString);

        int i = 0;
        for(i=0;i<128;i++){
            fb_draw_one_line_string(i,5,walkingStringDisplay);
            fb_show();
        }

        fb_show();

        if (dataValues.hum > boarderRedHum) {
            ROT = 1;
            GRUEN = 0;
            GELB = 0;
        } else if (dataValues.hum > borderYellowHum && dataValues.hum < boarderRedHum) {
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
