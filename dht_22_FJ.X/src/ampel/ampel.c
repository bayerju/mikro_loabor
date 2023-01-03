#include "ampel.h" 

void setAmpel(float currentValue, float boarderRed, float borderYellow) {
            if (currentValue > boarderRed) {
            ROT = 1;
            GRUEN = 0;
            GELB = 0;
        } else if (currentValue > borderYellow && currentValue < boarderRed) {
            ROT = 0;
            GRUEN = 0;
            GELB = 1;
        } else {
            ROT = 0;
            GRUEN = 1;
            GELB = 0;
        }
}
