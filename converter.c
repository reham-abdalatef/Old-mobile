/*
 * converter.c
 *
 * Created: 8/21/2016 10:50:22 PM
 *  Author: lenovo
 */ 
#include "StdTypes.h"
#include <util/delay.h>
#include "converter.h"
#include "LM35.h"
#include "lcd_4bit.h"
#include "Keypad.h"
u16 Convert_F(u16 c)
{
	return (c+32);
}

u16 Convert_K(u16 c)
{
	return (c+273);
}

void Dis_Temperature()
{
	u8 ch,n;
	u8 f=0;
	while(1)
	{
		lcd_disp_char_xy('<',1,0);
	    ch=	LM35_u8Read();
		lcd_gotoxy(2,0);
		lcd_displayInt((int)(ch));
		lcd_disp_string_xy("C",1,2);
		lcd_gotoxy(5,0);
		lcd_displayInt((int)(Convert_F(ch)));
		lcd_disp_string_xy("F",1,5);
	    lcd_gotoxy(10,0);
	    lcd_displayInt((int)(Convert_K(ch)));
		lcd_disp_string_xy("K",1,10);
		_delay_ms(500);
		f=kd_read();
		lcd_clrScreen();
		if(f=='*'){break;}

	}
	
	
	
}
