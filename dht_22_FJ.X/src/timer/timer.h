/**
 * @file timer.h
 * @author Group DHT22
 * @brief Providing the timer functions
 * @version 0.1
 * @date 2023-01-09
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef TIMER_H
#define TIMER_H
extern void T3_setup(void);
extern void enable_T3_interrupts(void);
extern void disable_T3_interrupts(void);
extern void enable_gate(void);
extern void disable_gate(void);
extern short isMessuringSensorFlag; // l�st die Messung des Sensors aus
extern void __attribute__((interrupt, no_auto_psv)) _T3Interrupt(void);

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif

#endif /* TIMER_H */