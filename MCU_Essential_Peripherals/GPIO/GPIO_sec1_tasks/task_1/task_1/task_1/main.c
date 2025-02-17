/*
 * main.c
 *
 * Created: 11/29/2024 3:30:26 PM
 *  Author: Lenovo
 */ 
#define F_CPU 8000000UL
#include "memory_map.h"
#include "Utils.h"
#include <util/delay.h>

int main(void)
{
	SET_BIT(DDRD,5);
	SET_BIT(DDRD,6);
	SET_BIT(DDRD,7);
    while(1)
    {
        int i ;
		for (i=5;i<=7;i++)
		{
			//_delay_ms(1000);
			SET_BIT(PORTD,i);
			_delay_ms(1000);
		}
		for (i=7;i>=5;i--)
		{
			//_delay_ms(1000);
			CLEAR_BIT(PORTD,i);
			_delay_ms(1000);
		}
    }
}