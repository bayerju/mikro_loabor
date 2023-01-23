/**
 * @brief Initializes the global variables
 * 
 */

#include "global_definitions.h"

// sensor messuring
const short int MAX_DATA_ARRAY_LENGTH = 20;        // 200us
short int isMessuringSensorFlag = 0;               // Flag to start the sensor messuring
short int isWakingSensorFlag = 0;                  // Flag to start the sensor waking up
// short int data[MAX_DATA_ARRAY_LENGTH];
short int bitEvalData[12];                         // BUffer to evaluate the bits
short int measurementBits[40];                     // Buffer to store the bits

char tempString [20] = {0};                        // Buffer to store the temperature
char humString [20] = {0};                         // Buffer to store the humidity

float borderYellowHum = 60.0;
float borderRedHum = 70.0;
int data[40] = {0};
TFloatData sensorData = {0};
ErrorCodes currentErrorCode = NO_ERROR;

char errorMessage[30] = "";

void resetError() {
    strcpy(errorMessage, "NO_ERROR");
    currentErrorCode = NO_ERROR;
}

void throwError(ErrorCodes a_errorCode) {
    switch (a_errorCode) {
        case NO_ERROR:
            strcpy(errorMessage, "");
            currentErrorCode = NO_ERROR;
            break;
        case ERROR:
            strcpy(errorMessage, "ERROR");
            currentErrorCode = ERROR;
            break;
        case ERROR_NO_RESPONSE:
            strcpy(errorMessage, "ERROR_NO_RESPONSE");
            currentErrorCode = ERROR_NO_RESPONSE;
            break;
        case ERROR_CHECKSUM:
            strcpy(errorMessage, "ERROR_CHECKSUM");
            currentErrorCode = ERROR_CHECKSUM;
            break;
        case ERROR_TIMEOUT:
            strcpy(errorMessage, "ERROR_TIMEOUT");
            currentErrorCode = ERROR_TIMEOUT;
            break;
        case ERROR_UNKNOWN:
            strcpy(errorMessage, "ERROR_UNKNOWN");
            currentErrorCode = ERROR_UNKNOWN;
            break;
        default:
            strcpy(errorMessage, "ERROR_UNKNOWN");
            currentErrorCode = ERROR_UNKNOWN;
            break;
    }
}


