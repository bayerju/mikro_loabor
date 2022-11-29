#include "p33FJ128GP802.h"
#include "global_definitions.h"

int evalWakingData(short int *a_data, short int length) {
    #if DEBUG
    TRISBbits.TRISB4 = 0;
    #endif
    int i;
    short int counter_zero = 0;
    short int currentState = 1;
    for (i = 0; i < length; i++) {
        if (a_data[i] = 0) {
            counter_zero++;
            currentState = 0;
        }
        if (counter_zero >= 7 && data[i] == 1) {
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

int evalBit(int *dataPoints) {
    short int ones = 0;
    short int zeros = 0;
    short int counter = 0;
    if (dataPoints[counter] == 0) {

    }
    // make sure to start with a one
    while (dataPoints[counter] != NULL) {
        if (dataPoints[counter] == 1) break;
        counter++;
    }
    // eval Bit
    while (dataPoints[counter] != NULL) {
        // check if it is a 0
        if (ones >= 1 && dataPoints[counter] == 0) {
            return 0;
        }
        if (ones >= 5 && dataPoints[counter] == 0) {
            return 1;
        }
        if (dataPoints[counter] == 1) {
            ones++;
            counter++;
        }

        if (dataPoints[counter] == 0) {
            zeros++;
            counter++;
        }
    }
    return -1;
}
