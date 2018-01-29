/*
 * EEPROM.c
 *
 * Created: 9/2/2016 7:46:25 PM
 *  Author: lenovo
 */ 
#include <avr/io.h>
#include "EEPROM.h"
#include "macros.h"
#include "lcd_4bit.h"
#include "StdTypes.h"


void EEPROM_write(unsigned int uiAddress, unsigned char ucData)
{
	while(EECR & (1<<EEWE))
	;
	EEAR = uiAddress;
	EEDR = ucData;
	EECR |= (1<<EEMWE);
	EECR |= (1<<EEWE);
}


unsigned char EEPROM_read(unsigned int uiAddress)
{
	while(EECR & (1<<EEWE))
	;
	EEAR = uiAddress;
	EECR |= (1<<EERE);
	return EEDR;
}