#include <stdio.h>
#include <stdlib.h>
#include "p33FJ128GP802.h"
#include "config.h"
#include "adc.h"
#include "timer.h"

#define MIN_VOLTAGE 0
#define MAX_VOLTAGE 4095
#define MAX_4Bit_Voltage 15

void result_led(unsigned char state) { LATBbits.LATB5 = state; }

/**
 * @brief set 8 LEDs so they show the linear value of input voltage from 0 to 3.3V with none beeing on at 0V and all beeing on at 3.3V
 * TODO: calc the voltage correctly and set the values
 * 1111 
 */
void setLeds(uint16_t inputVoltage) {
    inputVoltage = inputVoltage >> 8;
    int voltageSteps = 2; // 15 / 8 ~= 2
    PORTBbits.RB5 = (inputVoltage > MIN_VOLTAGE);
    PORTBbits.RB6 = (inputVoltage > voltageSteps);
    PORTBbits.RB7 = (inputVoltage > 2*voltageSteps);
    PORTBbits.RB8 = (inputVoltage > 3*voltageSteps);
    PORTBbits.RB9 = (inputVoltage > 4*voltageSteps);
    PORTBbits.RB10 = (inputVoltage > 5*voltageSteps);
    PORTBbits.RB11 = (inputVoltage > 6*voltageSteps);
    PORTBbits.RB12 = (inputVoltage >= MAX_4Bit_Voltage);
}

int calcTastV(unsigned int inputVoltage) {
    int shifted = inputVoltage >> 8;
    int tastV = shifted *100 / MAX_4Bit_Voltage;
    return tastV;
}



/**
 * @brief 
 * 
 * Timer setzen:
 * PR3 = T_Abtast/Tcy - 1
 * Tcy = 1/fcy = 1/40MHz = 25ns
*    t_Abtast = 1/f_Abtast = 1/4kHz = 250us
 *   PR3 = t_Abtast/t_cy - 1 = 250us/25ns - 1 = 9999
 * TODO: TSC überprüfen (Minute 8 im Video)
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
void main (int argc, char** argv) {
    unsigned int result;
    // unsigned int rescmp = 512;
    TRISB = 0;
    adc_init();
    T3_setup();

  
    
    initPwm();
    T3_start();
    adc_start();
    
    while (1)   
    {
        if (adc_flag) {
            // result = adc_avg();
            result = ADC1BUF0;
            setLeds(result);
            setPwm(calcTastV(result));
            adc_flag = 0;
        }
    }
    
    // read analog voltage on AN9 between 0 and 3.3V. The frequency of the ad conversion is 4kHz.
    
    // set AN9 (RB15) as analog input
    TRISBbits.TRISB15 = 1;

    

}
