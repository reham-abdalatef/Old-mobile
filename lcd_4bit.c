/**
* LCD_4bit.c
* Author :  Pixels
*/
#include "StdTypes.h"
#include "lcd_4bit.h"
#include "macros.h"
#include <util/delay.h>
#include <stdlib.h>

/////////////////////////////////////////////////////////////////////
//	LCD enable triggering function to make LCD aware about command or
//   data changes.
////////////////////////////////////////////////////////////////////
void lcd_sendCommand(unsigned char cmd);


void enableTrigger(void)
{

	CLR_BIT(LCD_ConfgData.CmdPort,LCD_E);
	_delay_us(500);

	SET_BIT(LCD_ConfgData.CmdPort,LCD_E);
	_delay_us(1500);


}
///////////////////////////////////////////////////////////////////////////////////////
// LCD initialization  
//////////////////////////////////////////////////////////////////////////////////////
void lcd_init(void)
{

	// initialize the LCD pins 
	DIO_InitPortDirection(LCD_ConfgData.CmdPort , 0xFF , (1<<LCD_E | 1<<LCD_RS | 1<<LCD_RW));
	DIO_InitPortDirection(LCD_ConfgData.DataPort, 0xFF , LCD_ConfgData.DataMask);
	 // activate LCD enable 
	SET_BIT(LCD_ConfgData.CmdPort , LCD_E);
	 // 4-bit mode - 2 line mode  
	lcd_sendCommand(0x33); 
	lcd_sendCommand (0x32);
	lcd_sendCommand (0x28);



	lcd_sendCommand(0x0c); // turn on LCD 

		
}


void lcd_sendCommand(unsigned char cmd)
{

	unsigned char high_nibble , low_nibble ; 		
	
	HIGH_NIBBLE(high_nibble,cmd);
	LOW_NIBBLE(low_nibble,cmd);

	CLR_BIT(LCD_ConfgData.CmdPort,LCD_RS); // to enable command mode 
	CLR_BIT(LCD_ConfgData.CmdPort,LCD_RW); // write signal to LCD 

	
	// to send high nibble command
	DIO_WritePort(LCD_ConfgData.DataPort , high_nibble , LCD_ConfgData.DataMask); 
	enableTrigger(); // triggre lcd enable 


	// to send low nibble command 
	DIO_WritePort(LCD_ConfgData.DataPort , low_nibble , LCD_ConfgData.DataMask);
	enableTrigger();

}

void lcd_displayChar (unsigned char data)
{

	unsigned char high_nibble , low_nibble ;

	SET_BIT(LCD_ConfgData.CmdPort,LCD_RS); //  enable data mode 
	CLR_BIT(LCD_ConfgData.CmdPort,LCD_RW); // activate LCD write 

	HIGH_NIBBLE(high_nibble,data); // get high nibble data 
	LOW_NIBBLE(low_nibble,data); // get low nibble data 
	
	
	// to send high nibble data
	DIO_WritePort(LCD_ConfgData.DataPort , high_nibble , LCD_ConfgData.DataMask);  
	enableTrigger(); // triggre lcd enable 
	
	
	// to send low nibble data 
	DIO_WritePort(LCD_ConfgData.DataPort , low_nibble , LCD_ConfgData.DataMask);
	enableTrigger();
	

}

void lcd_gotoxy(unsigned char x , unsigned char y )
{
	unsigned char position = 0x80;
	 
	switch(y)
	{
		case 0:

			position=position+x;
					
		break;

		case 1:

			position=0xc0;
			position=position+x;

		break;

		case 2:

			position=position+x;

		break;

		case 3:
			position=position+x;
		break;
	
	
	}
	
	lcd_sendCommand(position); 	


}


void lcd_clrScreen(void)
{

	lcd_sendCommand(0x01);


}


void lcd_dispString(char * ptr)
{
	/**write your code here*/
	int i=0;
	while(ptr[i] !='\0')
	{lcd_displayChar(ptr[i]);
		i++;
	}
	
}

void lcd_disp_string_xy(char * ptr , int y , int x)
{
	/**write your code here*/
	lcd_gotoxy(x,y);
	lcd_dispString(ptr);
}

void lcd_displayInt( int data)
{
	/**write your code here*/
		char s[5];
		data %=10000;
		itoa(data ,s , 10);
		lcd_dispString(s);
}

void lcd_disp_char_xy(char ptr,int y,int x)
{
	lcd_gotoxy(x,y);
lcd_displayChar(ptr);
}