/*
 * BipolarDriver.c
 *
 * Created: 10-Jun-17 4:06:01 PM
 * Author : uidq6025
 */ 

#include "Global.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "IPX_LCD_Display.h"
#include "IPX_Interrupt.h"
#include "IPX_BipolarDriver.h"

int main(void)
{
	init_LCD_Display();
	init_interrupt_200ms();
	init_bipolar_control();
	sei();
	
	_delay_ms(50);
	
	display_application_title();
	
    while (1) 
    {
		bipolar_drive_forward();
    }
}

