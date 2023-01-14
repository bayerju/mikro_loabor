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

<<<<<<< HEAD
#define DHT_PIN PORTBbits.RB5                   // from RB15 to RB2 put down there
#define FCY 40000000                            // 80MHz -> 40MHz Command clock
#define VALUE_10us 0.00001                      // 1us
#define step_10us 400;                          // VALUE_10us/(1/(FCY/2))
=======
#define DHT_PIN PORTBbits.RB5 // von RB15 auf RB2 stellen da runtergezogen
#define FCY 40000000 // 80MHz -> 40MHz Befehlstakt = 40_000_000 this syntax only works in c++11 and later
#define VALUE_10us 0.00001 // 1us
// VALUE_10us/(1/(FCY/2))
#define step_10us 400;
>>>>>>> 71629cc3f02cbff3024491a89b0f7d11322384b5

/**
 * @brief Provision of the main libraries
 */
#include <libpic30.h>
#include "p33FJ128GP802.h"
#include <stdio.h>
<<<<<<< HEAD
#include <stdlib.h>
#include <xc.h>
=======
#include "ampel.h"
#include "dht.h"
>>>>>>> 71629cc3f02cbff3024491a89b0f7d11322384b5

#include "ampel.h"

<<<<<<< HEAD
extern short int isWakingSensorFlag;            // triggers the measurement and the wake-up of the sensor
extern short int isMessuringSensorFlag;         // triggers the measurement of the sensor's data
extern const short int MAX_DATA_ARRAY_LENGTH;   // maximum length of the data array

extern short int bitEvalData[];                 // array for the evaluation of the data
extern short int measurementBits[];             // array for the measurement of the data
extern float borrderRedHum;                     // border value for the red light
extern float borderYellowHum;                   // border value for the yellow light
extern char tempString [20];                    // string for the temperature
extern char humString [20];                     // string for the humidity
=======
extern short int bitEvalData[];
extern short int measurementBits[];
extern float borderRedHum;
extern float borderYellowHum;
extern char tempString [20];
extern char humString [20];
extern FloatData dataValues;
extern int data[];
>>>>>>> 71629cc3f02cbff3024491a89b0f7d11322384b5


#define DEBUG 1

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif

#endif /* GLOBAL_DEFINITIONS_H */