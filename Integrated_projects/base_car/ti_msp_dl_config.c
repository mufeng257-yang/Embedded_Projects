/*
 * Copyright (c) 2023, Texas Instruments Incorporated
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
 *  ============ ti_msp_dl_config.c =============
 *  Configured MSPM0 DriverLib module definitions
 *
 *  DO NOT EDIT - This file is generated for the MSPM0G350X
 *  by the SysConfig tool.
 */

#include "ti_msp_dl_config.h"

DL_TimerA_backupConfig gTIMER_ENCODERBackup;
DL_TimerA_backupConfig gTIMER_SR04Backup;

/*
 *  ======== SYSCFG_DL_init ========
 *  Perform any initialization needed before using any board APIs
 */
SYSCONFIG_WEAK void SYSCFG_DL_init(void)
{
    SYSCFG_DL_initPower();
    SYSCFG_DL_GPIO_init();
    /* Module-Specific Initializations*/
    SYSCFG_DL_SYSCTL_init();
    SYSCFG_DL_TIMER_ENCODER_init();
    SYSCFG_DL_TIMER_SR04_init();
    SYSCFG_DL_UART_0_init();
    SYSCFG_DL_Bluetooth_init();
    /* Ensure backup structures have no valid state */
	gTIMER_ENCODERBackup.backupRdy 	= false;
	gTIMER_SR04Backup.backupRdy 	= false;


}
/*
 * User should take care to save and restore register configuration in application.
 * See Retention Configuration section for more details.
 */
SYSCONFIG_WEAK bool SYSCFG_DL_saveConfiguration(void)
{
    bool retStatus = true;

	retStatus &= DL_TimerA_saveConfiguration(TIMER_ENCODER_INST, &gTIMER_ENCODERBackup);
	retStatus &= DL_TimerA_saveConfiguration(TIMER_SR04_INST, &gTIMER_SR04Backup);

    return retStatus;
}


SYSCONFIG_WEAK bool SYSCFG_DL_restoreConfiguration(void)
{
    bool retStatus = true;

	retStatus &= DL_TimerA_restoreConfiguration(TIMER_ENCODER_INST, &gTIMER_ENCODERBackup, false);
	retStatus &= DL_TimerA_restoreConfiguration(TIMER_SR04_INST, &gTIMER_SR04Backup, false);

    return retStatus;
}

SYSCONFIG_WEAK void SYSCFG_DL_initPower(void)
{
    DL_GPIO_reset(GPIOA);
    DL_GPIO_reset(GPIOB);
    DL_TimerA_reset(TIMER_ENCODER_INST);
    DL_TimerA_reset(TIMER_SR04_INST);
    DL_UART_Main_reset(UART_0_INST);
    DL_UART_Main_reset(Bluetooth_INST);

    DL_GPIO_enablePower(GPIOA);
    DL_GPIO_enablePower(GPIOB);
    DL_TimerA_enablePower(TIMER_ENCODER_INST);
    DL_TimerA_enablePower(TIMER_SR04_INST);
    DL_UART_Main_enablePower(UART_0_INST);
    DL_UART_Main_enablePower(Bluetooth_INST);
    delay_cycles(POWER_STARTUP_DELAY);
}

SYSCONFIG_WEAK void SYSCFG_DL_GPIO_init(void)
{

    DL_GPIO_initPeripheralOutputFunction(
        GPIO_UART_0_IOMUX_TX, GPIO_UART_0_IOMUX_TX_FUNC);
    DL_GPIO_initPeripheralInputFunction(
        GPIO_UART_0_IOMUX_RX, GPIO_UART_0_IOMUX_RX_FUNC);
    DL_GPIO_initPeripheralOutputFunction(
        GPIO_Bluetooth_IOMUX_TX, GPIO_Bluetooth_IOMUX_TX_FUNC);
    DL_GPIO_initPeripheralInputFunction(
        GPIO_Bluetooth_IOMUX_RX, GPIO_Bluetooth_IOMUX_RX_FUNC);

    DL_GPIO_initDigitalInputFeatures(ENCODER_E1A_IOMUX,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_DOWN,
		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

    DL_GPIO_initDigitalInputFeatures(ENCODER_E1B_IOMUX,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_DOWN,
		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

    DL_GPIO_initDigitalInputFeatures(ENCODER_E2A_IOMUX,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_DOWN,
		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

    DL_GPIO_initDigitalInputFeatures(ENCODER_E2B_IOMUX,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_DOWN,
		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

    DL_GPIO_initDigitalOutput(SR04_Trig_IOMUX);

    DL_GPIO_initDigitalInputFeatures(SR04_Echo_IOMUX,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_NONE,
		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

    DL_GPIO_initDigitalOutput(OLED_OLED_SCL_IOMUX);

    DL_GPIO_initDigitalOutput(OLED_OLED_SDA_IOMUX);

    DL_GPIO_clearPins(GPIOA, OLED_OLED_SCL_PIN |
		OLED_OLED_SDA_PIN);
    DL_GPIO_setPins(GPIOA, SR04_Trig_PIN);
    DL_GPIO_enableOutput(GPIOA, SR04_Trig_PIN |
		OLED_OLED_SCL_PIN |
		OLED_OLED_SDA_PIN);
    DL_GPIO_setLowerPinsPolarity(GPIOA, DL_GPIO_PIN_8_EDGE_RISE_FALL);
    DL_GPIO_clearInterruptStatus(GPIOA, SR04_Echo_PIN);
    DL_GPIO_enableInterrupt(GPIOA, SR04_Echo_PIN);
    DL_GPIO_setLowerPinsPolarity(ENCODER_PORT, DL_GPIO_PIN_6_EDGE_RISE |
		DL_GPIO_PIN_7_EDGE_RISE |
		DL_GPIO_PIN_8_EDGE_RISE |
		DL_GPIO_PIN_9_EDGE_RISE);
    DL_GPIO_clearInterruptStatus(ENCODER_PORT, ENCODER_E1A_PIN |
		ENCODER_E1B_PIN |
		ENCODER_E2A_PIN |
		ENCODER_E2B_PIN);
    DL_GPIO_enableInterrupt(ENCODER_PORT, ENCODER_E1A_PIN |
		ENCODER_E1B_PIN |
		ENCODER_E2A_PIN |
		ENCODER_E2B_PIN);

}


SYSCONFIG_WEAK void SYSCFG_DL_SYSCTL_init(void)
{

	//Low Power Mode is configured to be SLEEP0
    DL_SYSCTL_setBORThreshold(DL_SYSCTL_BOR_THRESHOLD_LEVEL_0);

    DL_SYSCTL_setSYSOSCFreq(DL_SYSCTL_SYSOSC_FREQ_BASE);
    /* Set default configuration */
    DL_SYSCTL_disableHFXT();
    DL_SYSCTL_disableSYSPLL();
    DL_SYSCTL_setULPCLKDivider(DL_SYSCTL_ULPCLK_DIV_1);
    DL_SYSCTL_setMCLKDivider(DL_SYSCTL_MCLK_DIVIDER_DISABLE);
    /* INT_GROUP1 Priority */
    NVIC_SetPriority(GPIOA_INT_IRQn, 1);

}



/*
 * Timer clock configuration to be sourced by BUSCLK /  (4000000 Hz)
 * timerClkFreq = (timerClkSrc / (timerClkDivRatio * (timerClkPrescale + 1)))
 *   400000 Hz = 4000000 Hz / (8 * (9 + 1))
 */
static const DL_TimerA_ClockConfig gTIMER_ENCODERClockConfig = {
    .clockSel    = DL_TIMER_CLOCK_BUSCLK,
    .divideRatio = DL_TIMER_CLOCK_DIVIDE_8,
    .prescale    = 9U,
};

/*
 * Timer load value (where the counter starts from) is calculated as (timerPeriod * timerClockFreq) - 1
 * TIMER_ENCODER_INST_LOAD_VALUE = (10 ms * 400000 Hz) - 1
 */
static const DL_TimerA_TimerConfig gTIMER_ENCODERTimerConfig = {
    .period     = TIMER_ENCODER_INST_LOAD_VALUE,
    .timerMode  = DL_TIMER_TIMER_MODE_PERIODIC,
    .startTimer = DL_TIMER_START,
};

SYSCONFIG_WEAK void SYSCFG_DL_TIMER_ENCODER_init(void) {

    DL_TimerA_setClockConfig(TIMER_ENCODER_INST,
        (DL_TimerA_ClockConfig *) &gTIMER_ENCODERClockConfig);

    DL_TimerA_initTimerMode(TIMER_ENCODER_INST,
        (DL_TimerA_TimerConfig *) &gTIMER_ENCODERTimerConfig);
    DL_TimerA_enableInterrupt(TIMER_ENCODER_INST , DL_TIMERA_INTERRUPT_ZERO_EVENT);
	NVIC_SetPriority(TIMER_ENCODER_INST_INT_IRQN, 0);
    DL_TimerA_enableClock(TIMER_ENCODER_INST);





}

/*
 * Timer clock configuration to be sourced by BUSCLK /  (32000000 Hz)
 * timerClkFreq = (timerClkSrc / (timerClkDivRatio * (timerClkPrescale + 1)))
 *   800000 Hz = 32000000 Hz / (1 * (39 + 1))
 */
static const DL_TimerA_ClockConfig gTIMER_SR04ClockConfig = {
    .clockSel    = DL_TIMER_CLOCK_BUSCLK,
    .divideRatio = DL_TIMER_CLOCK_DIVIDE_1,
    .prescale    = 39U,
};

/*
 * Timer load value (where the counter starts from) is calculated as (timerPeriod * timerClockFreq) - 1
 * TIMER_SR04_INST_LOAD_VALUE = (1 ms * 800000 Hz) - 1
 */
static const DL_TimerA_TimerConfig gTIMER_SR04TimerConfig = {
    .period     = TIMER_SR04_INST_LOAD_VALUE,
    .timerMode  = DL_TIMER_TIMER_MODE_PERIODIC_UP,
    .startTimer = DL_TIMER_START,
};

SYSCONFIG_WEAK void SYSCFG_DL_TIMER_SR04_init(void) {

    DL_TimerA_setClockConfig(TIMER_SR04_INST,
        (DL_TimerA_ClockConfig *) &gTIMER_SR04ClockConfig);

    DL_TimerA_initTimerMode(TIMER_SR04_INST,
        (DL_TimerA_TimerConfig *) &gTIMER_SR04TimerConfig);
    DL_TimerA_enableInterrupt(TIMER_SR04_INST , DL_TIMERA_INTERRUPT_LOAD_EVENT);
	NVIC_SetPriority(TIMER_SR04_INST_INT_IRQN, 1);
    DL_TimerA_enableClock(TIMER_SR04_INST);





}


static const DL_UART_Main_ClockConfig gUART_0ClockConfig = {
    .clockSel    = DL_UART_MAIN_CLOCK_BUSCLK,
    .divideRatio = DL_UART_MAIN_CLOCK_DIVIDE_RATIO_1
};

static const DL_UART_Main_Config gUART_0Config = {
    .mode        = DL_UART_MAIN_MODE_NORMAL,
    .direction   = DL_UART_MAIN_DIRECTION_TX_RX,
    .flowControl = DL_UART_MAIN_FLOW_CONTROL_NONE,
    .parity      = DL_UART_MAIN_PARITY_NONE,
    .wordLength  = DL_UART_MAIN_WORD_LENGTH_8_BITS,
    .stopBits    = DL_UART_MAIN_STOP_BITS_ONE
};

SYSCONFIG_WEAK void SYSCFG_DL_UART_0_init(void)
{
    DL_UART_Main_setClockConfig(UART_0_INST, (DL_UART_Main_ClockConfig *) &gUART_0ClockConfig);

    DL_UART_Main_init(UART_0_INST, (DL_UART_Main_Config *) &gUART_0Config);
    /*
     * Configure baud rate by setting oversampling and baud rate divisors.
     *  Target baud rate: 9600
     *  Actual baud rate: 9600.24
     */
    DL_UART_Main_setOversampling(UART_0_INST, DL_UART_OVERSAMPLING_RATE_16X);
    DL_UART_Main_setBaudRateDivisor(UART_0_INST, UART_0_IBRD_32_MHZ_9600_BAUD, UART_0_FBRD_32_MHZ_9600_BAUD);



    DL_UART_Main_enable(UART_0_INST);
}
static const DL_UART_Main_ClockConfig gBluetoothClockConfig = {
    .clockSel    = DL_UART_MAIN_CLOCK_BUSCLK,
    .divideRatio = DL_UART_MAIN_CLOCK_DIVIDE_RATIO_1
};

static const DL_UART_Main_Config gBluetoothConfig = {
    .mode        = DL_UART_MAIN_MODE_NORMAL,
    .direction   = DL_UART_MAIN_DIRECTION_TX_RX,
    .flowControl = DL_UART_MAIN_FLOW_CONTROL_NONE,
    .parity      = DL_UART_MAIN_PARITY_NONE,
    .wordLength  = DL_UART_MAIN_WORD_LENGTH_8_BITS,
    .stopBits    = DL_UART_MAIN_STOP_BITS_ONE
};

SYSCONFIG_WEAK void SYSCFG_DL_Bluetooth_init(void)
{
    DL_UART_Main_setClockConfig(Bluetooth_INST, (DL_UART_Main_ClockConfig *) &gBluetoothClockConfig);

    DL_UART_Main_init(Bluetooth_INST, (DL_UART_Main_Config *) &gBluetoothConfig);
    /*
     * Configure baud rate by setting oversampling and baud rate divisors.
     *  Target baud rate: 115200
     *  Actual baud rate: 115211.52
     */
    DL_UART_Main_setOversampling(Bluetooth_INST, DL_UART_OVERSAMPLING_RATE_16X);
    DL_UART_Main_setBaudRateDivisor(Bluetooth_INST, Bluetooth_IBRD_32_MHZ_115200_BAUD, Bluetooth_FBRD_32_MHZ_115200_BAUD);


    /* Configure Interrupts */
    DL_UART_Main_enableInterrupt(Bluetooth_INST,
                                 DL_UART_MAIN_INTERRUPT_RX);
    /* Setting the Interrupt Priority */
    NVIC_SetPriority(Bluetooth_INST_INT_IRQN, 0);


    DL_UART_Main_enable(Bluetooth_INST);
}

