/*
 * Time.h
 *
 * Created: 8/29/2016 10:40:29 PM
 *  Author: lenovo
 */ 

#ifndef TIME_H_
#define TIME_H_


#define DS1307_ID 0xD0     // DS1307 ID
#define SEC_ADDRESS   0x00 // Address to access Ds1307 SEC register
#define DATE_ADDRESS  0x04 // Address to access Ds1307 DATE register
#define CONTROL 0x07       // Address to access Ds1307 CONTROL register

void Get_Time();
void Set();

#endif /* TIME_H_ */