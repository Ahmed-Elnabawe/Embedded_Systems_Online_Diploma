/*
 * Lcd_drivier.c
 *
 *  Created on: Dec 16, 2024
 *      Author: Lenovo
 */

#include "Lcd_drivier.h"
void wait(int x)
{
	int i , j ;
	for (i = 0; i < x; ++i) {
		for (j = 0; j < 255; ++j);
	}
}

char pos_in_current_row=0;
void LCD_clear_screen(){
	LCD_WRITE_COMMAND(LCD_CLEAR_SCREEN);
}
void lcd_kick(void){
	//	LCD_CNTRL&=~(1<<EN);
	MCAL_GPIO_WritePin(LCD_PORT, EN, GPIO_PIN_Set);
	wait(50);
	MCAL_GPIO_WritePin(LCD_PORT, EN, GPIO_PIN_ReSet);
}
void LCD_check_isbusy(){
	//	LCD_DATA_DIR=0x00;
	pinCnfg.PinNumber = GPIO_PIN_0;
	pinCnfg.PinMode = GPIO_MODE_Input_FLO;
	MCAL_GPIO_Init(LCD_PORT, &pinCnfg);

	pinCnfg.PinNumber = GPIO_PIN_1;
	pinCnfg.PinMode = GPIO_MODE_Input_FLO;
	MCAL_GPIO_Init(LCD_PORT, &pinCnfg);

	pinCnfg.PinNumber = GPIO_PIN_2;
	pinCnfg.PinMode = GPIO_MODE_Input_FLO;
	MCAL_GPIO_Init(LCD_PORT, &pinCnfg);

	pinCnfg.PinNumber = GPIO_PIN_3;
	pinCnfg.PinMode = GPIO_MODE_Input_FLO;
	MCAL_GPIO_Init(LCD_PORT, &pinCnfg);

	pinCnfg.PinNumber = GPIO_PIN_4;
	pinCnfg.PinMode = GPIO_MODE_Input_FLO;
	MCAL_GPIO_Init(LCD_PORT, &pinCnfg);

	pinCnfg.PinNumber = GPIO_PIN_5;
	pinCnfg.PinMode = GPIO_MODE_Input_FLO;
	MCAL_GPIO_Init(LCD_PORT, &pinCnfg);

	pinCnfg.PinNumber = GPIO_PIN_6;
	pinCnfg.PinMode = GPIO_MODE_Input_FLO;
	MCAL_GPIO_Init(LCD_PORT, &pinCnfg);

	pinCnfg.PinNumber = GPIO_PIN_7;
	pinCnfg.PinMode = GPIO_MODE_Input_FLO;
	MCAL_GPIO_Init(LCD_PORT, &pinCnfg);
	//	LCD_CNTRL&=~(1<<REG_SEL);
	MCAL_GPIO_WritePin(LCD_CNTRL, REG_SEL, GPIO_PIN_ReSet);
	//	LCD_CNTRL|=(1<<RW);
	MCAL_GPIO_WritePin(LCD_CNTRL, RW, GPIO_PIN_Set);
	lcd_kick();
	//	LCD_DATA_DIR=0xff;
	pinCnfg.PinNumber = GPIO_PIN_0;
	pinCnfg.PinMode = GPIO_MODE_Output_PP;
	pinCnfg.OutPutSpeed=GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_PORT, &pinCnfg);

	pinCnfg.PinNumber = GPIO_PIN_1;
	pinCnfg.PinMode = GPIO_MODE_Output_PP;
	pinCnfg.OutPutSpeed=GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_PORT, &pinCnfg);

	pinCnfg.PinNumber = GPIO_PIN_2;
	pinCnfg.PinMode = GPIO_MODE_Output_PP;
	pinCnfg.OutPutSpeed=GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_PORT, &pinCnfg);

	pinCnfg.PinNumber = GPIO_PIN_3;
	pinCnfg.PinMode = GPIO_MODE_Output_PP;
	pinCnfg.OutPutSpeed=GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_PORT, &pinCnfg);

	pinCnfg.PinNumber = GPIO_PIN_4;
	pinCnfg.PinMode = GPIO_MODE_Output_PP;
	pinCnfg.OutPutSpeed=GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_PORT, &pinCnfg);

	pinCnfg.PinNumber = GPIO_PIN_5;
	pinCnfg.PinMode = GPIO_MODE_Output_PP;
	pinCnfg.OutPutSpeed=GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_PORT, &pinCnfg);

	pinCnfg.PinNumber = GPIO_PIN_6;
	pinCnfg.PinMode = GPIO_MODE_Output_PP;
	pinCnfg.OutPutSpeed=GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_PORT, &pinCnfg);

	pinCnfg.PinNumber = GPIO_PIN_7;
	pinCnfg.PinMode = GPIO_MODE_Output_PP;
	pinCnfg.OutPutSpeed=GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_PORT, &pinCnfg);
	//	LCD_CNTRL&=~(1<<RW);
	MCAL_GPIO_WritePin(LCD_CNTRL, RW, GPIO_PIN_ReSet);

}
void LCD_INIT(){
	wait(20);
	//	LCD_CTRL_DATA_DIR |= (1<<RW | 1<<REG_SEL| 1<<EN);
	pinCnfg.PinNumber = RW;
	pinCnfg.PinMode = GPIO_MODE_Output_PP;
	pinCnfg.OutPutSpeed=GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_CNTRL, &pinCnfg);

	pinCnfg.PinNumber = REG_SEL;
	pinCnfg.PinMode = GPIO_MODE_Output_PP;
	pinCnfg.OutPutSpeed=GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_CNTRL, &pinCnfg);

	pinCnfg.PinNumber = EN;
	pinCnfg.PinMode = GPIO_MODE_Output_PP;
	pinCnfg.OutPutSpeed=GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_CNTRL, &pinCnfg);


	//	LCD_CNTRL &= ~( 1<<RW  | 1<<REG_SEL  | 1<<EN );//
	MCAL_GPIO_WritePin(LCD_CNTRL, RW, GPIO_PIN_ReSet);
	MCAL_GPIO_WritePin(LCD_CNTRL, REG_SEL, GPIO_PIN_ReSet);
	MCAL_GPIO_WritePin(LCD_CNTRL, EN, GPIO_PIN_ReSet);

	//	LCD_DATA_DIR=0xff;
	pinCnfg.PinNumber = GPIO_PIN_0;
	pinCnfg.PinMode = GPIO_MODE_Output_PP;
	pinCnfg.OutPutSpeed=GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_PORT, &pinCnfg);

	pinCnfg.PinNumber = GPIO_PIN_1;
	pinCnfg.PinMode = GPIO_MODE_Output_PP;
	pinCnfg.OutPutSpeed=GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_PORT, &pinCnfg);

	pinCnfg.PinNumber = GPIO_PIN_2;
	pinCnfg.PinMode = GPIO_MODE_Output_PP;
	pinCnfg.OutPutSpeed=GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_PORT, &pinCnfg);

	pinCnfg.PinNumber = GPIO_PIN_3;
	pinCnfg.PinMode = GPIO_MODE_Output_PP;
	pinCnfg.OutPutSpeed=GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_PORT, &pinCnfg);

	pinCnfg.PinNumber = GPIO_PIN_4;
	pinCnfg.PinMode = GPIO_MODE_Output_PP;
	pinCnfg.OutPutSpeed=GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_PORT, &pinCnfg);

	pinCnfg.PinNumber = GPIO_PIN_5;
	pinCnfg.PinMode = GPIO_MODE_Output_PP;
	pinCnfg.OutPutSpeed=GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_PORT, &pinCnfg);

	pinCnfg.PinNumber = GPIO_PIN_6;
	pinCnfg.PinMode = GPIO_MODE_Output_PP;
	pinCnfg.OutPutSpeed=GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_PORT, &pinCnfg);

	pinCnfg.PinNumber = GPIO_PIN_7;
	pinCnfg.PinMode = GPIO_MODE_Output_PP;
	pinCnfg.OutPutSpeed=GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_PORT, &pinCnfg);
	wait(150);
	LCD_WRITE_COMMAND(LCD_FUNCTION_8BIT_2LINES);

	LCD_WRITE_COMMAND(LCD_DISP_OFF);
	LCD_clear_screen();
	LCD_WRITE_COMMAND(LCD_ENTRY_MODE);
	LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW);
	LCD_WRITE_COMMAND(LCD_DISP_ON_CURSOR_BLINK);
	///LCD_WRITE_CHAR('Q');
}

void LCD_WRITE_COMMAND(unsigned char command){
	LCD_check_isbusy();
	//		LCD_PORT=command;
	MCAL_GPIO_WritePort(LCD_PORT, command);
	//		LCD_CNTRL&=~(1<<RW|1<<REG_SEL);
	MCAL_GPIO_WritePin(LCD_CNTRL, RW, GPIO_PIN_ReSet);
	MCAL_GPIO_WritePin(LCD_CNTRL, REG_SEL, GPIO_PIN_ReSet);

	wait(1);
	lcd_kick();
}
void LCD_WRITE_CHAR(unsigned char data){
	LCD_check_isbusy();
	//		LCD_PORT=data;
	MCAL_GPIO_WritePort(LCD_PORT, data);
	//		LCD_CNTRL&=~(1<<RW);
	MCAL_GPIO_WritePin(LCD_CNTRL, RW, GPIO_PIN_ReSet);
	//		LCD_CNTRL|=1<<REG_SEL;
	MCAL_GPIO_WritePin(LCD_CNTRL, REG_SEL, GPIO_PIN_Set);

	wait(1);
	lcd_kick();
	pos_in_current_row++;
//	if(pos_in_current_row == 16)
//	{
//		LCD_GOTO_XY(1,0);
//	}
//	else if(pos_in_current_row>=32)
//	{
//		LCD_clear_screen();
//		LCD_GOTO_XY(0,0);
//		pos_in_current_row = 0;
//	}
}
void LCD_WRITE_STRING(char* string){
	int count =0 ;
	while(*string>0)
	{
		LCD_WRITE_CHAR(*string++);
		count++;
		if (count == 16)
		{
			LCD_GOTO_XY(1,0);
		}
		else if (count >= 32)
		{
			LCD_clear_screen();
			LCD_GOTO_XY(0,0);
			count = 0;
		}
	}
}
void LCD_GOTO_XY(unsigned char line, unsigned char position){
	if (line==0)
	{
		if(position>=0 && position<=16)
			LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW+position);
	}
	else if (line == 1)
	{
		if(position>=0 && position<=16)
			LCD_WRITE_COMMAND(LCD_BEGIN_AT_SECOND_ROW+position);
	}
}
