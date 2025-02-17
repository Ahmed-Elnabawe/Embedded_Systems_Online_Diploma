/*
 * keybad.c
 *
 * Created: 12/12/2024 8:54:14 PM
 *  Author: Lenovo
 */
#include "keybad.h" 
char keybad_rows[]={R0,R1,R2,R3};
char keybad_colns[]={c0,c1,c2,c3};
void KEYBAD_INIT(){
	KEYBAD_DATA_DIRECTION |=((1<<c0)|(1<<c1)|(1<<c2)|(1<<c3));
	KEYBAD_DATA_DIRECTION &=~((1<<R0)|(1<<R1)|(1<<R2)|(1<<R3));
	KEYBAD_PORT =0xff;
}
char KEYBAD_GET_KEY()
{
	int i ,j ;
	for (i=0;i<4;i++)
	{
		KEYBAD_PORT |= ((1<<keybad_colns[0])|(1<<keybad_colns[1])|(1<<keybad_colns[2])|(1<<keybad_colns[3]));
		KEYBAD_PORT&=~(1<<keybad_colns[i]);
		for (j=0;j<4;j++)
		{
			if(!(KEYBAD_PIN&(1<<keybad_rows[j])))
			{
				while(!(KEYBAD_PIN&(1<<keybad_rows[j])));
				switch(i){
					case(0):
						if (j == 0) return '7';
						else if (j == 1) return '4';
						else if (j == 2) return '1';
						else if (j == 3) return '?';
						break;
					case(1):
						if (j == 0) return '8';
						else if (j == 1) return '5';
						else if (j == 2) return '2';
						else if (j == 3) return '0';
						break;
					case(2):
						if (j == 0) return '9';
						else if (j == 1) return '6';
						else if (j == 2) return '3';
						else if (j == 3) return '=';
						break;
					case(3):
						if (j == 0) return '/';
						else if (j == 1) return '*';
						else if (j == 2) return '-';
						else if (j == 3) return '+';
						break;
					
				}
			}
		}
		
	}
	return 'A';
}