/*
 * keybad.c
 *
 * Created: 12/12/2024 8:54:14 PM
 *  Author: Lenovo
 */
#include "keybad.h" 
char keybad_rows[]={R0,R1,R2,R3};
uint16_t keybad_colns[]={c0,c1,c2,c3};
void KEYBAD_INIT(){
	//	KEYBAD_DATA_DIRECTION |=((1<<c0)|(1<<c1)|(1<<c2)|(1<<c3));
	GPIO_PinConfig_t pinCnfg;

	pinCnfg.PinNumber=c0;
	pinCnfg.PinMode=GPIO_MODE_Output_PP;
	pinCnfg.OutPutSpeed=GPIO_SPEED_10M;
	MCAL_GPIO_Init(KEYBAD_PORT,&pinCnfg);

	pinCnfg.PinNumber=c1;
	pinCnfg.PinMode=GPIO_MODE_Output_PP;
	pinCnfg.OutPutSpeed=GPIO_SPEED_10M;
	MCAL_GPIO_Init(KEYBAD_PORT,&pinCnfg);

	pinCnfg.PinNumber=c2;
	pinCnfg.PinMode=GPIO_MODE_Output_PP;
	pinCnfg.OutPutSpeed=GPIO_SPEED_10M;
	MCAL_GPIO_Init(KEYBAD_PORT,&pinCnfg);

	pinCnfg.PinNumber=c3;
	pinCnfg.PinMode=GPIO_MODE_Output_PP;
	pinCnfg.OutPutSpeed=GPIO_SPEED_10M;
	MCAL_GPIO_Init(KEYBAD_PORT,&pinCnfg);
	//	KEYBAD_DATA_DIRECTION &=~((1<<R0)|(1<<R1)|(1<<R2)|(1<<R3));
	pinCnfg.PinNumber=R0;
	pinCnfg.PinMode=GPIO_MODE_Output_PP;
	pinCnfg.OutPutSpeed=GPIO_SPEED_10M;
	MCAL_GPIO_Init(KEYBAD_PORT,&pinCnfg);

	pinCnfg.PinNumber=R1;
	pinCnfg.PinMode=GPIO_MODE_Output_PP;
	pinCnfg.OutPutSpeed=GPIO_SPEED_10M;
	MCAL_GPIO_Init(KEYBAD_PORT,&pinCnfg);

	pinCnfg.PinNumber=R2;
	pinCnfg.PinMode=GPIO_MODE_Output_PP;
	pinCnfg.OutPutSpeed=GPIO_SPEED_10M;
	MCAL_GPIO_Init(KEYBAD_PORT,&pinCnfg);

	pinCnfg.PinNumber=R3;
	pinCnfg.PinMode=GPIO_MODE_Output_PP;
	pinCnfg.OutPutSpeed=GPIO_SPEED_10M;
	MCAL_GPIO_Init(KEYBAD_PORT,&pinCnfg);

//	pinCnfg.PinNumber=R3;
//	pinCnfg.PinMode=GPIO_MODE_Output_PP;
//	pinCnfg.OutPutSpeed=GPIO_SPEED_10M;
//	MCAL_GPIO_Init(KEYBAD_PORT,&pinCnfg);
	//	KEYBAD_PORT =0xff;
	MCAL_GPIO_WritePort(KEYBAD_PORT,0xff);
}
char KEYBAD_GET_KEY()
{
	int i ,j ;
	for (i=0;i<4;i++)
	{
		//		KEYBAD_PORT |= ((1<<keybad_colns[0])|(1<<keybad_colns[1])|(1<<keybad_colns[2])|(1<<keybad_colns[3]));
		MCAL_GPIO_WritePin(KEYBAD_PORT, keybad_colns[0], GPIO_PIN_Set);
		MCAL_GPIO_WritePin(KEYBAD_PORT, keybad_colns[1], GPIO_PIN_Set);
		MCAL_GPIO_WritePin(KEYBAD_PORT, keybad_colns[2], GPIO_PIN_Set);
		MCAL_GPIO_WritePin(KEYBAD_PORT, keybad_colns[3], GPIO_PIN_Set);

		//		KEYBAD_PORT&=~(1<<keybad_colns[i]);
		MCAL_GPIO_WritePin(KEYBAD_PORT, keybad_colns[i], GPIO_PIN_ReSet);
		for (j=0;j<4;j++)
		{
			if(MCAL_GPIO_ReadPin(KEYBAD_PORT, keybad_rows[j])==0)
			{
				while(MCAL_GPIO_ReadPin(KEYBAD_PORT, keybad_rows[j])==0);
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
