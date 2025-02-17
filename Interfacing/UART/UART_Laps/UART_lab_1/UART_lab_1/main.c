/*
 * UART_lab_1.c
 *
 * Created: 2/2/2025 10:29:06 PM
 * Author : Ahmed Elnabawe
 */ 

#include <avr/io.h>
#include "LCD/LCD.h"
#include "UART/UART.h"
#include <avr/interrupt.h>
int x =0 ;
int y ;

int main(void)
{
	
    LCD_INIT();
	sei();
	/*reti();*/
	UART_Init();
	LCD_GOTO_XY(0,0);
//	LCD_WRITE_STRING("UART TR");
	//UART_Send('a');
	//UART_Send('h');
	//UART_Send('m');
	//UART_Send('e');
	//UART_Send('d');
	UART_Send_asynch("ahmed");
	UART_Send_asynch("reda");

	
    while (1) 
    {
		
//		if(UART_Receive_P_check(&y))
	//	{
	//		LCD_GOTO_XY(0,0);
	//		LCD_WRITE_CHAR(y);
	//	}
		char  string[100] ;
		LCD_GOTO_XY(1,0);
		UART_Receive_asynch(string);
		LCD_WRITE_STRING(string);
		
		LCD_GOTO_XY(0,0);
		LCD_WRITE_number(x);
		x++;
		if(x==10) x=0;
		_delay_ms(100);
		LCD_clear_screen();
    }
}

