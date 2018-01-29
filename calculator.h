/*
 * calculator.h
 *
 * Created: 02/09/2016 09:12:12 ص
 *  Author: Masria For PCs
 */ 


#ifndef CALCULATOR_H_
#define CALCULATOR_H_
#include "Keypad.h"
#include "lcd_4bit.h"
#include <avr/io.h>
#define F_CPU 8000000ul
#include <util/delay.h>

void calculator_init(void);
int calculator_readNum(void);
int calculator_readOperation(void);
void calculator_guide(void);
void calculator_run(void);





#endif /* CALCULATOR_H_ */