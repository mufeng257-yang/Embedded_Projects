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

void GROUP1_IRQHandler(void)
{
	uint32_t gpio_status;

	gpio_status = DL_GPIO_getEnabledInterruptStatus(GPIO_MPU6050_PORT,GPIO_MPU6050_PIN_MPU6050_INT_PIN);
    
  if((gpio_status & GPIO_MPU6050_PIN_MPU6050_INT_PIN) == GPIO_MPU6050_PIN_MPU6050_INT_PIN){
				Read_Quad();
//				float Aspeed_out=PID_Compute(&Aspeedhuan,(float)A,(float)coutA);
//				float Bspeed_out=PID_Compute(&Bspeedhuan,(float)B,(float)coutB);
//				float jiaodu_out=PID_Compute(&jiaoduhuan,Target_jiaodu,error_yaw);
//				A_speed((int)(Aspeed_out+jiaodu_out));
//				B_speed((int)(Bspeed_out-jiaodu_out));
//				printf("%0.2f,%0.2f,%0.2f\n",Aspeed_out,Bspeed_out,jiaodu_out);
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