/*
 * File:   dht.h
 * Author: Julian
 *
 * Created on 28. November 2022, 17:59
 */

#ifndef DHT_H
#define DHT_H
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