/**
 * @file dht.c
 * @author Group DHT22
 * @brief Initializing the DHT22 sensor
 * @version 0.1
 * @date 2023-01-09
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "dht.h"

/**
 * @brief Starts the sensor
 */
void startDHT22(void){
    TRISBbits.TRISB5 = 0;
    PORTBbits.RB5 = 0;
    __delay_ms(2);                  // As a start signal, the DHT22 must pull the signal from the host to 0 for at least 1ms
    PORTBbits.RB5 = 1;
    TRISBbits.TRISB5 = 1;
}

/**
 * @brief Datas from the sensor are inserted into an string
 * @return int 
 */
void dataToString(int *data, char *tempString, char *humString, DataBytes *bytes, TFloatData *floatData) {
    int temp = 0, hum = 0; 
    float tempFloat = 0, humFloat = 0;

    /**
     * @brief Checks whether an error occurs in the
     * checksum and then outputs an error text
     * 
     */
    if (isChecksumOk(bytes) != 0) {
        throwError(ERROR_CHECKSUM);
        return;
    }

    temp = (bytes->tempByte1 << 8) + bytes->tempByte2;                  // Bit shifting is used to convert the data from the sensor into integer values that can be further processed.     
    tempFloat = (float)temp/10;                                         // convert the integer to a float
    hum = (bytes->humByte1 << 8) + bytes->humByte2;                     // Bit shifting is used to convert the data from the sensor into integer values that can be further processed.
    humFloat = (float)hum/10;                                           // convert the integer to a float

    sprintf(tempString, "Temperature: %.1f", (double)floatData->temp); // converted to double, because printf converts it anyway and now there is no warning and it is clear what is happening.
    sprintf(humString, "Humidity: %.1f", (double)floatData->hum);   
}

/**
 * @brief Compares the sum of the bits of the
 * temperature and humidity data with the checksum.
 * 
 * @param bytes 
 * @return int 
 */
int isChecksumOk(DataBytes *bytes) {
    int sum = bytes->humByte1 + bytes->humByte2 + bytes->tempByte1 + bytes->tempByte2;
    int low8Bits = sum & 0xFF;

    /**
     * @brief If the checksum is correct, the function returns 1
     * 
     */
    if (bytes->checksum == low8Bits) {
        return 0;
    } else {
        return -1;
    }
}

/**
 * @brief Reads the data from the sensor and stores it in an array. 
 * 
 * @param data 
 * @param tempString 
 * @param humidityString 
 * @return TFloatData 
 */
// TODO: Screen shot 3
int readData(int *data, char *tempString, char *humidityString) {
    int counterBits = 0;
    TMR3 = 0;
    startDHT22();
    TMR3 = 0;
    int isAnswerOk = checkSensorReply();
    if (isAnswerOk != 0) {
        throwError(ERROR_NO_RESPONSE);
        return -1;
    }
    if (isAnswerOk == 0) {                                   // all good start reading
        resolveError();
        int bit = -1;
        while (DHT_PIN == 1 && TMR3 < 4000);                // wait up to 100us;
        // TODO: change to gated timer from here on or just use different timer that is gated
        while (counterBits < 40){
            bit = evalBit();
            if (bit == -1) {
                throwError(ERROR_TIMEOUT); // TODO: new error for bit not recognized
                return -1;
            }

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

    sensorData.temp = ((float)(recievedBytes.tempByte1 << 8) + recievedBytes.tempByte2)/10;
    sensorData.hum = ((float)(recievedBytes.humByte1 << 8) + recievedBytes.humByte2)/10;
    dataToString(data, tempString, humidityString, &recievedBytes, &sensorData);
    return 0;
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
 * @brief Get the Recieved Byte from the data  Pointer starting at the
 * offset and returns it as int.
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
 * @brief sorts the bits
 * 
 * @return int -1 for failure, 1 for a 1 and 0 for a 0
 */
int evalBit() {
    int prevPin = 0;
    PORTBbits.RB9 = 1;
    TMR3 = 0;
    while(DHT_PIN == 0 && TMR3 < 3000);     // wait up to 75us;
    PORTBbits.RB9 = 0;
    if (TMR3 > 3000) {
        TMR3 = 0;
        return -1;
    }
    while(DHT_PIN == 1){
        if(DHT_PIN == 1 && prevPin == 0){   // wait for pin to go to 0;
            TMR3 = 0;
            prevPin = 1;
        }
    }
    int time = TMR3;
    if (time > 600 && time < 2000){         // 15us * 400 && 50us * 400
        TMR3 = 0;
        return 0;
    }
    else if (time > 2000 && time < 4000){   // 50us *400 && 100us * 400 // TODO:timeout is at 3000 and one is up to 4000
        TMR3 = 0;
        return 1;
    }
    else {
        TMR3 = 0;
        return -1;
    }
}

/**
 * @brief check the sensor reply
 * 
 * @return int 0 if the check was ok and 1 if it wasnt
 */
int checkSensorReply() {
    // 400 is 10 us (step_10us) and 12 to wait 80us+20 to 40us
    int maxTime = 4800; // 400*12
    int prevValue = 1;

    /**
     * @brief Wait for the sensor replay
     * 
     */
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
                if (timeStayedZero > 2800 && timeStayedZero < 3600) { // between 70 and 90 us // 1/40E6 = 25E-9 70E-6/25E-9 = 2800
                    TMR3 = 0;
                    return 0;
                    break;
                } else {
                    throwError(ERROR_NO_RESPONSE);
                    return -1;
                }
        } 
    }
    return 1;
}

/**
 * @brief evaluates the data from the sensor and returns 0 if the sensor
 * is waking up and -1 if it is not.
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
