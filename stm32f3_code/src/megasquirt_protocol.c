#include "megasquirt_protocol.h"
#include "stm32f30x_usart.h"
/**
 * @brief Respond to a Tuner Studio serial communications request
 */
void megasquirt_c_command(USART_TypeDef* USARTx) 
{
	// TODO Implement timer so we can send an actual uptime
	USART_SendData(USARTx, 0x0001);
}

/**
 * @brief Respond to a Tuner Studio serial data request, send all of our data; no CRC32
 */
void megasquirt_a_command(USART_TypeDef* USARTx, Megasquirt_RT_Data data) 
{
	uint8_t (*buffer)[MEGASQUIRT_RT_DATA_LENGTH + 1] = &data;
	for (uint8_t i = 0; i < MEGASQUIRT_RT_DATA_LENGTH; i++)
	{
		USART_SendData(USARTx, (uint16_t) buffer[i]);
	}
}