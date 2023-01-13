/**
 * @file OLED.c
 * @author Group DHT22
 * @ source Jan Haffmueller
 * @brief Initializing the OLED
 * @version 0.1
 * @date 2023-01-09
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "font.h"
#include "logo.h"
#include "i2c_routines.h"
#include "OLED.h"

// Framebuffer
uint8_t framebuffer[SSD1306_BUFFERSIZE];	// global array with entire display content.
											// Framebuffer is processed in the functions and then
											// sent completely for display with fb_show().

void init_OLED(void)
{
    // Display off
    OLED_sendCommand(SSD1306_DISPLAYOFF);

    OLED_sendCommand(SSD1306_SETDISPLAYCLOCKDIV);
    OLED_sendCommand(0x80);

    OLED_sendCommand(SSD1306_SETMULTIPLEX);
    OLED_sendCommand(0x3F);
    
    OLED_sendCommand(SSD1306_SETDISPLAYOFFSET);
    OLED_sendCommand(0x00);
    
    OLED_sendCommand(SSD1306_SETSTARTLINE | 0x00);
    
    // We use internal charge pump
    OLED_sendCommand(SSD1306_CHARGEPUMP);
    OLED_sendCommand(0x14);
    
    // Horizontal memory mode
    OLED_sendCommand(SSD1306_MEMORYMODE);
    OLED_sendCommand(0x00);
    
    OLED_sendCommand(SSD1306_SEGREMAP | 0x01);

    OLED_sendCommand(SSD1306_COMSCANDEC);

    OLED_sendCommand(SSD1306_SETCOMPINS);
    OLED_sendCommand(0x12);

    // Max contrast
    OLED_sendCommand(SSD1306_SETCONTRAST);
    OLED_sendCommand(0xCF);

    OLED_sendCommand(SSD1306_SETPRECHARGE);
    OLED_sendCommand(0xF1);

    OLED_sendCommand(SSD1306_SETVCOMDETECT);
    OLED_sendCommand(0x40);

    OLED_sendCommand(SSD1306_DISPLAYALLON_RESUME);

    // Non-inverted display
    OLED_sendCommand(SSD1306_NORMALDISPLAY);

    // Display on
    OLED_sendCommand(SSD1306_DISPLAYON);
}

//*******************************************************************************
// Transmitting a command to the OLED display

void OLED_sendCommand(uint8_t command)
{
    I2C_start(SSD1306_DEFAULT_ADDRESS);
 	I2C_write(0x00);
    I2C_write(command);
 	I2C_stop();
}

//*******************************************************************************
// Inversion of the OLED display

void OLED_invert(uint8_t inverted)
{
    if (inverted){
        OLED_sendCommand(SSD1306_INVERTDISPLAY);
    }
    else{
        OLED_sendCommand(SSD1306_NORMALDISPLAY);
    }
}

//*******************************************************************************
// Transferring the frame buffer to the OLED display

void OLED_sendFramebuffer(uint8_t *framebuffer)
{
    uint8_t packet = 0;
	uint8_t packet_byte = 0;
	
	OLED_sendCommand(SSD1306_COLUMNADDR);
    OLED_sendCommand(0x00);
    OLED_sendCommand(0x7F);

    OLED_sendCommand(SSD1306_PAGEADDR);
    OLED_sendCommand(0x00);
    OLED_sendCommand(0x07);

    // We have to send the framebuffer as 16 bytes packets
    // Our framebuffer is 1024 bytes long, 1024/16 = 64
    // We have to send 64 packets
    
    for (packet = 0; packet < 64; packet++){
		I2C_start(SSD1306_DEFAULT_ADDRESS);
        
        I2C_write(0x40);
		
        for (packet_byte = 0; packet_byte < 16; ++packet_byte){
			I2C_write(framebuffer[packet*16+packet_byte]);
        }
        
		I2C_stop();
    }
}

//*******************************************************************************
// Draw a pixel into the frame buffer at the position (pos_x|pos_y).
// Set the pixel with pixel_status = 1, delete with pixel_status = 0

void fb_drawPixel(uint8_t pos_x, uint8_t pos_y, uint8_t pixel_status)
{
    if (pos_x >= SSD1306_WIDTH || pos_y >= SSD1306_HEIGHT){
        return;
    }

    if (pixel_status){
        framebuffer[pos_x+(pos_y/8)*SSD1306_WIDTH] |= (1 << (pos_y&7));
    }
    else{
        framebuffer[pos_x+(pos_y/8)*SSD1306_WIDTH] &= ~(1 << (pos_y&7));
    }
}

//*******************************************************************************
// Draw a vertical line in the framebuffer of (x,y) length. 
// length.

void fb_drawVLine(uint8_t x, uint8_t y, uint8_t length)
{
    uint8_t i = 0;
	
	for (i = 0; i < length; ++i){
        fb_drawPixel(x, i+y, 1);
    }
}

//*******************************************************************************
// Draw a horizontal line in the framebuffer of (x|y) of length
// length.

void fb_drawHLine(uint8_t x, uint8_t y, uint8_t length)
{
    uint8_t i = 0;
	
	for (i = 0; i < length; ++i){
        fb_drawPixel(i+x, y, 1);
    }
}

//*******************************************************************************
// Draw a rectangle in the frame buffer from (x1|y1) to (x2|y2).
// The rectangle can be filled (1 = fill) or empty (0 = fill).

void fb_drawRectangle(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint8_t fill)
{
    uint8_t length = x2 - x1 + 1;
    uint8_t height = y2 - y1;
	int x = 0 , y = 0;
        
    if (!fill){
        fb_drawHLine(x1, y1, length);
        fb_drawHLine(x1, y2, length);
        fb_drawVLine(x1, y1, height);
        fb_drawVLine(x2, y1, height);
    }
    else{
        for (x = 0; x < length; ++x){
            for (y = 0; y <= height; ++y){
                fb_drawPixel(x1+x, y+y1, 1);
            }
        }
    }
}

//*******************************************************************************
// Delete the frame buffer

void fb_clear()
{
    uint16_t buffer_location = 0;
	
	for (buffer_location = 0; buffer_location < SSD1306_BUFFERSIZE; buffer_location++){
        framebuffer[buffer_location] = 0x00;
    }
}

//*******************************************************************************
// Invertiert the frame buffer

void fb_invert(uint8_t status)
{
    OLED_invert(status);
}

//*******************************************************************************
// Displaying the frame buffer on the OLED display

void fb_show()
{
    OLED_sendFramebuffer(framebuffer);
}

void fb_show_bmp(uint8_t *pBmp)
{
    OLED_sendFramebuffer(pBmp);
}

//*******************************************************************************
// Draw a character at position (x,y) - This function can only be called indirectly
// with the help of the function fb_draw_string, because it calculates the // corresponding index for the font vector! 
// corresponding index for the font vector!

void fb_draw_char (uint16_t x, uint16_t y, uint16_t fIndex)
{
    uint16_t bufIndex = (y << 7) + x;
    uint8_t j;
    
    for(j=0; j < font[fIndex]; j++){
        framebuffer[bufIndex + j] = font[fIndex + j + 1];
    }
}

//*******************************************************************************
// Draw a string from position (x,y)
// x: Start pixel 0...(127 character width)
// y: Line 0...7 (also with fb_draw_string_big)

void fb_draw_string (uint16_t x, uint16_t y, const char *pS)
{    
    uint16_t lIndex, k;
    
    while(*pS){
        // index the width information of character <c> 
        lIndex = 0;
        for(k=0; k < (*pS - ' '); k++){
            lIndex += (font[lIndex]) + 1;
        }
        
        // draw character
        fb_draw_char(x, y, lIndex);
        
        // move the cursor forward for the next character
        x += font[lIndex] + 1;
        
        // next charachter
        pS++;
    }
}

/**
 * @brief 
 * clears the whole row, which can be between 0 and 7
 * 
 * @param row 
 */
void fb_clear_string_row(uint8_t row) {
    uint8_t i;
    for(i=0; i<SSD1306_WIDTH; i++){
        framebuffer[(row << 7) + i] = 0;
    }

}

/**
 * @brief clears the hole row from x1 to the end of the row
 * 
 * @param row any value form 0 to 7
 * @param x1 starting value of x
 */
void fb_clear_string_row_from(uint8_t row, uint8_t x1) {
    fb_clear_string_area(row, x1, SSD1306_WIDTH);
}

/**
 * @brief 
 * clears the area of a string in a certain row starting from x1 to x2
 * 
 * @param x1 
 * @param y1 
 * @param x2 
 * @param y2 
 */
void fb_clear_string_area(uint8_t row, uint8_t x1, uint8_t x2) {
    uint8_t i;
    for(i=x1; i<x2; i++){
        framebuffer[(row << 7) + i] = 0;
    }
}

void fb_draw_string_big (uint16_t x, uint16_t y, const char *pS)
{
    uint8_t k;

    while(*pS){
        for(k=0; k<10; k++){
            framebuffer[( y    << 7) + x + k] = font2[*pS - ' '][k*2  ];
            framebuffer[((y+1) << 7) + x + k] = font2[*pS - ' '][k*2+1];
		}
        
        x += 10;
        
        // next charachter
        pS++;
    }    
}

/**
 * @brief implements same logic as fb_draw_string, but clears the row before drawing and when the row is full it starts again at x=0. 
 * This is why it does not work for texts, that take more than one row.
 * 
 * @param x 
 * @param row 
 * @param pS 
 */
void fb_draw_one_line_string( uint8_t x,uint8_t row, const char *pS) {
    fb_clear_string_row(row);
    
     uint16_t lIndex, k;
    
    while(*pS){
        // index the width information of character <c> 
        lIndex = 0;
        for(k=0; k < (*pS - ' '); k++){
            lIndex += (font[lIndex]) + 1; // +1 because the first byte is the width of the char
        }

        int maxX = 127 - font[lIndex] - 1; // max pixel in width - width of char - 1 safety pixel to the right.
    
        if (x > maxX) { // if the last char doesnt fit, start again at x=0 
            x = 0;
        }
        
        // draw character
        fb_draw_char(x, row, lIndex);
        
        // move the cursor forward for the next character
        x += font[lIndex] + 1;
        
        
        // next charachter
        pS++;
    }
}


//*******************************************************************************
void fb_draw_BMP (uint16_t x, uint16_t y)
{
    uint8_t k;
    for(k=0; k<10; k++){
		framebuffer[( y    << 7) + x + k] = FH_logo[0][k*2  ];
		framebuffer[((y+1) << 7) + x + k] = FH_logo[0][k*2+1];
    }
    
    x += 10;

    for(k=0; k<10; k++){
		framebuffer[( y    << 7) + x + k] = FH_logo[1][k*2  ];
		framebuffer[((y+1) << 7) + x + k] = FH_logo[1][k*2+1];
    }
 }

 void oled_draw(const char *tempString, const char *humString) {
        fb_clear();
        fb_draw_string(10,1,tempString);
        fb_draw_one_line_string(10,3,humString);
        fb_show();
 }
