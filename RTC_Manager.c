/*
 * RTC_Manager.c
 *
 * Created: 17-Dec-15 8:34:28 PM
 *  Author: Ali
 */ 
#include "RTC_Manager.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
u8 decoder(u8 data);
u8 getRTCdata(u8 address);
void RTC_vidInit( void )
{
	TWI_Init();
}

u8 RTC_getSeconds( void )
{
	u8 Sec ;
	Sec = getRTCdata(SECONDS);
	Sec = decoder(Sec);
	return Sec ;
}
u8 RTC_getMinutes( void )
{
	u8 Min;
	Min = getRTCdata(MINUTES);
	Min = decoder(Min);
	return Min ;
}
u8 RTC_getHours( void )
{
	u8 hours ;
	hours = getRTCdata(HOURS);
	hours = decoder(hours);
	return hours;
}
u8 RTC_getDay( void )
{
	u8 Day = 0x00 ;
	Day = getRTCdata(Day);
	Day = decoder(Day);
	return Day ;
}
u8 RTC_getDate( void )
{
	u8 date ;
	date = getRTCdata(DATE);
	date = decoder(date);
	return date ;
	
}
u8 RTC_getMonth( void )
{
	u8 month ; 
	month = getRTCdata(MONTH);
	month = decoder(month);
	return month;
}
u8 RTC_getYear( void ) 
{
	u8 year ; 
	year = getRTCdata(YEAR);
	year = decoder(year);
	return year; 
}
char * RTC_strClock( void )
{
	static char strClock[6] ;
	u8 hours , minutes ;
	hours = RTC_getHours();
	minutes = RTC_getMinutes();
	sprintf(strClock,"%02d:%02d",hours,minutes);
	return strClock ;
}
char* RTC_strDate ( void )
{
	static char strDate[9] ;
	u8 day , month , year ;
	day = RTC_getDate() ;
	month = RTC_getMonth();
	year = RTC_getYear();
	sprintf(strDate,"%02d/%02d/%02d",day,month,year);
	return strDate ;
}
u8 getRTCdata(u8 address)
{
	u8 data;
	TWI_Start();
	TWI_Write(SLA_W);
	TWI_Write(address);
	TWI_Start();
	TWI_Write(SLA_R);
	data = TWI_Read_With_NACK();
	TWI_Stop();
	return data ;
}

u8 decoder(u8 data)
{
	u8 ones , tens  , realValue;
	ones = data & 0x0F ;
	tens = data & 0xF0 ;
	realValue = (tens>>4) * 10 ;
	realValue += ones ;
	return realValue ;
}