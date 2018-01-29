/*
 * Lm35.h
 *
 * Created: 18-Jul-16 10:02:18 PM
 *  Author: Pixels
 */ 


#ifndef LM35_H_
#define LM35_H_

#include "StdTypes.h"

void	LM35_init(u8 ADCpin , float referenceVoltage , u16 adcResolution);
float	LM35_floatRead() ;
u8		LM35_u8Read() ;


#endif /* LM35_H_ */