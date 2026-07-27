#include "ti_msp_dl_config.h"
#include "encoder.h"
#include "interrupt.h"
#include "clock.h"
#include "mpu6050.h"
#include "pid.h"
#include "motor.h"
#include "serial.h"
uint8_t enable_group1_irq = 0;
extern int A;
extern int B;
extern float Target_jiaodu;
extern float error_yaw;
int A_PWM=0;
int B_PWM=0;
void Interrupt_Init(void)
{
    if(enable_group1_irq)
    {
        NVIC_EnableIRQ(1);
    }
}

void SysTick_Handler(void)
{
    tick_ms++;
}
void TIMER_ENCODER_INST_IRQHandler(){

if( DL_TimerA_getPendingInterrupt(TIMER_ENCODER_INST) == DL_TIMER_IIDX_ZERO )
	{
		encoder_update();
//				float jiaodu_out=PID_Compute(&jiaoduhuan,Target_jiaodu,error_yaw);
		float Aspeed_out=PID_Compute(&Aspeedhuan,(float)A,(float)coutA);
		float Bspeed_out=PID_Compute(&Bspeedhuan,(float)B,(float)coutB);
		A_PWM+=Aspeed_out;
		B_PWM+=Bspeed_out;
		if(A_PWM>1000) A_PWM=1000;
		if(A_PWM<-1000) A_PWM=-1000;
		if(B_PWM>1000) B_PWM=1000;
		if(B_PWM<-1000) B_PWM=-1000;
		A_speed(A_PWM);
		B_speed(B_PWM);
		//printf("%d,%d,%d,%d\n",A_PWM,B_PWM,coutA,coutB);
	}
}

void GROUP1_IRQHandler(void)
{
	uint32_t gpio_status;

	gpio_status = DL_GPIO_getEnabledInterruptStatus(GPIO_MPU6050_PORT,GPIO_MPU6050_PIN_MPU6050_INT_PIN);
    
  if((gpio_status & GPIO_MPU6050_PIN_MPU6050_INT_PIN) == GPIO_MPU6050_PIN_MPU6050_INT_PIN){
				Read_Quad();

				DL_GPIO_clearInterruptStatus(GPIO_MPU6050_PORT,GPIO_MPU6050_PIN_MPU6050_INT_PIN);
    }

	gpio_status = DL_GPIO_getEnabledInterruptStatus(ENCODER_PORT,ENCODER_E1A_PIN | ENCODER_E1B_PIN |ENCODER_E2A_PIN|ENCODER_E2B_PIN);
	
	if((gpio_status & ENCODER_E1A_PIN) == ENCODER_E1A_PIN)
	{

		if(!DL_GPIO_readPins(ENCODER_PORT,ENCODER_E1B_PIN))
		{
			raw_coutA++;
		}
		else
		{
			raw_coutA--;
		}
	}
	else if((gpio_status & ENCODER_E1B_PIN)==ENCODER_E1B_PIN)
	{

		if(!DL_GPIO_readPins(ENCODER_PORT,ENCODER_E1A_PIN))
		{
			raw_coutA--;
		}
		else
		{
			raw_coutA++;
		}
	}
	
	
	if((gpio_status & ENCODER_E2A_PIN) == ENCODER_E2A_PIN)
	{

		if(!DL_GPIO_readPins(ENCODER_PORT,ENCODER_E2B_PIN))
		{
			raw_coutB--;
		}
		else
		{
			raw_coutB++;
		}
	}
	else if((gpio_status & ENCODER_E2B_PIN)==ENCODER_E2B_PIN)
	{

		if(!DL_GPIO_readPins(ENCODER_PORT,ENCODER_E2A_PIN))
		{
			raw_coutB++;
		}
		else
		{
			raw_coutB--;
		}
	}

	DL_GPIO_clearInterruptStatus(ENCODER_PORT,ENCODER_E1A_PIN | ENCODER_E1B_PIN |ENCODER_E2A_PIN|ENCODER_E2B_PIN);
}