/*
 * UART.h
 *
 * Created: 2/2/2025 10:55:36 PM
 *  Author: Lenovo
 */ 


#ifndef UART_H_
#define UART_H_
#include <avr/io.h>
typedef unsigned char boolean;
typedef signed char sint8;
typedef unsigned char uint8;
typedef signed short int sint16;
typedef unsigned short int uint16;
typedef signed  long sint32;
typedef unsigned  long uint32;
typedef signed  long long sint64;
typedef unsigned  long long uint64;
#define SET_BIT(reg,bit)  (reg=reg|(1<<bit))
#define CLEAR_BIT(reg,bit)  (reg=reg & ~(1<<bit))
#define TOGGLE_BIT(reg,bit)  (reg=reg^(1<<bit))
#define READ_BIT(reg,bit)  ((reg>>bit)&1)

void UART_Init (void);
void UART_Send (uint8);
uint8 UART_Receive (void);
void UART_Send_String(char * string);
void UART_Receive_String(char * buffer); 
char UART_Receive_P_check(char * data);
void UART_Send_asynch(char *str);

/******* Tx/Rx Interrupt Enable *******/
void UART_Tx_Interrupt_Enable(void);

void UART_Rx_Interrupt_Enable(void);



void UART_Tx_Interrupt_Disable(void);


void UART_Rx_Interrupt_Disable(void);



void UART_Send_NoBlock(uint8 data);


uint8 UART_Receive_NoBlock(void);
void UART_Receive_asynch(char * str);


#endif /* UART_H_ */