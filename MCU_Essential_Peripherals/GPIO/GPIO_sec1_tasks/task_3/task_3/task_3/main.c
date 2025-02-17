/*
 * task_3.c
 *
 * Created: 11/29/2024 6:46:43 PM
 * Author : Lenovo
 */ 
#define F_CPU 8000000UL
#include "memory_map.h"
#include "Utils.h"
#include <util/delay.h>

int main(void)
{
	SET_BIT(DDRD,4);
	CLEAR_BIT(DDRD,0);
    while (1) 
    {
		if (READ_BIT(PIND,0)==1)
		{
			SET_BIT(PORTD,4);
			_delay_ms(1000);
			CLEAR_BIT(PORTD,4);
			while (READ_BIT(PIND,0)==1);
			
		}
    }
}

