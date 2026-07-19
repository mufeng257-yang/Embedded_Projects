#ifndef _ENCODER_H_
#define _ENCODER_H_
#include "ti_msp_dl_config.h"
extern int volatile cout1;
extern int volatile cout2;
extern int volatile raw_cout1;
extern int volatile raw_cout2;
extern int encoder_flag;
void TIMER_ENCODER_init(void);
void encoder_init(void);
#endif