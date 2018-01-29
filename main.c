/*
 * game.c
 *
 * Created: 8/25/2016 9:00:16 PM
 * Author : lenovo
 */ 

#include <avr/io.h>
#include "Time.h"
#include "game.h"
#include "interface.h"
#include "LM35.h"
#include "EEPROM.h"
#include "NameList.h"
#include "calculator.h"
#include "converter.h"

int main(void)
{
lcd_init();
keypad_init();
NameList_init();
LM35_init(0,5,1024);
Welcome();
//for(int i=0;i<1023;i++) EEPROM_write(i,0);        //Erase EEPROM	
	int key=0;
	while(1)
	{
		key=Menu(key);
		switch (key)
		{
			case 0:
			{
				lcd_clrScreen();
				DisplayList();
				newName();
				/*while(newName()){
					lcd_clrScreen();
				} //list of names*/
				lcd_clrScreen();
				break;
			}
			case 1:
			{		lcd_clrScreen();
				Get_Time();//time
				lcd_clrScreen();
				break;

			}
			case 2:
			{
				//temp
				lcd_clrScreen();
				Dis_Temperature();
				break;

			}
			case 3:
			{
				//calculator
				lcd_clrScreen();
				calculator_run();
				break;

			}
			case 4:
			{
				//game
				lcd_clrScreen();
				Game_Play();
				break;
			}
			
			
		}
		
	}
}

