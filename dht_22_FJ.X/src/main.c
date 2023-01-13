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

int main(int argc, char** argv) {
    AD1PCFGL = 0xffff;
    

    setup_pll();
    // CNPU1bits.CN15PUE = 1; // pull up resistor for RB15 // could not be used, because it is too big for the dht sensor
    isMessuringSensorFlag = 0;

// TODO: move into ampel.c
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
    
    __delay_ms(1000);

    unsigned char iState = 0;
    CommPutString("To change the middle border value type Y and to change the upper border Value type R. \n");
    T3_setup();
   
    while(1){
            
        ChangeValue(iState, &borderRedHum, &borderYellowHum);

        int data[40] = {0};

        startDHT22();
        TMR3 = 0x00;
        FloatData dataValues = readData(data, tempString, humString);

        char timerString [20] = {0};
        sprintf(timerString, "Timer: %d", TMR3);
        oled_draw(tempString, humString);
        setAmpel(dataValues.hum, borderRedHum, borderYellowHum);
        
        __delay_ms(1000)
    };


    return (0);
}
