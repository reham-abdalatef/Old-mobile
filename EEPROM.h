/*
 * EEPROM.h
 *
 * Created: 9/2/2016 7:46:39 PM
 *  Author: lenovo
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_



void EEPROM_write(unsigned int uiAddress, unsigned char ucData);
unsigned char EEPROM_read(unsigned int uiAddress);


#endif /* EEPROM_H_ */