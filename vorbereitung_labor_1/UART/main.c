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
    
    while(1) {
        if (CommIsEmpty() != 1){  // Echo of RX
            CommPutString("Julian\r");
            for(i=0;i<100000;i++);
        }
    }

    return 0;
}
