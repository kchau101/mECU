#include "uart.h"
#include "stm32f30x_usart.h"

/** @brief Initialises printer obj with default values
*/
void initPrinter(Print *print_obj)
{
	// Configure the read and write pointers to point to the start of the buffer
	// Also clear the buffer;
	print_obj->read_pos = 0;
	print_obj->write_pos = 0;
	print_obj->buffer[0] = 0;
}
/** @brief Updates the print queue with the new data. 
*/
void print(Print *print_obj, char *cbuf, uint16_t len) {
	/* Check if our string was longer than the buffer */
	if (len > PRINT_BUF_LEN)
	{
		// DO SOMETHING
	}
	else 
	{
		for (uint16_t i = 0; i < len; i++ )
		{
			print_obj->buffer[(print_obj->write_pos + i) % PRINT_BUF_LEN] = cbuf[i];
		}
		print_obj->write_pos = (print_obj->write_pos + len) % PRINT_BUF_LEN;
	}
}

void processPrint(Print *print_obj) 
{
	// Check if the transmit buffer is empty
	if (USART_GetFlagStatus(USART2, USART_FLAG_TXE) == SET) {
		//If so, check if we have data to send
		if (print_obj->read_pos != print_obj->write_pos) 
		{
			// Write and increment the pointer
			USART_SendData(print_obj->usart, print_obj->buffer[print_obj->read_pos]);
			print_obj->read_pos = (print_obj->read_pos + 1) % PRINT_BUF_LEN;
		}
	}
}
