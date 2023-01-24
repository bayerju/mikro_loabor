
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
    TRISBbits.TRISB13 = 0;
    TRISBbits.TRISB14 = 0;
    TRISBbits.TRISB15 = 0;
}

void setAmpelError (void) {
    ROT = 1;
    GRUEN = 1;
    GELB = 1;
}

void setAmpel(float currentValue, float borderRed, float borderYellow, int loopCounter_OLED) {
    initAmpelLEDs();
    if (currentValue > borderRed) {                                       // Humidity is higher than the red border --> Red light on
        ROT = 1;
        GRUEN = 0;
        GELB = 0;
        char walkingStringDisplay [20] = "Warning!";                           // Inizalisation when humidity is exceeded --> Output warning
        fb_draw_one_line_string(loopCounter_OLED,5,walkingStringDisplay);
        fb_show();
    } else if (currentValue > borderYellow && currentValue < borderRed) {      // Humidity is higher than the yellow border --> Green light on
        ROT = 0;
        GRUEN = 0;
        GELB = 1;
    } else {                                                                    // Humidity is lower than the yellow border --> Yellow light on                                        
        ROT = 0;
        GRUEN = 1;
        GELB = 0;
    }
}
