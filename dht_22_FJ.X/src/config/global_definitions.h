/**
 * @file global_definitions.h
 * @author Group DHT22
 * @brief Providing global definitions
 * @version 0.1
 * @date 2023-01-09
 * 
 * @copyright Copyright (c) 2023
 * 
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
#include "../ampel/ampel.h"

extern short int isWakingSensorFlag; // löst die Messung und das Aufwachen des Sensors aus
extern short int isMessuringSensorFlag; // löst die Messung der Daten des Sensors aus
extern const short int MAX_DATA_ARRAY_LENGTH;

extern short int bitEvalData[];
extern short int measurementBits[];
extern float borderRedHum;
extern float borderYellowHum;


#define DEBUG 1

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif

#endif /* GLOBAL_DEFINITIONS_H */