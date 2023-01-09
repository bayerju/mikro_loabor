
#ifndef AMPEL_H
#define AMPEL_H
#include "../config/global_definitions.h"

#define GELB LATBbits.LATB13
#define GRUEN LATBbits.LATB14
#define ROT LATBbits.LATB15

void setAmpel(float currentValue, float boarderRed, float borderYellow);

#ifdef __cplusplus
extern "C"
{
#endif

#ifdef __cplusplus
}
#endif

#endif /* DHT_H */