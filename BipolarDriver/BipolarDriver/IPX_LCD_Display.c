/*
 * IPX_LCD_Display.c
 *
 * Created: 22.03.2016 16:53:29
 *  Author: ScorpionIPX
 */ 

#include "Global.h"
#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include "IPX_LCD_Display.h"

#define MAX_CHARS_PER_ROW 16


void put_Char_LCD_Display(int ch, int type)
{
	PORTC = (PORTC&0x0F)|(ch&0xF0);
	PORTC = (PORTC&0xFE)|(type&0x01);
	PORTC = PORTC|0x02;
	_delay_ms(LCD_DELAY_MS);
	PORTC &= 0xFC;
	PORTC = (PORTC&0x0F)|((ch<<4)&0xF0);
	PORTC = (PORTC&0xFE)|(type&0x01);
	PORTC = PORTC|0x02;
	_delay_ms(LCD_DELAY_MS);
	PORTC &= 0xFC;
}

void init_LCD_Display(void)
{
	DDRC = 0xFF;
	put_Char_LCD_Display(0x03,0);
	_delay_ms(LCD_INIT_DELAY_MS);
	put_Char_LCD_Display(0x03,0);
	_delay_ms(LCD_INIT_DELAY_MS);
	put_Char_LCD_Display(0x03,0);
	_delay_ms(LCD_INIT_DELAY_MS);
	put_Char_LCD_Display(0x02,0);
	_delay_ms(LCD_INIT_DELAY_MS);
	put_Char_LCD_Display(0x0C,0);
	_delay_ms(LCD_INIT_DELAY_MS);
	put_Char_LCD_Display(0x01,0);
	_delay_ms(LCD_INIT_DELAY_MS);
	put_Char_LCD_Display(0x80,0);
	_delay_ms(LCD_INIT_DELAY_MS);
	put_Char_LCD_Display(0x01,0);//clear display
}

// display string
void put_string(const char *_string)
{
	int ch_index;
	for(ch_index=0;ch_index<strlen(_string);ch_index++)
	{
		put_Char_LCD_Display(_string[ch_index], 1);
	}
}

void display_initializing_message()
{
	put_Char_LCD_Display(0x01,0);
	
	put_Char_LCD_Display(0x80, 0);
	put_string("Initializing...");
}

void display_application_title()
{
	put_Char_LCD_Display(0x01, 0);
	put_Char_LCD_Display(0x80, 0);
	put_string("BIPOLAR DRIVER");
	put_Char_LCD_Display(0xC0, 0);
	put_string("   SCORPIONIPX");
}

