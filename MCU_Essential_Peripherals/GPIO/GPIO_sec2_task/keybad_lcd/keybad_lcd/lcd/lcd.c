/*
 * lcd.c
 *
 * Created: 12/12/2024 3:20:55 PM
 *  Author: Lenovo
 */ 
#include "lcd.h"
char pos_in_current_row=0;
void LCD_clear_screen(){
	LCD_WRITE_COMMAND(LCD_CLEAR_SCREEN);
}
void lcd_kick(void){
	LCD_CNTRL&=~(1<<EN);	
	_delay_ms(1);
	LCD_CNTRL|=1<<EN;
}
void LCD_check_isbusy(){
	LCD_DATA_DIR=0x00;
	LCD_CNTRL&=~(1<<REG_SEL);
	LCD_CNTRL|=(1<<RW);
	lcd_kick();
	LCD_DATA_DIR=0xff;
	LCD_CNTRL&=~(1<<RW);
}
void LCD_INIT(){
	_delay_ms(20);
	LCD_CTRL_DATA_DIR |= (1<<RW | 1<<REG_SEL| 1<<EN);
	LCD_CNTRL &= ~( 1<<RW  | 1<<REG_SEL  | 1<<EN );//
	LCD_DATA_DIR=0xff;
	_delay_ms(15);
	#ifdef EIGHT_BIT_MODE
	LCD_WRITE_COMMAND(LCD_FUNCTION_8BIT_2LINES); 
	#endif
	#ifdef FOUR_BIT_MODE
	LCD_WRITE_COMMAND(LCD_FUNCTION_4BIT_2LINES);
	#endif
	
	LCD_WRITE_COMMAND(LCD_DISP_OFF);
	LCD_clear_screen();
	LCD_WRITE_COMMAND(LCD_ENTRY_MODE);
	LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW);
	LCD_WRITE_COMMAND(LCD_DISP_ON_CURSOR_BLINK);
}

void LCD_WRITE_COMMAND(unsigned char command){
	LCD_check_isbusy();
	LCD_CNTRL&=~(1<<RW|1<<REG_SEL);
	LCD_DATA_PORT=command;
	lcd_kick();	
}
void LCD_WRITE_CHAR(unsigned char data){
	LCD_check_isbusy();
	LCD_CNTRL&=~(1<<RW);
	LCD_CNTRL|=1<<REG_SEL;
	LCD_DATA_PORT=data;
	lcd_kick();
	pos_in_current_row++;
	if(pos_in_current_row == 16)
	{
		LCD_GOTO_XY(1,0);
	}
	else if(pos_in_current_row>=32)
	{
			LCD_clear_screen();
			LCD_GOTO_XY(0,0);
			pos_in_current_row = 0;		
	}
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