/*
 * LDR.h
 *
 * Created: 18-Jul-16 9:39:59 PM
 *  Author: Pixels
 */ 


#ifndef LDR_H_
#define LDR_H_

#include "StdTypes.h"

/**initialize the LDR sensor in a specific channel*/
void LDR_inti() ;

/**return the reading in values from 0 to 100 for simplification*/
u16 LDR_read(u16 channel) ;



#endif /* LDR_H_ */