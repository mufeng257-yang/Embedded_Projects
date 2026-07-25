/*
 * Copyright (c) 2023, Texas Instruments Incorporated - http://www.ti.com
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

/*
 *  ============ ti_msp_dl_config.h =============
 *  Configured MSPM0 DriverLib module declarations
 *
 *  DO NOT EDIT - This file is generated for the MSPM0G350X
 *  by the SysConfig tool.
 */
#ifndef ti_msp_dl_config_h
#define ti_msp_dl_config_h

#define CONFIG_MSPM0G350X
#define CONFIG_MSPM0G3507

#if defined(__ti_version__) || defined(__TI_COMPILER_VERSION__)
#define SYSCONFIG_WEAK __attribute__((weak))
#elif defined(__IAR_SYSTEMS_ICC__)
#define SYSCONFIG_WEAK __weak
#elif defined(__GNUC__)
#define SYSCONFIG_WEAK __attribute__((weak))
#endif

#include <ti/devices/msp/msp.h>
#include <ti/driverlib/driverlib.h>
#include <ti/driverlib/m0p/dl_core.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 *  ======== SYSCFG_DL_init ========
 *  Perform all required MSP DL initialization
 *
 *  This function should be called once at a point before any use of
 *  MSP DL.
 */


/* clang-format off */

#define POWER_STARTUP_DELAY                                                (16)


#define CPUCLK_FREQ                                                     32000000



/* Defines for PWM_MOTOR */
#define PWM_MOTOR_INST                                                     TIMA1
#define PWM_MOTOR_INST_IRQHandler                               TIMA1_IRQHandler
#define PWM_MOTOR_INST_INT_IRQN                                 (TIMA1_INT_IRQn)
#define PWM_MOTOR_INST_CLK_FREQ                                         32000000
/* GPIO defines for channel 0 */
#define GPIO_PWM_MOTOR_C0_PORT                                             GPIOA
#define GPIO_PWM_MOTOR_C0_PIN                                     DL_GPIO_PIN_17
#define GPIO_PWM_MOTOR_C0_IOMUX                                  (IOMUX_PINCM39)
#define GPIO_PWM_MOTOR_C0_IOMUX_FUNC                 IOMUX_PINCM39_PF_TIMA1_CCP0
#define GPIO_PWM_MOTOR_C0_IDX                                DL_TIMER_CC_0_INDEX
/* GPIO defines for channel 1 */
#define GPIO_PWM_MOTOR_C1_PORT                                             GPIOA
#define GPIO_PWM_MOTOR_C1_PIN                                     DL_GPIO_PIN_16
#define GPIO_PWM_MOTOR_C1_IOMUX                                  (IOMUX_PINCM38)
#define GPIO_PWM_MOTOR_C1_IOMUX_FUNC                 IOMUX_PINCM38_PF_TIMA1_CCP1
#define GPIO_PWM_MOTOR_C1_IDX                                DL_TIMER_CC_1_INDEX



/* Defines for TIMER_ENCODER */
#define TIMER_ENCODER_INST                                               (TIMA0)
#define TIMER_ENCODER_INST_IRQHandler                           TIMA0_IRQHandler
#define TIMER_ENCODER_INST_INT_IRQN                             (TIMA0_INT_IRQn)
#define TIMER_ENCODER_INST_LOAD_VALUE                                    (3999U)




/* Defines for I2C_MPU6050 */
#define I2C_MPU6050_INST                                                    I2C1
#define I2C_MPU6050_INST_IRQHandler                              I2C1_IRQHandler
#define I2C_MPU6050_INST_INT_IRQN                                  I2C1_INT_IRQn
#define I2C_MPU6050_BUS_SPEED_HZ                                          400000
#define GPIO_I2C_MPU6050_SDA_PORT                                          GPIOA
#define GPIO_I2C_MPU6050_SDA_PIN                                  DL_GPIO_PIN_30
#define GPIO_I2C_MPU6050_IOMUX_SDA                                (IOMUX_PINCM5)
#define GPIO_I2C_MPU6050_IOMUX_SDA_FUNC                 IOMUX_PINCM5_PF_I2C1_SDA
#define GPIO_I2C_MPU6050_SCL_PORT                                          GPIOA
#define GPIO_I2C_MPU6050_SCL_PIN                                  DL_GPIO_PIN_29
#define GPIO_I2C_MPU6050_IOMUX_SCL                                (IOMUX_PINCM4)
#define GPIO_I2C_MPU6050_IOMUX_SCL_FUNC                 IOMUX_PINCM4_PF_I2C1_SCL


/* Defines for UART_0 */
#define UART_0_INST                                                        UART0
#define UART_0_INST_FREQUENCY                                           32000000
#define UART_0_INST_IRQHandler                                  UART0_IRQHandler
#define UART_0_INST_INT_IRQN                                      UART0_INT_IRQn
#define GPIO_UART_0_RX_PORT                                                GPIOA
#define GPIO_UART_0_TX_PORT                                                GPIOA
#define GPIO_UART_0_RX_PIN                                        DL_GPIO_PIN_11
#define GPIO_UART_0_TX_PIN                                        DL_GPIO_PIN_10
#define GPIO_UART_0_IOMUX_RX                                     (IOMUX_PINCM22)
#define GPIO_UART_0_IOMUX_TX                                     (IOMUX_PINCM21)
#define GPIO_UART_0_IOMUX_RX_FUNC                      IOMUX_PINCM22_PF_UART0_RX
#define GPIO_UART_0_IOMUX_TX_FUNC                      IOMUX_PINCM21_PF_UART0_TX
#define UART_0_BAUD_RATE                                                  (9600)
#define UART_0_IBRD_32_MHZ_9600_BAUD                                       (208)
#define UART_0_FBRD_32_MHZ_9600_BAUD                                        (21)
/* Defines for Bluetooth */
#define Bluetooth_INST                                                     UART2
#define Bluetooth_INST_FREQUENCY                                        32000000
#define Bluetooth_INST_IRQHandler                               UART2_IRQHandler
#define Bluetooth_INST_INT_IRQN                                   UART2_INT_IRQn
#define GPIO_Bluetooth_RX_PORT                                             GPIOB
#define GPIO_Bluetooth_TX_PORT                                             GPIOA
#define GPIO_Bluetooth_RX_PIN                                     DL_GPIO_PIN_18
#define GPIO_Bluetooth_TX_PIN                                     DL_GPIO_PIN_21
#define GPIO_Bluetooth_IOMUX_RX                                  (IOMUX_PINCM44)
#define GPIO_Bluetooth_IOMUX_TX                                  (IOMUX_PINCM46)
#define GPIO_Bluetooth_IOMUX_RX_FUNC                   IOMUX_PINCM44_PF_UART2_RX
#define GPIO_Bluetooth_IOMUX_TX_FUNC                   IOMUX_PINCM46_PF_UART2_TX
#define Bluetooth_BAUD_RATE                                             (115200)
#define Bluetooth_IBRD_32_MHZ_115200_BAUD                                   (17)
#define Bluetooth_FBRD_32_MHZ_115200_BAUD                                   (23)





/* Port definition for Pin Group GPIO_MPU6050 */
#define GPIO_MPU6050_PORT                                                (GPIOB)

/* Defines for PIN_MPU6050_INT: GPIOB.15 with pinCMx 32 on package pin 3 */
// pins affected by this interrupt request:["PIN_MPU6050_INT"]
#define GPIO_MPU6050_INT_IRQN                                   (GPIOB_INT_IRQn)
#define GPIO_MPU6050_INT_IIDX                   (DL_INTERRUPT_GROUP1_IIDX_GPIOB)
#define GPIO_MPU6050_PIN_MPU6050_INT_IIDX                   (DL_GPIO_IIDX_DIO15)
#define GPIO_MPU6050_PIN_MPU6050_INT_PIN                        (DL_GPIO_PIN_15)
#define GPIO_MPU6050_PIN_MPU6050_INT_IOMUX                       (IOMUX_PINCM32)
/* Port definition for Pin Group citie */
#define citie_PORT                                                       (GPIOB)

/* Defines for work: GPIOB.5 with pinCMx 18 on package pin 53 */
#define citie_work_PIN                                           (DL_GPIO_PIN_5)
#define citie_work_IOMUX                                         (IOMUX_PINCM18)
/* Port definition for Pin Group KEY */
#define KEY_PORT                                                         (GPIOB)

/* Defines for key0: GPIOB.21 with pinCMx 49 on package pin 20 */
#define KEY_key0_PIN                                            (DL_GPIO_PIN_21)
#define KEY_key0_IOMUX                                           (IOMUX_PINCM49)
/* Port definition for Pin Group LED */
#define LED_PORT                                                         (GPIOB)

/* Defines for LED0: GPIOB.22 with pinCMx 50 on package pin 21 */
#define LED_LED0_PIN                                            (DL_GPIO_PIN_22)
#define LED_LED0_IOMUX                                           (IOMUX_PINCM50)
/* Port definition for Pin Group ENCODER */
#define ENCODER_PORT                                                     (GPIOA)

/* Defines for E1A: GPIOA.27 with pinCMx 60 on package pin 31 */
// pins affected by this interrupt request:["E1A","E1B","E2A","E2B"]
#define ENCODER_INT_IRQN                                        (GPIOA_INT_IRQn)
#define ENCODER_INT_IIDX                        (DL_INTERRUPT_GROUP1_IIDX_GPIOA)
#define ENCODER_E1A_IIDX                                    (DL_GPIO_IIDX_DIO27)
#define ENCODER_E1A_PIN                                         (DL_GPIO_PIN_27)
#define ENCODER_E1A_IOMUX                                        (IOMUX_PINCM60)
/* Defines for E1B: GPIOA.26 with pinCMx 59 on package pin 30 */
#define ENCODER_E1B_IIDX                                    (DL_GPIO_IIDX_DIO26)
#define ENCODER_E1B_PIN                                         (DL_GPIO_PIN_26)
#define ENCODER_E1B_IOMUX                                        (IOMUX_PINCM59)
/* Defines for E2A: GPIOA.25 with pinCMx 55 on package pin 26 */
#define ENCODER_E2A_IIDX                                    (DL_GPIO_IIDX_DIO25)
#define ENCODER_E2A_PIN                                         (DL_GPIO_PIN_25)
#define ENCODER_E2A_IOMUX                                        (IOMUX_PINCM55)
/* Defines for E2B: GPIOA.24 with pinCMx 54 on package pin 25 */
#define ENCODER_E2B_IIDX                                    (DL_GPIO_IIDX_DIO24)
#define ENCODER_E2B_PIN                                         (DL_GPIO_PIN_24)
#define ENCODER_E2B_IOMUX                                        (IOMUX_PINCM54)
/* Port definition for Pin Group OLED */
#define OLED_PORT                                                        (GPIOA)

/* Defines for OLED_SCL: GPIOA.31 with pinCMx 6 on package pin 39 */
#define OLED_OLED_SCL_PIN                                       (DL_GPIO_PIN_31)
#define OLED_OLED_SCL_IOMUX                                       (IOMUX_PINCM6)
/* Defines for OLED_SDA: GPIOA.28 with pinCMx 3 on package pin 35 */
#define OLED_OLED_SDA_PIN                                       (DL_GPIO_PIN_28)
#define OLED_OLED_SDA_IOMUX                                       (IOMUX_PINCM3)
/* Defines for AIN1: GPIOB.3 with pinCMx 16 on package pin 51 */
#define MOTOR_AIN1_PORT                                                  (GPIOB)
#define MOTOR_AIN1_PIN                                           (DL_GPIO_PIN_3)
#define MOTOR_AIN1_IOMUX                                         (IOMUX_PINCM16)
/* Defines for AIN2: GPIOA.15 with pinCMx 37 on package pin 8 */
#define MOTOR_AIN2_PORT                                                  (GPIOA)
#define MOTOR_AIN2_PIN                                          (DL_GPIO_PIN_15)
#define MOTOR_AIN2_IOMUX                                         (IOMUX_PINCM37)
/* Defines for BIN1: GPIOA.12 with pinCMx 34 on package pin 5 */
#define MOTOR_BIN1_PORT                                                  (GPIOA)
#define MOTOR_BIN1_PIN                                          (DL_GPIO_PIN_12)
#define MOTOR_BIN1_IOMUX                                         (IOMUX_PINCM34)
/* Defines for BIN2: GPIOA.13 with pinCMx 35 on package pin 6 */
#define MOTOR_BIN2_PORT                                                  (GPIOA)
#define MOTOR_BIN2_PIN                                          (DL_GPIO_PIN_13)
#define MOTOR_BIN2_IOMUX                                         (IOMUX_PINCM35)
/* Port definition for Pin Group IIC_Software */
#define IIC_Software_PORT                                                (GPIOA)

/* Defines for SDA: GPIOA.0 with pinCMx 1 on package pin 33 */
#define IIC_Software_SDA_PIN                                     (DL_GPIO_PIN_0)
#define IIC_Software_SDA_IOMUX                                    (IOMUX_PINCM1)
/* Defines for SCL: GPIOA.1 with pinCMx 2 on package pin 34 */
#define IIC_Software_SCL_PIN                                     (DL_GPIO_PIN_1)
#define IIC_Software_SCL_IOMUX                                    (IOMUX_PINCM2)


/* clang-format on */

void SYSCFG_DL_init(void);
void SYSCFG_DL_initPower(void);
void SYSCFG_DL_GPIO_init(void);
void SYSCFG_DL_SYSCTL_init(void);
void SYSCFG_DL_PWM_MOTOR_init(void);
void SYSCFG_DL_TIMER_ENCODER_init(void);
void SYSCFG_DL_I2C_MPU6050_init(void);
void SYSCFG_DL_UART_0_init(void);
void SYSCFG_DL_Bluetooth_init(void);


bool SYSCFG_DL_saveConfiguration(void);
bool SYSCFG_DL_restoreConfiguration(void);

#ifdef __cplusplus
}
#endif

#endif /* ti_msp_dl_config_h */
