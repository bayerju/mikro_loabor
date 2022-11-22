/*
 * File:   init_device.c
 * Author: MarvinK
 * Created on 11. November 2022, 16:49
 */

#include "xc.h"
#include <stdio.h>

void init_oscillator (void){
    PLLFBDbits.PLLDIV = 78;         //siehe Main Datei für Berechnung
    CLKDIVbits.PLLPOST = 1;
    CLKDIVbits.PLLPRE = 0;
    
    __builtin_write_OSCCONH(0x3);     //PRI oscillatior mit PLL
    __builtin_write_OSCCONL(0x1);      //Set OSWN
    
    while(OSCCONbits.COSC != 0b011);    //Warten bis PLL neuer Oszillator wird
    while(OSCCONbits.LOCK != 1);        //Warten bis PLL gelocked ist
}

void port_init(void){               //Einstellung der Ports die Benutzt werden
    TRISBbits.TRISB15 = 1;          //Input Port für die Analoge SPannung
    
    TRISBbits.TRISB5 = 0;           //Setzten der Ouput Ports 5 - 12
    TRISBbits.TRISB6 = 0;
    TRISBbits.TRISB7 = 0;
    TRISBbits.TRISB8 = 0;
    TRISBbits.TRISB9 = 0;
    TRISBbits.TRISB10 = 0;
    TRISBbits.TRISB11 = 0;
    TRISBbits.TRISB12 = 0; 
    
    TRISBbits.TRISB13 = 0;          //Ausgabe Port für die PWM einheit
    
    TRISBbits.TRISB14 = 0;          //Port für die Bestimmung der Tatsächlichen Frequenz  
    
    AD1PCFGL = 0xFFFF;              //Setzten der Analog pins als Digital
}

void initPwm() {
    OC1CONbits.OCM = 0b000;
    OC1R = 100;
    OC1RS = 500;
    OC1CONbits.OCTSEL = 0;
    OC1CONbits.OCM = 0b110;
    RPOR6bits.RP13R = 18;
    
    T2CONbits.TON = 0;
    T2CONbits.TCS = 0;
    T2CONbits.TGATE = 0;
    T2CONbits.TCKPS = 0b00;
    TMR2 = 0x00;
    PR2 = 500;
      
    IPC1bits.T2IP = 0x01;
    IFS0bits.T2IF = 0;
    IEC0bits.T2IE = 1;
    T2CONbits.TON = 1;      
}