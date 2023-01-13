/**
 * @file main.c
 * @author Group DHT22
 * @brief 
 * @version 0.1
 * @date 2023-01-09
 * 
 * @copyright Copyright (c) 2023
 * 
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
#include "uart_dsPIC.h"
// #include "ampel.h"

#define datapin 5 // RB15



// #define VALUE_10us 0.000001 // 1ms

// #define step_10us = VALUE_10us/(1/(FCY/2));



//  void CommGetSetBorderValue(float *border, unsigned char *iState) {
//     if (CommIsEmpty() != 1){  // Echo of RX
//         char buffer[30] = "The new value is: ";
//         char inputBuffer[10] = {0};
//         float currentvalue = 0;
//         CommGetString(inputBuffer);
//         currentvalue = (float)atof(inputBuffer);
//         if (currentvalue > 0 && currentvalue < 100) { // check if the value is in the range of 0 to 100
//             *border = currentvalue;
//             snprintf(buffer, sizeof(buffer), "%.1f\n", (double)*border);
//             CommPutString(buffer);
//             *iState = 1;
//         } else {
//             CommPutString("The value is not in the range of 0 to 100. \nPlase try again. \n");
//         }
//     }
//     return;
//  }

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
    
    // float borderRedHum = 70;
    // float borderYellowHum = 61;
    
    
    __delay_ms(1000);

    unsigned char iState = 0;
    CommPutString("To change the middle border value type Y and to change the upper border Value type R. \n");
    T3_setup();
    
   
    while(1){
            
        ChangeValue(iState, &borderRedHum, &borderYellowHum);
           
        char tempString [20] = {0};
        char humString [20] = {0};

        int data[40] = {0};

        startDHT22();
        TMR3 = 0x00;
        FloatData dataValues = readData(data, tempString, humString);

        char timerString [20] = {0};
        sprintf(timerString, "Timer: %d", TMR3);
        fb_clear();
        fb_draw_string(10,0,tempString);
        fb_draw_string(10,4,timerString);
        fb_draw_one_line_string(0,3,humString);

        fb_show();

        setAmpel(dataValues.hum, borderRedHum, borderYellowHum);
        
        __delay_ms(1000)
    };


    return (0);
}
