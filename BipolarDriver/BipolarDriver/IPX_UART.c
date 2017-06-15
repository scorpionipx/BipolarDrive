/*
 * IPX_UART.c
 *
 * Created: 02.04.2016 00:49:25
 *  Author: Dan
 */ 

#include "Global.h"
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "IPX_UART.h"
#include "IPX_BipolarDriver.h"
#include "IPX_LCD_Display.h"

#define USART_BAUDRATE 9600
#define BAUD_PRESCALE (((F_CPU / (USART_BAUDRATE * 16UL))) - 1)

#define RECEIVING_STATE_ID 0
#define RECEIVING_STATE_DATA_1 1
#define RECEIVING_STATE_DATA_2 2

volatile unsigned char received_command;
volatile unsigned int receiving_state = RECEIVING_STATE_ID;
unsigned char command_id = 0;
uint16 received_data;

void init_UART(void)
{
	UCSRB = (1 << RXEN) | (1 << TXEN);   // Turn on the transmission and reception circuitry
	UCSRC = (1 << URSEL) | (1 << UCSZ0) | (1 << UCSZ1); // Use 8-bit character sizes

	UBRRH = (BAUD_PRESCALE >> 8); // Load upper 8-bits of the baud rate value into the high byte of the UBRR register
	UBRRL = BAUD_PRESCALE; // Load lower 8-bits of the baud rate value into the low byte of the UBRR register

	UCSRB |= (1 << RXCIE); // Enable the USART Recieve Complete interrupt (USART_RXC)
}

ISR(USART_RXC_vect)
{
	received_command = UDR; // Fetch the received byte value into the variable "ByteReceived"
	
	uart_command(received_command);
	
	//UDR = received_command; // Echo back the received byte back to the computer
}

void uart_command(unsigned char _command)
{
	switch(receiving_state)
	{
		default:
		{
			UDR = _command;
			break;
		}
		case RECEIVING_STATE_ID:
		{
			receiving_state = RECEIVING_STATE_DATA_1;
			
			command_id = _command;
			received_data = 0;
			
			break;
		}
		case RECEIVING_STATE_DATA_1:
		{
			receiving_state = RECEIVING_STATE_DATA_2;
			
			received_data = _command;
			
			break;
		}
		case RECEIVING_STATE_DATA_2:
		{
			receiving_state = RECEIVING_STATE_ID;
			
			received_data <<= 8;
			received_data |= _command;
			
			DESIRED_ANGLE = received_data;
			
			break;
		}
	}
}