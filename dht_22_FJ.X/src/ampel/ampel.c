
#include "ampel.h" 
#include "OLED.h"

/**
 * @brief Traffic light control
 * 
 * @param currentValue 
 * @param boarderRed 
 * The red light indicates that the humidity is too high.
 * @param borderYellow 
 * The yellow light sinalises that the humidity is too low
 */

void setAmpel(float currentValue, float boarderRed, float borderYellow) 
            if (currentValue > boarderRed) {                                       // Humidity is higher than the red border --> Red light on
            ROT = 1;
            GRUEN = 0;
            GELB = 0;
            char walkingStringDisplay [20] = "Warning!";                           // Inizalisation when humidity is exceeded --> Output warning
            int i = 0;
            for(i=0;i<128;i++){                                                    // Inizalisation walking string (text)
            fb_draw_one_line_string(i,5,walkingStringDisplay);
            fb_show();
        }
        } else if (currentValue > borderYellow && currentValue < boarderRed) {      // Humidity is higher than the yellow border --> Green light on
            ROT = 0;
            GRUEN = 0;
            GELB = 1;
        } else {                                                                    // Humidity is lower than the yellow border --> Yellow light on                                        
            ROT = 0;
            GRUEN = 1;
            GELB = 0;
        }
}
