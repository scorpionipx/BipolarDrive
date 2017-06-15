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
#include <stdlib.h>
#include "IPX_LCD_Display.h"
#include "IPX_Interrupt.h"
#include "IPX_BipolarDriver.h"
#include "IPX_UART.h"

int main(void)
{
	ANGLE = 0;
	ROTATIONS = 0;
	LAST_STEP = BIPOLAR_STEP_NULL;
	DESIRED_ANGLE = 0;
	
	init_UART();
	init_LCD_Display();
	init_interrupt_200ms();
	init_bipolar_control();
	
	_delay_ms(50);
	
	display_application_title();
	_delay_ms(1000);
	
	put_Char_LCD_Display(0x01, 0);
	put_Char_LCD_Display(0x80, 0);
	put_string("ANGLE TARGET DIF");
	_delay_ms(1500);
	sei();
	
    while (1) 
    {
		//bipolar_wave_drive_forward();
		//bipolar_high_torque_full_step_drive_forward();
		
		//bipolar_forward_half_step_drive_forward();
		//_delay_ms(500);
		//if((abs(ANGLE - DESIRED_ANGLE)) >= (STEP_DEGREES))
		{
			spin_to_angle();
		}
    }
}

