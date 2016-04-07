#include "stm32f30x_conf.h"
#include "stm32f30x_rcc.h"
#include "state_machine.h"
#include "engine_params.h"
#include "pins.h"

/* Disable Systicks for now
void SysTick_Handler(void) {
	static uint16_t tick = 0;

	switch (tick++) {
		case 100:
			tick = 0;
			GPIOE->ODR ^= (1 << 8);
			break;
	}
	
}
*/

State illegal_state(System_Vars *s_vars)
{
	const char* state_desc = "ILLEGAL";
	while(1);
}

/**
 * @brief Configure general purpose IOs. Requires the use of TMR2,
 * 	       call the timer configuration before GPIO config.
 *         Populate the system_vars variable;
 */
State init_state(System_Vars* s_vars)
{
	GPIO_InitTypeDef PortA;
	GPIO_InitTypeDef PortE;
	
	/* GPIOA,E Periph clock enable */
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA | RCC_AHBPeriph_GPIOE, ENABLE);
	
	/* configure the output leds */
	PortE.GPIO_Pin = DISCOVERY_LD3 | DISCOVERY_LD4;
	PortE.GPIO_Speed = GPIO_Speed_50MHz;
	PortE.GPIO_Mode = GPIO_Mode_OUT;
	PortE.GPIO_PuPd = GPIO_PuPd_NOPULL;
	/* Use Push-Pull mode, actively drive high and low */ 
	PortE.GPIO_OType = GPIO_OType_PP;
	
	GPIO_Init(GPIOE, &PortE);
	
	/* Enable the USART2 Periph Clock */
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);
	
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource2, GPIO_AF_7);
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource3, GPIO_AF_7);
	
	/* Configure USART2 pins RX/TX pins */
	/* PA2 Tx, PA3 Rx */
	PortA.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3;
	PortA.GPIO_Speed = GPIO_Speed_50MHz;
	PortA.GPIO_Mode = GPIO_Mode_AF;
	PortA.GPIO_PuPd = GPIO_PuPd_NOPULL;
	PortA.GPIO_OType = GPIO_OType_PP;
	GPIO_Init(GPIOA, &PortA);
	
	USART_InitTypeDef USART2_Config;
	/* Configure USART2 */
	USART2_Config.USART_BaudRate = 9600;
	USART2_Config.USART_WordLength = USART_WordLength_8b;
	USART2_Config.USART_StopBits = USART_StopBits_1;
	USART2_Config.USART_Parity = USART_Parity_No;
	USART2_Config.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART2_Config.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	
	USART_Init(USART2, &USART2_Config);
	
	/* Enable USART2 */
	USART_Cmd(USART2, ENABLE);
	
	GPIO_WriteBit(GPIOE, DISCOVERY_LD3, Bit_SET);
	GPIO_WriteBit(GPIOE, DISCOVERY_LD4, Bit_SET);
	/* Send "OK" on the serial port to show it works */
	USART_SendData(USART2, 'O');
	while (USART_GetFlagStatus(USART2, USART_FLAG_TXE) == RESET);
	USART_SendData(USART2, 'K');
	/**** Configure System Vars ****/
	
	s_vars->engine_rpm = 0000;
	s_vars->throttle_percentage = p00;
	
	/**** Transition to the Ready State ****/
	return RDY_STATE;
}

State ready_state(System_Vars *s_vars)
{
	while(1) {
		/* Check if we got a serial message */
		if (USART_GetFlagStatus(USART2, USART_FLAG_RXNE)) {
			USART_SendData(USART2, USART_ReceiveData(USART2));
			/** Print out engine rpm **/
			
		}
	}
}

int main(void)
{
	//Configure our I/O
	
	//Spin up the state machine
	State_Machine s;
	System_Vars s_vars;
	
	s.state_table[ILLEGAL_STATE] = illegal_state;
	s.state_table[INIT_STATE] = init_state;
	s.state_table[RDY_STATE] = ready_state;
	s.state_table[NUM_STATES] = illegal_state;
	s.current_state = INIT_STATE;
	while(1)
	{
		s.current_state = s.state_table[s.current_state](&s_vars);
	}

}