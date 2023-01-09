
#include "ampel.h" 
#include "OLED.h"

void setAmpel(float currentValue, float boarderRed, float borderYellow) {
            if (currentValue > boarderRed) {                                       // Humidity is higher than the red border
            ROT = 1;
            GRUEN = 0;
            GELB = 0;
            char walkingStringDisplay [20] = "Warning!";
            int i = 0;
            for(i=0;i<128;i++){
            fb_draw_one_line_string(i,5,walkingStringDisplay);
            fb_show();
        }
        } else if (currentValue > borderYellow && currentValue < boarderRed) {      // Humidity is higher than the yellow border
            ROT = 0;
            GRUEN = 0;
            GELB = 1;
        } else {                                                                    // Humidity is lower than the yellow border                                             
            ROT = 0;
            GRUEN = 1;
            GELB = 0;
        }
}
