#include <stdio.h>
#include <stdlib.h>
#include "p33FJ128GP802.h"
#include "config.h"
#include "init_osc_80.h"
#include "init_osc_80.h"
#include "adc.h"
#include "timer.h"
#include "pwm.h"

void result_led(unsigned char state) { LATBbits.LATB5 = state; }

/**
 * @brief set 8 LEDs so they show the linear value of input voltage from 0 to 3.3V with none beeing on at 0V and all beeing on at 3.3V
 * TODO: calc the voltage correctly and set the values
 */
void setLeds(long inputVoltage) {
    LATBbits.LATB0 = (inputVoltage > 512);
    LATBbits.LATB1 = (inputVoltage > 600);
    LATBbits.LATB2 = (inputVoltage > 700);
    LATBbits.LATB3 = (inputVoltage > 800);
    LATBbits.LATB4 = (inputVoltage > 900);
    LATBbits.LATB5 = (inputVoltage > 1000);
    LATBbits.LATB6 = (inputVoltage > 1000);
    LATBbits.LATB7 = (inputVoltage > 1024);
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
            result = adc_avg();
            setLeds(result);
        }
    }
    
    // read analog voltage on AN9 between 0 and 3.3V. The frequency of the ad conversion is 4kHz.
    
    // set analog input pin to analog input
    TRISBbits.TRISB5 = 1;

}
