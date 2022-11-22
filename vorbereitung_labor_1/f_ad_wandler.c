#include <stdio.h>
#include <stdlib.h>
#include "p33FJ128GP802.h"
#include "config.h"
#include "init_osc_80.h"
#include "init_osc_80.h"
#include "adc.h"
#include "timer.h"
#include "pwm.h"

#define MIN_VOLTAGE 0
#define MAX_VOLTAGE 3.3

void result_led(unsigned char state) { LATBbits.LATB5 = state; }

/**
 * @brief set 8 LEDs so they show the linear value of input voltage from 0 to 3.3V with none beeing on at 0V and all beeing on at 3.3V
 * TODO: calc the voltage correctly and set the values
 */
void setLeds(uint16_t inputVoltage) {
    inputVoltage = inputVoltage >> 8;
    int voltageSteps = MAX_VOLTAGE / 7;
    PORTBbits.RB5 = (inputVoltage > MIN_VOLTAGE);
    PORTBbits.RB6 = (inputVoltage > voltageSteps);
    PORTBbits.RB7 = (inputVoltage > 2*voltageSteps);
    PORTBbits.RB8 = (inputVoltage > 3*voltageSteps);
    PORTBbits.RB9 = (inputVoltage > 4*voltageSteps);
    PORTBbits.RB10 = (inputVoltage > 5*voltageSteps);
    PORTBbits.RB11 = (inputVoltage > 6*voltageSteps);
    PORTBbits.RB12 = (inputVoltage > MAX_VOLTAGE);

}

int calcTastV(uint16_t inputVoltage) { 
    int VCC = 5;
    int tastV = inputVoltage / VCC;
    return tastV;
}

void switchCaseVariant() {
    while(1){
        switch(adcValue>>8) {
            case 0x0:
            case 0x1:
            case 0x2:
                setPwm(5);
                setPinB(5, 0);
                setPinB(6, 0);
                setPinB(7, 0);
                setPinB(8, 0);
                setPinB(9, 0);
                setPinB(10, 0);
                setPinB(11, 0);
                setPinB(12, 0);
                break;
            case 0x3:
            case 0x4:
                setPwm(10);
                setPinB(5, 1);
                setPinB(6, 0);
                setPinB(7, 0);
                setPinB(8, 0);
                setPinB(9, 0);
                setPinB(10, 0);
                setPinB(11, 0);
                setPinB(12, 0);
                break;
            case 0x5:
            case 0x6:
                setPwm(20);
                setPinB(5, 1);
                setPinB(6, 1);
                setPinB(7, 0);
                setPinB(8, 0);
                setPinB(9, 0);
                setPinB(10, 0);
                setPinB(11, 0);
                setPinB(12, 0);
                break;
            case 0x7:
                setPwm(40);
                setPinB(5, 1);
                setPinB(6, 1);
                setPinB(7, 1);
                setPinB(8, 0);
                setPinB(9, 0);
                setPinB(10, 0);
                setPinB(11, 0);
                setPinB(12, 0);
                break;
            case 0x8:
                setPwm(50);
                setPinB(5, 1);
                setPinB(6, 1);
                setPinB(7, 1);
                setPinB(8, 1);
                setPinB(9, 0);
                setPinB(10, 0);
                setPinB(11, 0);
                setPinB(12, 0);
                break;
            case 0x9:
                setPwm(60);
                setPinB(5, 1);
                setPinB(6, 1);
                setPinB(7, 1);
                setPinB(8, 1);
                setPinB(9, 1);
                setPinB(10, 0);
                setPinB(11, 0);
                setPinB(12, 0);
                break;
            case 0xA:
                setPwm(80);
                setPinB(5, 1);
                setPinB(6, 1);
                setPinB(7, 1);
                setPinB(8, 1);
                setPinB(9, 1);
                setPinB(10, 1);
                setPinB(11, 0);
                setPinB(12, 0);
                break;
            case 0xB:
                setPwm(90);
                setPinB(5, 1);
                setPinB(6, 1);
                setPinB(7, 1);
                setPinB(8, 1);
                setPinB(9, 1);
                setPinB(10, 1);
                setPinB(11, 1);
                setPinB(12, 0);
                break;
            case 0xC:
            case 0xD:
            case 0xE:
            case 0xF:
                setPwm(100);
                setPinB(5, 1);
                setPinB(6, 1);
                setPinB(7, 1);
                setPinB(8, 1);
                setPinB(9, 1);
                setPinB(10, 1);
                setPinB(11, 1);
                setPinB(12, 1);
                break;
        }
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
int main (int argc, char** argv) {
    unsigned int result;
    // unsigned int rescmp = 512;

    init_80();
    adc_init();
    T3_init();

    TRISB = 0;
    
    initPwm();
    adc_start();
    T3_start();
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
