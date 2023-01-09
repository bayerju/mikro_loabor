
// #include "p33FJ128GP802.h"
#include <xc.h>
#include "../config/global_definitions.h"
#include <stdio.h>
// #include "timerstartvs.h"
#include "dht.h"
#include <libpic30.h>

/**
 * @brief Reads the data from the DHT22 sensor.
 * Starts the sensor
 */
void startDHT22(void){
    TRISBbits.TRISB5 = 0;
    PORTBbits.RB5 = 0;
    __delay_ms(2);                  // As a start signal, the DHT22 must pull the signal from the host to 0 for at least 1ms
    PORTBbits.RB5 = 1;
    TRISBbits.TRISB5 = 1;
}

void dataToString(int *data, char *tempString, char *humString, DataBytes *bytes, FloatData *floatData) {
    int temp = 0, hum = 0; 
    float tempFloat = 0, humFloat = 0;

    if (isChecksumOk(bytes) == 0) {
        sprintf(tempString, "Checksum Error");
        sprintf(humString, "Checksum Error");
        return;
    }

    temp = (bytes->tempByte1 << 8) + bytes->tempByte2;
    tempFloat = (float)temp/10;
    hum = (bytes->humByte1 << 8) + bytes->humByte2;
    humFloat = (float)hum/10;

    sprintf(tempString, "Temperature: %.1f", (double)floatData->temp); // converted to double, because printf converts it anyway and now there is no warning and it is clear what is happening.
    sprintf(humString, "Humidity: %.1f", (double)floatData->hum);   
}

int isChecksumOk(DataBytes *bytes) {
    int sum = bytes->humByte1 + bytes->humByte2 + bytes->tempByte1 + bytes->tempByte2;
    int low8Bits = sum & 0xFF;

    if (bytes->checksum == low8Bits) {
        return 1;
    } else {
        return 0;
    }
}



FloatData readData(int *data, char *tempString, char *humidityString) {
    int counterBits = 0;
    FloatData dataValues;
    int isAnswerOk = checkSensorReply();
    if (isAnswerOk == 0){ // all good start reading
        int bit = -1;
        while (DHT_PIN == 1 && TMR3 < 4000); // wait up to 100us;
        while (counterBits < 40){
            bit = evalBit();
            if (bit == -1)
                // TODO: add error handling
                return dataValues;
            data[counterBits] = bit;
            counterBits++;
        }
    }

    DataBytes recievedBytes;
    recievedBytes.currentByte = &recievedBytes.humByte1;

    int i;
    for (i = 0; i < 5; i++) {
        *recievedBytes.currentByte = getRecievedByte(i*8, data);
        recievedBytes.currentByte++;
    }
    recievedBytes.currentByte = &recievedBytes.humByte1;

    dataValues.temp = ((float)(recievedBytes.tempByte1 << 8) + recievedBytes.tempByte2)/10;
    dataValues.hum = ((float)(recievedBytes.humByte1 << 8) + recievedBytes.humByte2)/10;
    dataToString(data, tempString, humidityString, &recievedBytes, &dataValues);
    return dataValues;
}

/**
 * @brief Sets a bit in the int num at position t 1.
 * SRC: https://hackernoon.com/bit-manipulation-in-c-and-c-1cs2bux
 * 
 * @param num 
 * @param position 
 * @return int 
 */
int set_bit(int num, int position) {
	int mask = 1 << position;
	return num | mask;
}

/**
 * @brief Get the Recieved Byte from the data  Pointer starting at the offset and returns it as int.
 * 
 * @param offset 
 * @param data 
 * @return int 
 */
int getRecievedByte(int offset, int *data) {
    int byte = 0;
    int i = 0;
    for (i = 0 ; i < 8; i++) {
        if (data[i + offset] == 1) {
            byte = set_bit(byte, 7-i);
        }
    }
    return byte;
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
    else if (time > 2000 && time < 4000){ // 50us *400 && 100us * 400 // TODO:timeout is at 3000 and one is up to 4000
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

/**
 * @brief evaluates the data from the sensor and returns 0 if the sensor is waking up and -1 if it is not.
 * 
 * @param a_data 
 * @param length 
 * @return int 
 */
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
