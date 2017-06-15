/*
 * IPX_UART.h
 *
 * Created: 02.04.2016 00:59:54
 *  Author: Dan
 */ 


#ifndef IPX_UART_H_
#define IPX_UART_H_

#include "Global.h"

void init_UART(void);
void uart_command(unsigned char _command);

#endif /* IPX_UART_H_ */