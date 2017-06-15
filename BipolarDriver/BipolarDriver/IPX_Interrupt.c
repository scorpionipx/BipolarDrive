/*
 * IPX_Interrupt.c
 *
 * Created: 22.03.2016 20:52:05
 *  Author: ScorpionIPX
 */ 


#include "Global.h"
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#include "IPX_LCD_Display.h"
#include "IPX_BipolarDriver.h"

#define TOGGLE_PWR_LED PORTB ^= (1 << 0)

#define INTERRUPT_200MS 200
#define SECOND 5

volatile int counter = 0;

// 200 ms timer
void init_interrupt_200ms()
{
	// set up timer with prescaler = 64 and CTC mode
	TCCR1B |= (1 << WGM12)|(1 << CS11)|(1 << CS10);
	
	// initialize counter
	TCNT1 = 0;
	
	// initialize compare value
	OCR1A = 49999;
	
	// enable compare interrupt
	TIMSK |= (1 << OCIE1A);
}

volatile int xcounter = 1;

// 200ms ISR
ISR (TIMER1_COMPA_vect)
{
/*	put_Char_LCD_Display(0xC0, 0);
	put_Char_LCD_Display((ANGLE/1000)%10 + 48, 1);
	put_Char_LCD_Display((ANGLE/100)%10 + 48, 1);
	put_Char_LCD_Display((ANGLE/10)%10 + 48, 1);
	put_Char_LCD_Display('.', 1);
	put_Char_LCD_Display(ANGLE%10 + 48, 1);
	
	put_Char_LCD_Display(' ', 1);
	
	put_Char_LCD_Display((DESIRED_ANGLE/1000)%10 + 48, 1);
	put_Char_LCD_Display((DESIRED_ANGLE/100)%10 + 48, 1);
	put_Char_LCD_Display((DESIRED_ANGLE/10)%10 + 48, 1);
	put_Char_LCD_Display('.', 1);
	put_Char_LCD_Display(DESIRED_ANGLE%10 + 48, 1);
	
	put_Char_LCD_Display(' ', 1);*/
	if((abs(ANGLE - DESIRED_ANGLE)) > (STEP_DEGREES / 2))
	{
		//put_Char_LCD_Display('Y', 1);
	}
	else
	{
		//put_Char_LCD_Display('N', 1);
		MOTOR_OFF;
	}
	
	/*put_Char_LCD_Display((abs(ANGLE - DESIRED_ANGLE)/1000)%10 + 48, 1);
	put_Char_LCD_Display((abs(ANGLE - DESIRED_ANGLE)/100)%10 + 48, 1);
	put_Char_LCD_Display((abs(ANGLE - DESIRED_ANGLE)/10)%10 + 48, 1);*/
}
