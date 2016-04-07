#ifndef UART_COMM_H
#define UART_COMM_H

#define PRINT_BUF_LEN 81

typedef struct print {
	USART_TypeDef *usart;
	char buffer[PRINT_BUF_LEN];
	uint8_t read_pos;
	uint8_t write_pos;
} Print;

void configPrint(Print*);
void print(Print*, char*, uint16_t );
void ftoa(float, char*, uint8_t);
void processQueue();
#endif