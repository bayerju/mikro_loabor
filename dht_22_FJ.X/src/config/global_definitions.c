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

float borderRedHum = 70.0;
float borderYellowHum = 60.0;

FloatData dataValues;
