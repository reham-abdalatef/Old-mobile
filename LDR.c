/*
 * LDR.c
 *
 * Created: 18-Jul-16 9:40:14 PM
 *  Author: Pixels
 */ 

/************************************************************************/
/* with the help of the ADC driver build the LDR driver
	please note that we use multi layer desing in here , where tha ADC driver is a lower layer and the 
	LDR is an upper layer above the ADC and then come the program it self 
	there may also be other layers between the app and the ADC and LDR layer       */
/************************************************************************/

#include "LDR.h"
#include "ADC.h"
void LDR_inti()
{
	/**write your code here*/
	ADC_Init();
}

u16 LDR_read(u16 channel)
{
	/**write your code here*/
	return ADC_read(channel);
}
