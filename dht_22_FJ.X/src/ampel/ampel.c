
#include "ampel.h" 
#include "OLED.h"
#include "global_definitions.h"

/**
 * @brief Traffic light control
 * 
 * @param currentValue 
 * @param borderRed 
 * The red light indicates that the humidity is too high.
 * @param borderYellow 
 * The yellow light sinalises that the humidity is too low
 */

// TODO: Screen shot 1
void initAmpelLEDs (void) {
    LED_GREEN_INIT = 0;
    LED_YELLOW_INIT = 0;
    LED_RED_INIT = 0;
}

void setAmpelError (void) {
    LED_RED = 1;
    LED_GREEN = 1;
    LED_YELLOW = 1;
}

void setAmpel(float currentValue, float borderRed, float borderYellow, int loopCounter_OLED) {
    if (currentValue > borderRed) {                                       // Humidity is higher than the red border --> Red light on
        LED_RED = 1;
        LED_GREEN = 0;
        LED_YELLOW = 0;
        char walkingStringDisplay [20] = "Warning!";                           // Inizalisation when humidity is exceeded --> Output warning
        fb_draw_one_line_string(loopCounter_OLED,5,walkingStringDisplay);
        fb_show();
    } else if (currentValue > borderYellow && currentValue < borderRed) {      // Humidity is higher than the yellow border --> Green light on
        LED_RED = 0;
        LED_GREEN = 0;
        LED_YELLOW = 1;
    } else {                                                                    // Humidity is lower than the yellow border --> Yellow light on                                        
        LED_RED = 0;
        LED_GREEN = 1;
        LED_YELLOW = 0;
    }
}
