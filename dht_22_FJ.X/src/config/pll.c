/**
 * @file pll.c
 * @author Group DHT22
 * @brief Initializes the PLL
 * @version 0.1
 * @date 2023-01-09
 * 
 * @copyright Copyright (c) 2023
 * 
 */
    
    void setup_pll() {
            
    PLLFBDbits.PLLDIV = 78;             // set plldiv to 78
    
    CLKDIVbits.PLLPOST = 0;             // set pllpost to 0
    
    CLKDIVbits.PLLPRE = 0;              // set pllpres to 0

    __builtin_write_OSCCONH(0x03);
    __builtin_write_OSCCONL(0x01);

    while (OSCCONbits.COSC != 0b011);   // Wait for Clock switch to occur
    while (OSCCONbits.LOCK != 1);       // Wait for PLL to lock
    }
