#include "serial.h"
volatile char rxBuffer[RX_BUFFER_SIZE];
volatile uint16_t rxIndex = 0;         
volatile bool stringReady = false; 
int fputc(int ch, FILE *stream)
{
        while( DL_UART_isBusy(UART_0_INST) == true );

        DL_UART_Main_transmitData(UART_0_INST, ch);

        return ch;
}
void UART_0_INST_IRQHandler(void)
{
    switch( DL_UART_getPendingInterrupt(UART_0_INST) )
    {
        case DL_UART_IIDX_RX:{
            char rxChar = DL_UART_Main_receiveData(UART_0_INST);
						if (rxChar == '\n' || rxChar == '\r') {
								if (rxIndex > 0) {
										rxBuffer[rxIndex] = '\0';
										stringReady = true;     
										rxIndex = 0;       
								}
						} 
						else {
								if (rxIndex < (RX_BUFFER_SIZE - 1)) {
										rxBuffer[rxIndex] = rxChar;
										rxIndex++;
								} else {
										rxBuffer[RX_BUFFER_SIZE - 1] = '\0';
										stringReady = true;
										rxIndex = 0;
								}
						}
				}
            break;
						
        default:
            break;
								
				}
}