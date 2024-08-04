// learn-in-depth 
//Ahmed Elnabawe
#include <platform.h>
#define RCC_BASE 0x40021000
#define GPIO_BASE 0x40010800
#define APB2ENR *((volatile uint32*)(RCC_BASE+0x18))
#define CRH *((volatile uint32*)(GPIO_BASE+0x04))
#define ODR_AD (volatile uint32*)(GPIO_BASE+0x0c)
typedef union {
	volatile uint32 ALL_PINS;
	 struct 
	{
		volatile uint32 reserved:13;
		volatile uint32 PIN_13:1;

	}PINS;
}ODR_t;

volatile ODR_t* ODR_REG= (volatile ODR_t*)(GPIO_BASE+0x0C);
int main()
{

	APB2ENR|=(1<<2);
	CRH&=0xFF0FFFFF;
	CRH|=0x00200000;
	int i;
	while(1)
	{
		ODR_REG->PINS.PIN_13=0;
		for( i =0 ;i<5000;i++);
		ODR_REG->PINS.PIN_13=1;
		for(i =0 ;i<5000;i++);	
	}
}




