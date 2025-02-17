/*
 * UART.c
 *
 * Created: 2/2/2025 10:55:51 PM
 *  Author: Lenovo
 */ 
#include "UART.h"
#include <avr/interrupt.h>
#include <string.h>

char buffer [100];
static char flag =1;
static char * G_TX_str  ;
static char  * G_RX_str  ;


void UART_Init (void)
{
	//1-boadRate 	
	// set u2x to zero 
	CLEAR_BIT(UCSRA,U2X);
	// select async mode 
	//CLEAR_BIT(UCSRC,UMSEL); the problem is here
	// set bode rate to 9600 at 8MHZ freq
	UBRRL = 51;
	//========================================//
	//2-framing
	// no parity mode
	CLEAR_BIT(UCSRC,UPM0);
	CLEAR_BIT(UCSRC,UPM1);
	// use one stop bit
	CLEAR_BIT(UCSRC,UPM1);
	// use 8 bit data mode  011
	SET_BIT(UCSRC,UCSZ0);
	SET_BIT(UCSRC,UCSZ1);
	CLEAR_BIT(UCSRB,UCSZ2);
	//========================================//
	//3-Enable
	SET_BIT(UCSRB,TXEN);
	SET_BIT(UCSRB,RXEN);
	//UCSRB
}



/******* Tx/Rx Interrupt Enable *******/
void UART_Tx_Interrupt_Enable(void)
{
	SET_BIT(UCSRB,TXCIE);
}
void UART_Rx_Interrupt_Enable(void)
{
	SET_BIT(UCSRB,RXCIE);
}


void UART_Tx_Interrupt_Disable(void)
{
	CLEAR_BIT(UCSRB,TXCIE);
}

void UART_Rx_Interrupt_Disable(void)
{
	CLEAR_BIT(UCSRB,RXCIE);
}


void UART_Send_NoBlock(uint8 data)
{
	UDR = data;
}

uint8 UART_Receive_NoBlock(void)
{
	return UDR;
}








void UART_Send (uint8 data)
{
	while(!READ_BIT(UCSRA,UDRE));
	UDR=data;	
}
uint8 UART_Receive (void)
{
		while(!READ_BIT(UCSRA,RXC));
		return UDR;
}

void UART_Send_String(char * string)
{
	int i = 0 ;
	for (i=0;string[i]!=0;i++)
	{
	
		UART_Send(string[i]);
	}
	UART_Send('\r');
	
}



void UART_Receive_String (char * buffer)
{
	char i = 0 ;
	buffer[i]=UART_Receive();
	while(buffer[i]!='\r')
	{
		i++;
		buffer[i]=UART_Receive();
	}
	buffer[i]='\0';
}
char UART_Receive_P_check(char * data)
{
	if(READ_BIT(UCSRA,RXC))
	{
		
		*data = UDR;
		return	1 ;
	}
	return 0;
}


void UART_Send_asynch(char *str)// ahmed 
{
	if(flag==1)
	{
		UART_Tx_Interrupt_Enable();
		UART_Send_NoBlock(str[0]);
		G_TX_str=str;
		flag = 0;
	}
	
}
void UART_Receive_asynch(char * str)
{
		UART_Rx_Interrupt_Enable();
		//str[0]=UART_Receive_NoBlock();
		G_RX_str=str;
}

ISR(USART_TXC_vect)
{						
	static unsigned char i =1; 
	if(G_TX_str[i] != 0)
	{
		UART_Send_NoBlock(G_TX_str[i]);
		i++;
	}
	else
	{
		i=1;
		flag=1;
	}
	
}
ISR(USART_RXC_vect)
{						
	static unsigned char i =-1; 
	static unsigned char i_flag =0; 
	char res =UART_Receive_NoBlock();
	if(res!='\r')	
	{
		i++;
		G_RX_str[i]=res;		
	}
	else
	{
		memset(G_RX_str,0,100);
		i=-1 ;
		//LCD_GOTO_XY(1,0);
		//LCD_WRITE_STRING(G_RX_str);

	}

}

