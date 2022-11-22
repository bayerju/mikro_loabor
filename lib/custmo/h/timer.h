#ifndef TIMER_H
#define TIMER_H
extern void T3_init(void);
extern void T3_start(void);
extern void T3_stop(void);
extern void __attribute__((__interrupt__, no_auto_psv)) _T1Interrupt(void);
#endif