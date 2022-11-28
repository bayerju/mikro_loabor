/*
 * File:   global_definitions.h
 * Author: Julian
 *
 * Created on 28. November 2022, 17:19
 */

#ifndef GLOBAL_DEFINITIONS_H
#define GLOBAL_DEFINITIONS_H

extern short int
    isWakingSensorFlag; // löst die Messung und das Aufwachen des Sensors aus
extern short int
    isMessuringSensorFlag; // löst die Messung der Daten des Sensors aus
extern short int MAX_DATA_ARRAY_LENGTH;
extern short int data[];
#define DEBUG 1

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif

#endif /* GLOBAL_DEFINITIONS_H */
