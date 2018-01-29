/*
 * RTC_Manager.h
 *
 * Created: 17-Dec-15 8:34:13 PM
 *  Author: LENOVO
 */ 


#ifndef RTC_MANAGER_H_
#define RTC_MANAGER_H_
#include "StdTypes.h"
#include "I2C.h"
#define SLA_W  0b11010000
#define SLA_R   0b11010001
#define SECONDS 0x00
#define MINUTES 0x01
#define HOURS 0x02
#define DAY 0x03
#define DATE 0x04
#define MONTH 0x05
#define YEAR 0x06

void RTC_vidInit( void );
u8 RTC_getSeconds( void );
u8 RTC_getMinutes( void );
u8 RTC_getHours( void );
u8 RTC_getDay( void );
u8 RTC_getDate( void );
u8 RTC_getMonth( void );
u8 RTC_getYear( void ) ;
char * RTC_strClock( void );
char* RTC_strDate ( void );







#endif /* RTC_MANAGER_H_ */