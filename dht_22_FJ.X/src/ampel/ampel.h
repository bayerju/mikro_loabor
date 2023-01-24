/**
 * @file ampel.h
 * @author Group DHT22
 * @brief Providing the traffic light functions
 * @version 0.1
 * @date 2023-01-09
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef AMPEL_H
#define AMPEL_H

#include "global_definitions.h"

extern void setAmpel(float currentValue, float borderRed, float borderYellow, int loopCounter_OLED);

#ifdef __cplusplus
extern "C"
{
#endif

#ifdef __cplusplus
}
#endif

#endif /* AMPEL_H */
