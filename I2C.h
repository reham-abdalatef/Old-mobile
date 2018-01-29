/*
 * I2C.h
 *
 * Created: 3/12/2014 12:05:49 PM
 *  Author: Mohamed Tarek
 */ 


#ifndef I2C_H_
#define I2C_H_

#include<avr/io.h>


#define TW_START         0x08 // start has been sent
#define TW_REP_START     0x10 // repeated start 
#define TW_MT_SLA_W_ACK  0x18 // ( slave address + Write have been sent ) + Ack received from slave
#define TW_MT_SLA_R_ACK  0x40 // ( slave address + Read have been sent ) + Ack received from slave
#define TW_MT_DATA_ACK   0x28 // Data byte has been transmitted and ACK has been received from Slave.
#define TW_MR_DATA_ACK   0x50 // Master received data and send ACK
#define TW_MR_DATA_NACK  0x58 // MAster received data but don't send ACK


void TWI_Init(void);
void TWI_Start(void);
void TWI_Stop(void);
void TWI_Write(unsigned char data);
unsigned char TWI_Read_With_ACK(void); //read with send Ack
unsigned char TWI_Read_With_NACK(void); //read without send Ack
unsigned char TWI_Get_Status(void);


#endif /* I2C_H_ */