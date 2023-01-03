/*
 * File:   global_definitions.h
 * Author: Julian
 *
 * Created on 28. November 2022, 17:19
 */

#ifndef GLOBAL_DEFINITIONS_H
#define GLOBAL_DEFINITIONS_H

#define DHT_PIN PORTBbits.RB5 // von RB15 auf RB2 stellen da runtergezogen
#define FCY 40000000 // 80MHz -> 40MHz Befehlstakt
#define VALUE_10us 0.00001 // 1us
// VALUE_10us/(1/(FCY/2))
#define step_10us 400;

#include <xc.h>
#include <libpic30.h>

extern short int
    isWakingSensorFlag; // löst die Messung und das Aufwachen des Sensors aus
extern short int
    isMessuringSensorFlag; // löst die Messung der Daten des Sensors aus
extern const short int MAX_DATA_ARRAY_LENGTH;
// extern short int data[];
extern short int bitEvalData[];
extern short int measurementBits[];
#define DEBUG 1

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif

#endif /* GLOBAL_DEFINITIONS_H */