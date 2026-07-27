#include "ti_msp_dl_config.h"
#include "encoder.h"
#include "IOI2C.h"
#include "OLED.h" 
#include "clock.h"
#include "interrupt.h"
#include "mpu6050.h"
#include "motor.h"
#include "serial.h"
#include "pid.h"
short y_flag=0;
float zero_yaw=0.0;
float error_yaw=0.0;
int A=0;
int B=0;
float Target_jiaodu=0.0f;
char buf[20];
bool h1,h2,h3,h4,h5,h6,h7,h8;
int cmd=0;
int data=0;
int main(void)
{
    SYSCFG_DL_init();
		NVIC_EnableIRQ(UART_0_INST_INT_IRQN);
		SysTick_Init();
		TIMER_ENCODER_init();
		MPU6050_Init();
		Interrupt_Init();

		OLED_Init();
		OLED_Clear();
		encoder_init();
		coutA=0;
		coutB=0;
		A_speed(0);
		B_speed(0);
		PID_Init(&jiaoduhuan,0,0,0,180,-180);
		PID_Init(&Aspeedhuan,5,0,0,500,-500);
		PID_Init(&Bspeedhuan,5,0,0,500,-500);
		delay_ms(10);
    while (1) {
			printf("%d,%d,%d,%d,%d,%d\n",A_PWM,B_PWM,coutA,coutB,A,B);
			//h1=DL_GPIO_readPins(GPIOB,Huidu_H1_PIN);
//			h2=DL_GPIO_readPins(GPIOB,Huidu_H2_PIN);
//			h3=DL_GPIO_readPins(GPIOB,Huidu_H3_PIN);
//			h4=DL_GPIO_readPins(GPIOB,Huidu_H4_PIN);
//			h5=DL_GPIO_readPins(GPIOB,Huidu_H5_PIN);
//			h6=DL_GPIO_readPins(GPIOB,Huidu_H6_PIN);
//			h7=DL_GPIO_readPins(GPIOB,Huidu_H7_PIN);
			
			//h8=DL_GPIO_readPins(GPIOA,Huidu_H8_PIN);
			//printf("%d,%d,%d,%d,%d,%d\n",h2,h3,h4,h5,h6,h7);
			
//			if(!DL_GPIO_readPins(KEY_PORT,KEY_key0_PIN)) DL_GPIO_togglePins(LED_PORT,LED_LED0_PIN);
			
			if (stringReady) 
			{
				
				sscanf((char*)rxBuffer, "%d,%d", &cmd,&data);
				if(cmd==1) A=data;
				else if(cmd==2) Aspeedhuan.Kp=data;
				else if(cmd==3) Aspeedhuan.Kd=data;
				else if(cmd==4) Aspeedhuan.Ki=data;
				else if(cmd==5) B=data;
				else if(cmd==6) Bspeedhuan.Kp=data;
				else if(cmd==7) Bspeedhuan.Kd=data;
				else if(cmd==8) Bspeedhuan.Ki=data;
//			sscanf((char*)rxBuffer, "%d,%d", &A,&B);
//			sprintf(buf,"A=%3d ",A);
//			OLED_ShowString(0,0,(uint8_t*)buf,16);
//			sprintf(buf,"B=%3d ",B);
//			OLED_ShowString(0,2,(uint8_t*)buf,16);
				
				printf("%d,%d\n",cmd,data);
				stringReady = false;
			}
//			if(!y_flag){printf("yaw=%4.1f\n",yaw);}
//			if(y_flag){
//			error_yaw=yaw-zero_yaw;
//			if (error_yaw>180) error_yaw=360-error_yaw;
//			if (error_yaw<-180) error_yaw=360-error_yaw;
//				
//			if (error_yaw>5+Target_jiaodu)
//				{ 
//					A_speed(100);
//					B_speed(-100);
//				}
//			else if (error_yaw<Target_jiaodu-5)
//				{ 
//					A_speed(-100);					
//					B_speed(100);
//				}
//			else 
//				{
//					y_flag=0;
//					A_speed(0);
//					B_speed(0);
//				}
//		}
			
//			DL_GPIO_togglePins(citie_PORT,citie_work_PIN);
//			delay_ms(1000);
		
//			sprintf(buf,"%-6.1f", pitch);
//			OLED_ShowString(0,0,(uint8_t*)buf,16);
//			sprintf(buf,"%-6.1f", roll);
//			OLED_ShowString(0,2,(uint8_t*)buf,16);
//			sprintf(buf,"%-6.1f", yaw);
//			OLED_ShowString(0,2,(uint8_t*)buf,16);

//			sprintf(buf,"cout1=%3d ",coutA);
//			OLED_ShowString(0,4,(uint8_t*)buf,16);
//			sprintf(buf,"cout2=%3d ",coutB);
//			OLED_ShowString(0,6,(uint8_t*)buf,16);
			delay_ms(100);
    }
}
