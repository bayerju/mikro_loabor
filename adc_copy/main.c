/*
 * File:   main.c
 * Author: MarvinK
 *
 * Created on 11. November 2022, 15:59
 * 5.5 
Schreiben Sie ein C- Programm, welches über AN9 (RB15) eine analoge Spannung im
Bereich von 0V ? Uin ? 3,3V einliest. Die Abtastfrequenz des Wandlers soll 4kHz
betragen (Auflösung des Wandlers 12Bit). Nach jeder Wandlung soll ein Interrupt
ausgelöst werden. Innerhalb der Interruptroutine soll nur das Einlesen der Spannung
erfolgen. In einem Unterprogramm erfolgt die Auswertung. Abhängig vom
eingelesenen Spannungswert sollen die oberen 4 Bit des abgetasteten Wertes
ausgewertet werden und ein 8-Bit Leuchtband an PortB [RB12?RB5] ausgegeben
werden (0V ? alle LEDs aus, 3,3V ? alle LEDs an).
Erzeugen Sie zusätzlich an Port B (RB13) mit der PWM- Einheit ein PWM- Signal.
Das Tastverhältnis in Abhängigkeit von dem eingelesenen Wandlerwert ist der Tabelle
zu entnehmen. Die PWM- Frequenz soll ebenfalls 4kHz betragen.
Integrieren Sie in das Programm eine Ausgabe an den Port B (RB14), welche es
ermöglicht eine Bestimmung der tatsächlichen Abtastfrequenz vorzunehmen.
 * 
 * AbtastFrequenz = 4kHz
 * 12 Bit Wandler
 * Abtasterate = 4 kHz --> T(abtast) = 1/4 kHz = 0,25 milli s
 * Befehlstakt wird gewählt ald FCY = 20 MHz
 * Primary Oscillator = 4 MHz
 * --> TCY = 50ns; 
 *  PR3 = T(abtast)/TCY - 1 = ((0,25 milli s) / (50 ns)) -1 = 4999
 * -----------------------------------------------------------------------------
 * Internal ADC clock: FAD = 4 MHz --> TAD = 250 ns
 * sampling + conversion time (10 - bit): TSC = 14 * TAD = 14 * 250 ns = 3,5 micro s
 * --> Tabtast = 0,25 milli s > 3,5 micro s
 * -----------------------------------------------------------------------------
 * PLL 
 * Befehlstakt FCY = 20 MHz --> FOSC = 40 MHz
 * FIN = 4 MHz --> N = 2 --> PLLPRE = 0
 * FREF = 2 MHz 
 * FOSC = 40 MHz --> FVCO = 160 MHz --> PLLPOST=1
 * M = FVCO / FREF = 160 MHz /2 MHz --> PLLDIV = 80 - 2 = 78
 * PLLPOST= 1
 * PLLPRE = 0
 * PLLDIV = 78
 */


#include "xc.h"
#include "config.h"
#include "init_device.h"
#include "Timer.h"
#include "adc.h"

#define ON 1
#define OFF 0

void setPwm(int percentage) {
    OC1RS = percentage*5;
}

void setPinB(int pinNumber, int level) {    
    switch(pinNumber) {
        case 0:
            LATBbits.LATB0 = level;
            break;
        case 1:
            LATBbits.LATB1 = level;
            break;
        case 2:
            LATBbits.LATB2 = level;
            break;
        case 3:
            LATBbits.LATB3 = level;
            break;
        case 4:
            LATBbits.LATB4 = level;
            break;
        case 5:
            LATBbits.LATB5 = level;
            break;
        case 6:
            LATBbits.LATB6 = level;
            break;
        case 7:
            LATBbits.LATB7 = level;
            break;
        case 8:
            LATBbits.LATB8 = level;
            break;
        case 9:
            LATBbits.LATB9 = level;
            break;
        case 10:
            LATBbits.LATB10 = level;
            break;
        case 11:
            LATBbits.LATB11 = level;
            break;
        case 12:
            LATBbits.LATB12 = level;
            break;
        case 13:
            LATBbits.LATB13 = level;
            break;
        case 14:
            LATBbits.LATB14 = level;
            break;
        case 15:
            LATBbits.LATB15 = level;
            break;
    }
}
    
int main(void) {
    
    //Initialisierung aller Komponenten
    port_init();
    init_oscillator();
    adc_init();
    T3_init();
    
    adc_start();
    T3_start();
    initPwm();
    
    while(1){
        switch(adcValue>>8) {
            case 0x0:
            case 0x1:
            case 0x2:
                setPwm(5);
                setPinB(5, 0);
                setPinB(6, 0);
                setPinB(7, 0);
                setPinB(8, 0);
                setPinB(9, 0);
                setPinB(10, 0);
                setPinB(11, 0);
                setPinB(12, 0);
                break;
            case 0x3:
            case 0x4:
                setPwm(10);
                setPinB(5, 1);
                setPinB(6, 0);
                setPinB(7, 0);
                setPinB(8, 0);
                setPinB(9, 0);
                setPinB(10, 0);
                setPinB(11, 0);
                setPinB(12, 0);
                break;
            case 0x5:
            case 0x6:
                setPwm(20);
                setPinB(5, 1);
                setPinB(6, 1);
                setPinB(7, 0);
                setPinB(8, 0);
                setPinB(9, 0);
                setPinB(10, 0);
                setPinB(11, 0);
                setPinB(12, 0);
                break;
            case 0x7:
                setPwm(40);
                setPinB(5, 1);
                setPinB(6, 1);
                setPinB(7, 1);
                setPinB(8, 0);
                setPinB(9, 0);
                setPinB(10, 0);
                setPinB(11, 0);
                setPinB(12, 0);
                break;
            case 0x8:
                setPwm(50);
                setPinB(5, 1);
                setPinB(6, 1);
                setPinB(7, 1);
                setPinB(8, 1);
                setPinB(9, 0);
                setPinB(10, 0);
                setPinB(11, 0);
                setPinB(12, 0);
                break;
            case 0x9:
                setPwm(60);
                setPinB(5, 1);
                setPinB(6, 1);
                setPinB(7, 1);
                setPinB(8, 1);
                setPinB(9, 1);
                setPinB(10, 0);
                setPinB(11, 0);
                setPinB(12, 0);
                break;
            case 0xA:
                setPwm(80);
                setPinB(5, 1);
                setPinB(6, 1);
                setPinB(7, 1);
                setPinB(8, 1);
                setPinB(9, 1);
                setPinB(10, 1);
                setPinB(11, 0);
                setPinB(12, 0);
                break;
            case 0xB:
                setPwm(90);
                setPinB(5, 1);
                setPinB(6, 1);
                setPinB(7, 1);
                setPinB(8, 1);
                setPinB(9, 1);
                setPinB(10, 1);
                setPinB(11, 1);
                setPinB(12, 0);
                break;
            case 0xC:
            case 0xD:
            case 0xE:
            case 0xF:
                setPwm(100);
                setPinB(5, 1);
                setPinB(6, 1);
                setPinB(7, 1);
                setPinB(8, 1);
                setPinB(9, 1);
                setPinB(10, 1);
                setPinB(11, 1);
                setPinB(12, 1);
                break;
        }
        
        
        
        
       } 
    return 0;
}
