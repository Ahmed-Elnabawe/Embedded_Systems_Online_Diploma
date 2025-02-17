/*
 * keybad_lcd.c
 *
 * Created: 12/12/2024 3:19:21 PM
 * Author : Lenovo
 */ 

#include "lcd/lcd.h"
#include "keybad/keybad.h"
int main(void)
{
    LCD_INIT();
	KEYBAD_INIT();
	unsigned char pressed_key ;
    while (1) 
    {
		pressed_key=KEYBAD_GET_KEY();
		switch(pressed_key)
		{
			case('A'):
				break ;
			case('?'):
				LCD_clear_screen();
				break;
			default:
				LCD_WRITE_CHAR(pressed_key);	
			
		}

    }
}

