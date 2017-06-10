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

// 200ms ISR
ISR (TIMER1_COMPA_vect)
{
}
