#include "encoder.h"
int volatile coutA=0;
int volatile coutB=0;
int volatile raw_coutA=0;
int volatile raw_coutB=0;
void encoder_init(void)
{
	NVIC_ClearPendingIRQ(GPIOB_INT_IRQn);
	NVIC_EnableIRQ(GPIOB_INT_IRQn);
}
int get_encoder_count(int e)
{
	if(e==1) return coutA;
	if(e==2) return coutB;
	return 0;
}
void encoder_update(void)
{
	coutA = raw_coutA;
	coutB = raw_coutB;
	raw_coutA= 0;
	raw_coutB= 0;
}
void TIMER_ENCODER_init(void)
{

	NVIC_ClearPendingIRQ(TIMER_ENCODER_INST_INT_IRQN);
	NVIC_EnableIRQ(TIMER_ENCODER_INST_INT_IRQN);
}
int encoder_flag=0;
void TIMER_ENCODER_INST_IRQHandler(){

if( DL_TimerA_getPendingInterrupt(TIMER_ENCODER_INST) == DL_TIMER_IIDX_ZERO )
	{
		encoder_update();
	}
}
