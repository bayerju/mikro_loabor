
#ifndef TIMER_H
#define TIMER_H
extern void T3_setup(void);
extern short isMessuringSensorFlag; // l�st die Messung des Sensors aus
extern void __attribute__((interrupt, no_auto_psv)) _T3Interrupt(void);

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif

#endif /* TIMER_H */