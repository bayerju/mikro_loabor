// #include "p33FJ128GP802.h"
#include <xc.h>
#include "../config/global_definitions.h"
#include <stdio.h>
// #include "timerstartvs.h"
#include "dht.h"
#include <libpic30.h>

void startDHT22(void){
    TRISBbits.TRISB5 = 0;
    PORTBbits.RB5 = 0;
    __delay_ms(2);
    PORTBbits.RB5 = 1;
    TRISBbits.TRISB5 = 1;
    //Setup_T1();
}


int splitDataArray(short int *a_data, short int length){
    
    // int i;
    // for (i = 0; i < length; i++) {
    //     if (i < 8) {
    //         bitEvalData[i] = a_data[i];
    //     } else {
    //         measurementBits[i-8] = a_data[i];
    //     }
    // }
    return 0;
}

int readData(int *data) {
    int counterBits = 0;
    int isAnswerOk = checkSensorReply();
    if (isAnswerOk == 0){ // all good start reading
        int bit = -1;
        while (DHT_PIN == 1 && TMR3 < 4000); // wait up to 100us;
        while (counterBits < 40){
            bit = evalBit();
            if (bit == -1)
                return -1;
            data[counterBits] = bit;
            counterBits++;
        }
    }
    return 0;
}

/**
 * @brief 
 * 
 * @return int -1 for failure, 1 for a 1 and 0 for a 0
 */
int evalBit() {
    int prevPin = 0;
    PORTBbits.RB9 = 1;
    TMR3 = 0;
    while(DHT_PIN == 0 && TMR3 < 3000); // wait up to 75us;
    PORTBbits.RB9 = 0;
    if (TMR3 > 3000) {
        TMR3 = 0;
        return -1;
    }
    while(DHT_PIN == 1){
        if(DHT_PIN == 1 && prevPin == 0){ // wait for pin to go to 0;
            TMR3 = 0;
            prevPin = 1;
        }
    }
    int time = TMR3;
    if (time > 600 && time < 2000){ // 15us * 400 && 50us * 400
        TMR3 = 0;
        return 0;
    }
    else if (time > 2000 && time < 4000){ // 50us *400 && 100us * 400
        TMR3 = 0;
        return 1;
    }
    else {
        TMR3 = 0;
        return -1;
    }
}

/**
 * @brief 
 * 
 * @return int 0 if the check was ok and 1 if it wasnt
 */
int checkSensorReply() {
    // 400 is 10 us (step_10us) and 12 to wait 80us+20 to 40us
    int maxTime = 4800; // 400*12
    int prevValue = 1;
    //TRISBbits.TRISB5 = 0; hier wollten wir toggeln
    //PORTBbits.RB5  = 0;
    while (TMR3 < maxTime) {
        
        
        if (PORTBbits.RB5 == 1 && prevValue == 1) {
            continue;
        } 
        if (PORTBbits.RB5 == 0 && prevValue == 1) {
            TMR3 = 0;
            prevValue = 0;
            
        }

        if (PORTBbits.RB5 == 1 && prevValue == 0) {

                int timeStayedZero = TMR3;
                if (timeStayedZero > 2800 && timeStayedZero < 3600) { // zwischen 70 und 90 us // 1/40E6 = 25E-9 70E-6/25E-9 = 2800
                    TMR3 = 0;
                    return 0;
                    break;
                } else {
                    return -1;
                }
            // if (timeStayedZero > step_10us*50) {
            //     PORTBbits.RB14 = 1;
            // } else {
            //     PORTBbits.RB14 = 0;
            // }
            // prevValue = 1;
        } 
    }
    return 1;
}

int evalWakingData(short int *a_data, short int length) {
    #if DEBUG
    TRISBbits.TRISB4 = 0;
    #endif
    int i;
    short int counter_zero = 0;
    short int currentState = 1;
    for (i = 0; i < length; i++) {
        if (a_data[i] == 0) {
            counter_zero++;
            currentState = 0;
        }
        if (counter_zero >= 7 && a_data[i] == 1) {
            isWakingSensorFlag = 0;
            isMessuringSensorFlag = 1;
            return 0;
        }
    }
    isWakingSensorFlag = 0;
    isMessuringSensorFlag = 0;
    #if DEBUG
    PORTBbits.RB4 = 1;
    #endif
    return -1;
}

// /**
//  * @brief 
//  * 
//  * @param dataPoints 
//  * @return int 
//  */
// int evalBit(int *dataPoints) {
//     short int ones = 0;
//     short int zeros = 0;
//     short int counter = 0;
//     if (dataPoints[counter] == 0) {

//     }
//     // make sure to start with a one
//     while (dataPoints[counter] != NULL) {
//         if (dataPoints[counter] == 1) break;
//         counter++;
//     }
//     // eval Bit
//     while (dataPoints[counter] != NULL) {
//         // check if it is a 0
//         if (ones >= 1 && dataPoints[counter] == 0) {
//             return 0;
//         }
//         if (ones >= 5 && dataPoints[counter] == 0) {
//             return 1;
//         }
//         if (dataPoints[counter] == 1) {
//             ones++;
//             counter++;
//         }

//         if (dataPoints[counter] == 0) {
//             zeros++;
//             counter++;
//         }
//     }
//     return -1;
// }
