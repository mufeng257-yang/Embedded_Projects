#include "encoder.h"
int volatile cout1=0;
int volatile cout2=0;
int volatile raw_cout1=0;
int volatile raw_cout2=0;
void encoder_init(void)
{
	NVIC_ClearPendingIRQ(GPIOB_INT_IRQn);
	NVIC_EnableIRQ(GPIOB_INT_IRQn);
}
int get_encoder_count(int e)
{
	if(e==1) return cout1;
	if(e==2) return cout2;
	return 0;
}
void encoder_update(void)
{
	cout1 = raw_cout1;
	cout2 = raw_cout2;
	raw_cout1= 0;
	raw_cout2= 0;
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
//		encoder_flag=1;
	}
}
