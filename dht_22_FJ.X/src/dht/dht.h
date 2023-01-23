/**
 * @file dht.h
 * @author Group DHT22
 * @brief Providing the DHT22 functions
 * @version 0.1
 * @date 2023-01-09
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef DHT_H
#define DHT_H

#include "global_definitions.h"

struct DataBytes  {
    int humByte1;
    int humByte2;
    int tempByte1;
    int tempByte2;
    int checksum;
    int *currentByte;
} ;

typedef struct DataBytes DataBytes;

struct FloatData {
    float temp;
    float hum;
} ;

typedef struct FloatData FloatData;

void startDHT22 (void);
void dataToString(int *data, char *tempString, char *humString, DataBytes *bytes, FloatData *floatData);
int isChecksumOk(DataBytes *bytes);
FloatData readData(int *data, char *tempString, char *humidityString);
int set_bit(int num, int position);
int getRecievedByte(int offset, int *data);
int evalBit();
int checkSensorReply(void);
int evalWakingData(short int *a_data, short int length);

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif

#endif /* DHT_H */