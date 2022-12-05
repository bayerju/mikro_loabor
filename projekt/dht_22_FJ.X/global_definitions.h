/*
 * File:   global_definitions.h
 * Author: Julian
 *
 * Created on 28. November 2022, 17:19
 */

#ifndef GLOBAL_DEFINITIONS_H
#define GLOBAL_DEFINITIONS_H

extern short int
    isWakingSensorFlag; // lÃ¶st die Messung und das Aufwachen des Sensors aus
extern short int
    isMessuringSensorFlag; // lÃ¶st die Messung der Daten des Sensors aus
extern const short int MAX_DATA_ARRAY_LENGTH;
extern short int data[];
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
