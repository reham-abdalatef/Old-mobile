#include "StdTypes.h"
#include <util/delay.h>
#include <avr/io.h>
#include "lcd_4bit.h"
#include "Keypad.h"
#include "DIO.h"
#include "NameList.h"
#include "EEPROM.h"
int addCounter = 0 ;

void NameList_init(void){
	
		addCounter = (int)EEPROM_read(0)*20+1;
}


void DisplayList(void){
	int listSize = EEPROM_read(0);
	lcd_dispString("Name list:");
	for(int i=0; i<listSize ; i++){
		while(kpad_read()!='#');
		lcd_clrScreen();
		for(int j=i*20+1; j<i*20+11; j++){
			lcd_displayChar(EEPROM_read(j));
		}
		lcd_gotoxy(0,1);
		for(int j=i*20+11; j<i*20+21; j++){
			lcd_displayChar(EEPROM_read(j));
		}
	}
	while(kpad_read()!='#');
	lcd_clrScreen();
}


int newName(void){
	char okay[9][4] = {
	{'1','a','b','c'},
	{'2','d','e','f'},
	{'3','g','h','i'},
	{'4','j','k','l'},
	{'5','m','n','o'},
	{'6','p','q','r'},
	{'7','s','t','u'},
	{'8','v','w','x'},
	{'9','y','z',':'}
	};
	char name[10]={0,0,0,0,0,0,0,0,0,0};
	char num[10]={0,0,0,0,0,0,0,0,0,0};
	char key = 0, value ;
	int charCounter= 0,lcdCounter = 0,numCounter = 0, stringCounter = 0;
	
	while(key !='0'||lcdCounter<=10){
		charCounter = 0;
		key = 0;
		do{
			
			value = key;
			
			key = kpad_read();
			if(key == '#')
			{break;}
			if(charCounter != 0)
			{
				lcd_disp_char_xy(' ',0,lcdCounter);
			}
			
				
			charCounter++ ;
			
			lcd_disp_char_xy(okay[key-'1'][charCounter%4],0,lcdCounter);
			if(key == '0'){
				goto xd;
			}
			
			if(key != value && key !='#') {
				charCounter=0;
			}
			
}while(key != '#') ;
key = value ;
if(key >= '1' && key <= '9'){
	/*lcd_gotoxy(lcdCounter,0);
	lcd_displayChar(okay[key-'1'][charCounter%4]);*/
	name[stringCounter++]=okay[key-'1'][charCounter%4];
	lcdCounter++ ;
}

}
xd :
stringCounter = 0;


lcd_gotoxy(0,1);
key = 0;
while(key!='#'||numCounter<=10){
	key = kpad_read();
	switch(key){
		case '0': lcd_displayChar('0');
		num[stringCounter++]='0';
		break;
		case '1': lcd_displayChar('1');
		num[stringCounter++]='1';
		break;
		case '2': lcd_displayChar('2');
		num[stringCounter++]='2';
		break;
		case '3': lcd_displayChar('3');
		num[stringCounter++]='3';
		break;
		case '4': lcd_displayChar('4');
		num[stringCounter++]='4';
		break;
		case '5': lcd_displayChar('5');
		num[stringCounter++]='5';
		break;
		case '6': lcd_displayChar('6');
		num[stringCounter++]='6';
		break;
		case '7': lcd_displayChar('7');
		num[stringCounter++]='7';
		break;
		case '8': lcd_displayChar('8');
		num[stringCounter++]='8';
		break;
		case '9': lcd_displayChar('9');
		num[stringCounter++]='9';
	}
	numCounter++ ;
}



stringCounter = 0;
SavingName(name,num);
for(int i=0;i<10;i++){
	name[i]=0;
	num[i]=0;
}
_delay_ms(3000);
lcd_clrScreen();
lcd_dispString("Add new name ?");
lcd_gotoxy(0,1);
lcd_dispString("1-Yes  2-No");
while(1){
	char k = kpad_read();
	if(k=='1')
	return 1;
	if(k=='2')
	return 0;
}
return 0;
}


void SavingName (char name[], char num[]){
	
	
	for(int i=0; i<10; i++){
		EEPROM_write(addCounter++,name[i]);
	}
	for(int i=0; i<10; i++){
		EEPROM_write(addCounter++,num[i]);
	}
	EEPROM_write(0,EEPROM_read(0)+1);
	lcd_clrScreen();
	lcd_dispString("Name saved !");
}