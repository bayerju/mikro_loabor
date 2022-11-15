/*
 * File:   OLED_test.c
 * Author: Jan
 *
 * Created on 26. November 2020, 11:49
 */
#define FCY 40000000ULL     // wichtig für <libpic30> mit Delay (muss davor stehen)

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
    
    // LED-Test
    LATB = 0;
    LATB = 0x0010;
    for(i=0;i<12;i++){
        __delay_ms(50);
        LATB <<= 1;
    }
    
    init_i2c();
    init_OLED();
    
    // Etwas Text in den Framebuffer schreiben
    fb_draw_string_big(35,0,"FH KIEL");
    fb_draw_string_big(9,3,"OLED 128x64");
    // Logo in den Framebuffer schreiben
    fb_draw_BMP(10,0);
    fb_draw_string(15,6,"... und das ist kleiner Text!");
    // Den Framebuffer anzeigen
    fb_show();
      
    // kleine Animation mit maximaler Display refresh rate
    while(1){        
        for(i=0;i<128;i++){
            fb_drawPixel(i,63,1);
            fb_show();
        }
        for(i=63;i>42;i--){
            fb_drawPixel(127,i,1);
            fb_show();
        }
        for(i=127;i;i--){
            fb_drawPixel(i,42,1);
            fb_show();
        }
         for(i=42;i<63;i++){
            fb_drawPixel(0,i,1);
            fb_show();
        }
        for(i=0;i<128;i++){
            fb_drawPixel(i,63,0);
            fb_show();
        }
        for(i=63;i>42;i--){
            fb_drawPixel(127,i,0);
            fb_show();
        }
        for(i=127;i;i--){
            fb_drawPixel(i,42,0);
            fb_show();
        }
         for(i=42;i<63;i++){
            fb_drawPixel(0,i,0);
            fb_show();
         }
    }
    
    return 0;
}
