/*
 * task_2.c
 *
 * Created: 11/29/2024 6:30:12 PM
 * Author : Lenovo
 */ 

#define  F_CPU 8000000UL
#include "Utils.h"
#include "memory_map.h"
#include <util/delay.h>
int i = 5 ;
int main(void)
{
	SET_BIT(DDRD,5);
	SET_BIT(DDRD,6);
	SET_BIT(DDRD,7);
	CLEAR_BIT(DDRD,0);
    while (1) 
    {
		
		if (READ_BIT(PIND,0)==1)
		{
			SET_BIT(PORTD,i);
			while(READ_BIT(PIND,0)==1);
			i++;
			if(i==7) continue;
		}
    }
}

