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

#define FCY 40000000                            // 80MHz -> 40MHz Command clock
#define VALUE_10us 0.00001                      // 1us
#define step_10us 400;                          // VALUE_10us/(1/(FCY/2))

// TODO: Screen shot 2
/**
 * @brief Provision of the main libraries
 */
#include <xc.h>
#include <libpic30.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// ErrorHandling
typedef enum ErrorCodes
{
    NO_ERROR,
    ERROR,
    ERROR_NO_RESPONSE,
    ERROR_CHECKSUM,
    ERROR_TIMEOUT,
    ERROR_UNKNOWN
} ErrorCodes;
extern enum errorCodes errorCodes;
extern ErrorCodes currentErrorCode;
extern char errorMessage[];
extern void throwError(ErrorCodes errorCode);
extern void resetError(void);


struct FloatData {
    float temp;
    float hum;
} ;

typedef struct FloatData TFloatData;

extern short int isWakingSensorFlag;            // triggers the measurement and the wake-up of the sensor
extern short int isMessuringSensorFlag;         // triggers the measurement of the sensor's data
extern const short int MAX_DATA_ARRAY_LENGTH;   // maximum length of the data array

extern short int bitEvalData[];                 // array for the evaluation of the data
extern short int measurementBits[];             // array for the measurement of the data
extern float borderRedHum;                     // border value for the red light
extern float borderYellowHum;                   // border value for the yellow light
extern char tempString [20];                    // string for the temperature
extern char humString [20];                     // string for the humidity
extern TFloatData sensorData;                    // struct for the data
extern int data[];                              // array for the data
extern char isReadingDataFlag;                  // flag for the reading of the data


// PINs
#define LED_RED_INIT TRISBbits.TRISB15
#define LED_YELLOW_INIT TRISBbits.TRISB12
#define LED_GREEN_INIT TRISBbits.TRISB14
#define DHT_PIN_INIT TRISBbits.TRISB5

#define LED_RED LATBbits.LATB15
#define LED_YELLOW LATBbits.LATB12
#define LED_GREEN LATBbits.LATB14
#define DHT_PIN PORTBbits.RB5


#define DEBUG 1

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif

#endif /* GLOBAL_DEFINITIONS_H */