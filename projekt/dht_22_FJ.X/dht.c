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
        printf("%d ", data[i]);
    }
    isWakingSensorFlag = 0;
    isMessuringSensorFlag = 0;
    #if DEBUG
    PORTBbits.RB4 = 1;
    #endif
    return -1;
}
