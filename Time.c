/*
 * Time.c
 *
 * Created: 8/29/2016 10:28:54 PM
 *  Author: 
 */
#include "StdTypes.h"
#include <avr/io.h>
#include <util/delay.h>

#include "Time.h" 
#include "RTC_Manager.h"
#include "lcd_4bit.h"
#include "Keypad.h"



void Get_Time()
{
	while(1)
	{lcd_gotoxy(0,0);
	lcd_dispString(RTC_strClock());
     lcd_gotoxy(0,1);
	 lcd_dispString( RTC_strDate());
	 _delay_ms(1000);
	 lcd_clrScreen();
	}
}


void Set()
{u8 d,m,y,h;
	lcd_dispString("Enter date d/m/y");
	lcd_gotoxy(0,1);
	d = keypad_read();
	lcd_displayChar(d);
	lcd_displayChar('/');
	m = keypad_read();
	lcd_displayChar(m);
	lcd_displayChar('/');
	y = keypad_read();
	lcd_displayChar(y);
	DS1307_SetDate(d,m,y);
	_delay_ms(300);
	lcd_clrScreen();
	lcd_dispString("Enter Time h:m");
	lcd_gotoxy(0,1);
	h = keypad_read();
	lcd_displayChar(h);
	lcd_displayChar('/');
	m = keypad_read();
	lcd_displayChar(m);
	DS1307_SetTime(h,m,'0');
_delay_ms(200);
lcd_clrScreen();
	
}