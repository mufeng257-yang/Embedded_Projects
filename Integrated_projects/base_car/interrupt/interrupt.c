#include "ti_msp_dl_config.h"
#include "encoder.h"
#include "bsp_sr04.h"
void GROUP1_IRQHandler(void)
{
	switch( DL_Interrupt_getPendingGroup(DL_INTERRUPT_GROUP_1) )
    {
        case SR04_INT_IIDX:
            if( SR04_ECHO() )
            {
                SR04_Flag = 1;
                distance = 0.0;
                Open_Timer(); 
            }
            else 
            {
                Close_Timer();  
                SR04_Flag = 0;
                distance = (float)Get_TIMER_Count() / 58.0f; 
            }
						DL_GPIO_clearInterruptStatus(SR04_PORT,SR04_Echo_PIN);
				
        break;
    }
	uint32_t gpio_status;

	gpio_status = DL_GPIO_getEnabledInterruptStatus(ENCODER_PORT,ENCODER_E1A_PIN | ENCODER_E1B_PIN |ENCODER_E2A_PIN|ENCODER_E2B_PIN);
	
	if((gpio_status & ENCODER_E1A_PIN) == ENCODER_E1A_PIN)
	{

		if(!DL_GPIO_readPins(ENCODER_PORT,ENCODER_E1B_PIN))
		{
			raw_cout1--;
		}
		else
		{
			raw_cout1++;
		}
	}
	else if((gpio_status & ENCODER_E1B_PIN)==ENCODER_E1B_PIN)
	{

		if(!DL_GPIO_readPins(ENCODER_PORT,ENCODER_E1A_PIN))
		{
			raw_cout1++;
		}
		else
		{
			raw_cout1--;
		}
	}
	
	
	if((gpio_status & ENCODER_E2A_PIN) == ENCODER_E2A_PIN)
	{

		if(!DL_GPIO_readPins(ENCODER_PORT,ENCODER_E2B_PIN))
		{
			raw_cout2++;
		}
		else
		{
			raw_cout2--;
		}
	}
	else if((gpio_status & ENCODER_E2B_PIN)==ENCODER_E2B_PIN)
	{

		if(!DL_GPIO_readPins(ENCODER_PORT,ENCODER_E2A_PIN))
		{
			raw_cout2--;
		}
		else
		{
			raw_cout2++;
		}
	}

	DL_GPIO_clearInterruptStatus(ENCODER_PORT,ENCODER_E1A_PIN | ENCODER_E1B_PIN |ENCODER_E2A_PIN|ENCODER_E2B_PIN);
}