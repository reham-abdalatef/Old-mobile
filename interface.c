/*
 * interface.c
 *
 * Created: 8/31/2016 1:50:19 AM
 *  Author: lenovo
 */ 
#include "interface.h"
#include "StdTypes.h"
#include "game.h"
#include "calculator.h"
#include "Time.h"
#include "lcd_4bit.h"
#include "Keypad.h"
#include <util/delay.h>


void Welcome()
{
lcd_disp_string_xy("WELCOME",0,4);
lcd_disp_string_xy("Press to Menu",1,0);
keypad_read();
lcd_clrScreen();
}
void Dis_Time_Mu()
{
lcd_disp_string_xy("Menu",0,5);
	lcd_disp_string_xy("<",1,0);
	lcd_disp_string_xy(">",1,15);
	lcd_disp_string_xy("Time,Date",1,2);
	
}

void Dis_Temp()
{
	lcd_disp_string_xy("Menu",0,5);
	lcd_disp_string_xy("<",1,0);
	lcd_disp_string_xy(">",1,15);
	lcd_disp_string_xy("Temperature",1,2);
	
}

void Dis_List_of_name()
{
	lcd_disp_string_xy("Menu",0,5);
	lcd_disp_string_xy("<",1,0);
	lcd_disp_string_xy(">",1,15);
	lcd_disp_string_xy("Contacts",1,3);
	
}
void Dis_Game()
{
	lcd_disp_string_xy("Menu",0,5);
	lcd_disp_string_xy("<",1,0);
	lcd_disp_string_xy(">",1,15);
	lcd_disp_string_xy("Game",1,6);
	
}
void Dis_calculator()
{
	lcd_disp_string_xy("Menu",0,5);
	lcd_disp_string_xy("<",1,0);
	lcd_disp_string_xy(">",1,15);
	lcd_disp_string_xy("calculator",1,2);
	
}
void menu_start(int counter)
{
	switch(counter)
	{
		case 0 :
		{
			Dis_List_of_name();
			break;
		}
		case 1 :
		{
			Dis_Time_Mu();
			break;
		}
		case 2 :
		{
			Dis_Temp();
			break;
		}
		case 3:
		{
			Dis_calculator();
			break;
		}
		case 4:
		{
			Dis_Game();
			break;
		}
	}
}

int Menu(int counter)
{
	u8 key;
menu_start(counter);
	while(1)
	{
		_delay_ms(200);
		key=keypad_read();
		if((key =='#') && (counter<4))
		{counter=counter +1;}
		else if((key =='*') && (counter>0))
		{counter=counter -1;}
		else if (key =='0')
		{break;}
		else {continue;}
		lcd_clrScreen();

	switch(counter)
{
		case 0 :
		{
			Dis_List_of_name();
			break;
		}	
		case 1 :
		{
		Dis_Time_Mu();
        break;
		}	
		case 2 :
		{
		Dis_Temp();
		break;
		}		
		case 3 :
		{
		Dis_calculator();
		break;	
		}
		case 4 :
		{
			 Dis_Game();
			 break;
		}
		
}

	}
	return counter;
}


void Simulation()
{
	int key=0;
	while(1)
	{
		key=Menu(key);
		switch (key)
		{
			case 0:
			{
			//list of names
			break;
			}
			case 1:
			{
				//time
				break;

			}
			case 2:
			{
				//temp
				break;

			}
			case 3:
			{
				//calculator
			
			break;

			}
			case 4:
			{
				//game
				Game_Play();
				break;
			}
			
			
		}
		
	}

}


