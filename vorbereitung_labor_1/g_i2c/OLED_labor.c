#define FCY 40000000ULL     // wichtig f�r <libpic30> mit Delay (muss davor stehen)

#include <xc.h>
#include <libpic30.h>
#include <stdint.h>
#include <stdlib.h>
#include "PIC_init.h"
#include "i2c_routines.h"
#include "OLED.h"

int main(void) {
    uint8_t i = 0;

    init_system_clock();
    init_ports();

    //LED-Test
    LATB = 0;
    LATB = 0x0010;
    for(i=0;i<12;i++){
        __delay_ms(50);
        LATB <<= 1;
    }

    init_i2c();
    init_OLED();

    fb_draw_string_big(35,0,"Labor 1");
    fb_draw_string(35,0,"gleicher Abstand nach LInks");

    fb_show();

    return 0;
    
}