/**
 * @brief Initializes the global variables
 * 
 */

#include "global_definitions.h"

// sensor messuring
const short int MAX_DATA_ARRAY_LENGTH = 20;        // 200us
short int isMessuringSensorFlag = 0;
short int isWakingSensorFlag = 0;
// short int data[MAX_DATA_ARRAY_LENGTH];
short int bitEvalData[12];
short int measurementBits[40];

char tempString [20] = {0};
char humString [20] = {0};

float borderYellowHum = 40.0;
float borderRedHum = 50.0; // TODO: change to 60 and 70
int data[40] = {0};
FloatData dataValues;


char errorMessage[30] = {0};
void throwError(ErrorCodes a_errorCode) {
    switch (a_errorCode) {
        case NO_ERROR:
            strcpy(errorMessage, "NO_ERROR");
            break;
        case ERROR:
            strcpy(errorMessage, "ERROR");
            break;
        case ERROR_NO_RESPONSE:
            strcpy(errorMessage, "ERROR_NO_RESPONSE");
            break;
        case ERROR_CHECKSUM:
            strcpy(errorMessage, "ERROR_CHECKSUM");
            break;
        case ERROR_TIMEOUT:
            strcpy(errorMessage, "ERROR_TIMEOUT");
            break;
        case ERROR_UNKNOWN:
            strcpy(errorMessage, "ERROR_UNKNOWN");
            break;
        default:
            strcpy(errorMessage, "ERROR_UNKNOWN");
            break;
    }
}

void resolveError() {
    strcpy(errorMessage, "NO_ERROR");
}

