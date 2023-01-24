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

#include "ampel.h"
#include "config.h" // sets primary oscillator to 4MHz
#include "dht.h"
#include "global_definitions.h"
#include "i2c_routines.h"
#include "OLED.h"
#include "pll.h"
#include "timer.h"
#include "uart.h"
#include "uart_dsPIC.h"
#include "timerstart.h"
// #include "ampel.h"

#define datapin 5 // RB15
//TODO: Screen shot 8
int main(int argc, char** argv) {
    AD1PCFGL = 0xffff;
    

    setup_pll();
    // CNPU1bits.CN15PUE = 1; // pull up resistor for RB15 // could not be used, because it is too big for the dht sensor
    isMessuringSensorFlag = 0;

    TRISBbits.TRISB9 = 0;
    PORTBbits.RB9 = 0;
    init_i2c();
    init_OLED();
    CommConfig();               // Configure UART1
    CommInit();
    CommEnable();               // Enable UART1
    
    __delay_ms(1000);

    unsigned char iState = 0;
    int i = 0;
    CommPutString("To change the middle border value type Y and to change the upper border Value type R. \n");
    T3_setup();
    
    T1_setup();
    initAmpelLEDs();
   
   /**
    * @brief Programme control through infinitely continuous loop 
    * 
    */
    while(1){
        if (currentErrorCode != NO_ERROR)
        {
            fb_clear();
            fb_draw_one_line_string(i,3,errorMessage);
            fb_show();
        } else {
            ChangeValue(iState, &borderRedHum, &borderYellowHum); // change the border values
            oled_draw(tempString, humString); //
            setAmpel(sensorData.hum, borderRedHum, borderYellowHum, i);
        }
        i++;
        if (i > 127) {
            i = 0;
        }
    };
    return (0);
}
