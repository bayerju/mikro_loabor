/**
 * @file OLED.h
 * @author Group DHT22
 * @source Jan Haffmueller
 * @brief Providing the OLED functions
 * @version 0.1
 * @date 2023-01-09
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef OLED_H
#define	OLED_H

#include "global_definitions.h"

//*******************************************************************************
// SSD1306 Register Map
#define SSD1306_DEFAULT_ADDRESS     0x78	// 0x7A Konfigurierbar
#define SSD1306_SETCONTRAST         0x81
#define SSD1306_DISPLAYALLON_RESUME 0xA4
#define SSD1306_DISPLAYALLON        0xA5
#define SSD1306_NORMALDISPLAY       0xA6
#define SSD1306_INVERTDISPLAY       0xA7
#define SSD1306_DISPLAYOFF          0xAE
#define SSD1306_DISPLAYON           0xAF
#define SSD1306_SETDISPLAYOFFSET    0xD3
#define SSD1306_SETCOMPINS          0xDA
#define SSD1306_SETVCOMDETECT       0xDB
#define SSD1306_SETDISPLAYCLOCKDIV  0xD5
#define SSD1306_SETPRECHARGE        0xD9
#define SSD1306_SETMULTIPLEX        0xA8
#define SSD1306_SETLOWCOLUMN        0x00
#define SSD1306_SETHIGHCOLUMN       0x10
#define SSD1306_SETSTARTLINE        0x40
#define SSD1306_MEMORYMODE          0x20
#define SSD1306_COLUMNADDR          0x21
#define SSD1306_PAGEADDR            0x22
#define SSD1306_COMSCANINC          0xC0
#define SSD1306_COMSCANDEC          0xC8
#define SSD1306_SEGREMAP            0xA0
#define SSD1306_CHARGEPUMP          0x8D
#define SSD1306_SWITCHCAPVCC        0x02
#define SSD1306_NOP                 0xE3

#define SSD1306_WIDTH               128
#define SSD1306_HEIGHT              64

#define SSD1306_BUFFERSIZE (SSD1306_WIDTH*SSD1306_HEIGHT)/8 // it is devided by 8 because there are 8 pixels per byte

//*******************************************************************************
// global variables
extern uint8_t framebuffer[SSD1306_BUFFERSIZE];

//*******************************************************************************
// funktion prototypes

void init_OLED(void);
void OLED_sendFramebuffer(uint8_t *framebuffer);
void OLED_invert(uint8_t inverted);
void OLED_sendCommand(uint8_t command);
void OLED_sendData(uint8_t a_data);

void fb_drawPixel(uint8_t pos_x, uint8_t pos_y, uint8_t pixel_status);
void fb_drawVLine(uint8_t x, uint8_t y, uint8_t length);
void fb_drawHLine(uint8_t x, uint8_t y, uint8_t length);
void fb_drawRectangle(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint8_t fill);
void fb_clear();
void fb_clear_string_area(uint8_t row, uint8_t x1, uint8_t x2);
void fb_invert(uint8_t status);
void fb_show();
void fb_show_bmp(uint8_t *pBmp);
void fb_draw_char (uint16_t x, uint16_t y, uint16_t fIndex);
void fb_draw_string (uint16_t x, uint16_t y, const char *pS);
void fb_draw_one_line_string ( uint8_t x, uint8_t row, const char *pS);

void fb_draw_string_big (uint16_t x, uint16_t y, const char *pS);
void fb_draw_BMP (uint16_t x, uint16_t y);
void oled_draw(const char *tempString, const char *humString);

#endif	// OLED_H
