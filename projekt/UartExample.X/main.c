#include "xc.h"         	    // Einbinden der prozessor-spezifischen 
                                // Header-Datei
#include "defines.h"            // Einbinden der Prozessor defines
#include "init_device.h"        // Einbinden der init_device.c-spezifischen
                                // Header-Datei
#include "uart.h"                // Einbinden der init_device.c-spezifischen
                                // Header-Datei
#include "uart_dsPIC.h"         // Einbinden der init_device.c-spezifischen
                                // Header-Datei
#include <stdio.h>

int main (void)
{
    unsigned char data = 0;
    unsigned long int i;
    unsigned char str_data[]="Hallo World\r";
    unsigned char str_buf[20];
    int AnyInt = 530;
    float AnyFloat = 7.456;
    
    init_ports();               // Setup Port Pins
    init_oscillator();
    CommConfig();               // Configure UART1
    CommInit();
    CommEnable();               // Enable UART1
    
    // Welcome string
    CommPutString(str_data);
    for (i=0;i<100000;i++);
    
    // Output an Integer
    sprintf(str_buf,"%d\r",AnyInt);
    CommPutString(str_buf);
    
    // Output a Float
    sprintf(str_buf,"%f\r",AnyFloat);
    CommPutString(str_buf);
    
    // Use sscanf to convert a string to a number
    // sscanf(str_num, "%d", &AnyNum); //str_num contains the string
                                    // AnyNum will hold the converted number
	while (1)				    // Endless loop
	{
        if (CommIsEmpty() != 1){  // Echo of RX
            data = CommGetChar();
            CommPutChar(data);
        }
        
        for (i=0;i<200000;i++);
    
	}

    return 0;
}
