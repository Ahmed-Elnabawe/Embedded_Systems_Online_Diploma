#include "platform.h"
#define RCC_BASE 0x40021000
#define GPIO_BASE 0x40010800
#define APB2ENR_REG 	*(volatile uint32 *)(RCC_BASE+0x18)
#define CRH_REG 	    *(volatile uint32 *)(GPIO_BASE+0x04)
#define APB2ENR_PIN (1<<2)
typedef union {
	volatile uint32 ALL_BINS ;
	struct {
		volatile uint32 bin0:1;
		volatile uint32 bin1:1;
		volatile uint32 bin2:1;
		volatile uint32 bin3:1;
		volatile uint32 bin4:1;
		volatile uint32 bin5:1;
		volatile uint32 bin6:1;
		volatile uint32 bin7:1;
		volatile uint32 bin8:1;
		volatile uint32 bin9:1;
		volatile uint32 bin10:1;
		volatile uint32 bin11:1;
		volatile uint32 bin12:1;
		volatile uint32 bin13:1;
		volatile uint32 bin14:1;
		volatile uint32 bin15:1;
		volatile uint32 bin16:1;
		volatile uint32 bin17:1;
		volatile uint32 bin18:1;
		volatile uint32 bin19:1;
		volatile uint32 bin20:1;
		volatile uint32 bin21:1;
		volatile uint32 bin22:1;
		volatile uint32 bin23:1;
		volatile uint32 bin24:1;
		volatile uint32 bin25:1;
		volatile uint32 bin26:1;
		volatile uint32 bin27:1;
		volatile uint32 bin28:1;
		volatile uint32 bin29:1;
		volatile uint32 bin30:1;
		volatile uint32 bin31:1;
	}pin;
}ODR_REG_t;

volatile ODR_REG_t * odr_reg =(volatile ODR_REG_t *)(GPIO_BASE+0x0c);
int main (){
	APB2ENR_REG|=APB2ENR_PIN;
	CRH_REG&=0xff0fffff;
	CRH_REG|=0x00200000;
	while(1)
	{
		odr_reg->pin.bin13=1;
		for(int i =0 ;i<5000;i++);
		odr_reg->pin.bin13=0;
		for(int i =0 ;i<5000;i++);
	}
}
