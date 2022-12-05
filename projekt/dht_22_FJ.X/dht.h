/*
 * File:   dht.h
 * Author: Julian
 *
 * Created on 28. November 2022, 17:59
 */

#ifndef DHT_H
#define DHT_H
extern int evalWakingData(short int *a_data, short int length);
extern int evalBit();
extern void startDHT22 (void);
extern int checkSensorReply(void);
extern void readData(int *data);

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif

#endif /* DHT_H */
