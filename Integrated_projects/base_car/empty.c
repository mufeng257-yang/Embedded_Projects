/*
 * Copyright (c) 2021, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "ti_msp_dl_config.h"
#include "encoder.h"
#include "bsp_sr04.h"
#include "IOI2C.h"
#include "OLED.h" 
#include "serial.h"
int x=0;
int y=0;
char cnt_buf[20];
int main(void)
{
    SYSCFG_DL_init();
		
		TIMER_ENCODER_init();
		NVIC_EnableIRQ(Bluetooth_INST_INT_IRQN);
		SR04_Init();
		encoder_init();
		OLED_Init();
		OLED_Clear();
		cout1=0;
		cout2=0;
		NVIC_EnableIRQ(SR04_INT_IRQN);
		delay_ms(10);
    while (1) {
			if (stringReady) 
			{
			sscanf((char*)rxBuffer, "%d,%d", &x, &y);
			stringReady = false;
			}
			uint32_t V=(int)SR04_GetLength();
			OLED_ShowString(0,1,(uint8_t*)rxBuffer,16);
			printf("%s",rxBuffer);
			printf("x=%d,y=%d",x,y);
			printf("SR=%dCM ", V);
			printf("cout1=%3d ",cout1);
			printf("cout2=%3d\n",cout2);


    }
}
