/*
 * stm32f103c6_EXTI_driver.h
 *
 *  Created on: Jan 26, 2025
 *      Author: Ahmed Elnabawe
 */

#ifndef INC_STM32F103C6_EXTI_DRIVER_H_
#define INC_STM32F103C6_EXTI_DRIVER_H_
#include "stm32f103x6.h"
#include "stm32f103c6_gpio_driver.h"

typedef struct {
	uint16_t 		EXTI_InputLineNumber ;
	GPIO_TypeDef* 	GPIO_Port ;
	uint16_t		GPIO_PIN;
	uint8_t 		EXTI_IQR;
}EXTI_GPIO_Maping_t;

typedef struct
{
	EXTI_GPIO_Maping_t  EXTI_PIN ;        // Specify the EXTI pin to be configured
								          // this parameter can be selected according to @ref

	uint8_t			    trigger_case ;  // Specify the EXTI pin detection
									    // this parameter can be selected according to @ref EXTI_Trigger_define

	uint8_t 			IRQ_EN;		  // Enable or Disable the interrupt mask (at EXTI and NVIC)
									  // this parameter can be selected according to @ref EXTI_IRQ_define
	void(*P_IRQ_CallBack)(void);

}EXTI_PinConfig_t;


// References //
//===============//
//@ref EXTI_define
// this reference is to constrain the user to use fixed choices when selecting pin and port and interrupt line
//EXTI0
#define EXTI_EXTI0PA0   (EXTI_GPIO_Maping_t){EXTI0,GPIOA,GPIO_PIN_0,EXTI0_IRQ}
#define EXTI_EXTI0PB0   (EXTI_GPIO_Maping_t){EXTI0,GPIOB,GPIO_PIN_0,EXTI0_IRQ}
#define EXTI_EXTI0PC0   (EXTI_GPIO_Maping_t){EXTI0,GPIOC,GPIO_PIN_0,EXTI0_IRQ}
#define EXTI_EXTI0PD0   (EXTI_GPIO_Maping_t){EXTI0,GPIOD,GPIO_PIN_0,EXTI0_IRQ}

//EXTI1
#define EXTI_EXTI1PA1   (EXTI_GPIO_Maping_t){EXTI1,GPIOA,GPIO_PIN_1,EXTI1_IRQ}
#define EXTI_EXTI1PB1   (EXTI_GPIO_Maping_t){EXTI1,GPIOB,GPIO_PIN_1,EXTI1_IRQ}
#define EXTI_EXTI1PC1   (EXTI_GPIO_Maping_t){EXTI1,GPIOC,GPIO_PIN_1,EXTI1_IRQ}
#define EXTI_EXTI1PD1   (EXTI_GPIO_Maping_t){EXTI1,GPIOD,GPIO_PIN_1,EXTI1_IRQ}

//EXTI2
#define EXTI_EXTI2PA2   (EXTI_GPIO_Maping_t){EXTI2,GPIOA,GPIO_PIN_2,EXTI2_IRQ}
#define EXTI_EXTI2PB2   (EXTI_GPIO_Maping_t){EXTI2,GPIOB,GPIO_PIN_2,EXTI2_IRQ}
#define EXTI_EXTI2PC2   (EXTI_GPIO_Maping_t){EXTI2,GPIOC,GPIO_PIN_2,EXTI2_IRQ}
#define EXTI_EXTI2PD2   (EXTI_GPIO_Maping_t){EXTI2,GPIOD,GPIO_PIN_2,EXTI2_IRQ}

//EXTI3
#define EXTI_EXTI3PA3   (EXTI_GPIO_Maping_t){EXTI3,GPIOA,GPIO_PIN_3,EXTI3_IRQ}
#define EXTI_EXTI3PB3   (EXTI_GPIO_Maping_t){EXTI3,GPIOB,GPIO_PIN_3,EXTI3_IRQ}
#define EXTI_EXTI3PC3   (EXTI_GPIO_Maping_t){EXTI3,GPIOC,GPIO_PIN_3,EXTI3_IRQ}
#define EXTI_EXTI3PD3   (EXTI_GPIO_Maping_t){EXTI3,GPIOD,GPIO_PIN_3,EXTI3_IRQ}

//EXTI4
#define EXTI_EXTI4PA4   (EXTI_GPIO_Maping_t){EXTI4,GPIOA,GPIO_PIN_4,EXTI4_IRQ}
#define EXTI_EXTI4PB4   (EXTI_GPIO_Maping_t){EXTI4,GPIOB,GPIO_PIN_4,EXTI4_IRQ}
#define EXTI_EXTI4PC4   (EXTI_GPIO_Maping_t){EXTI4,GPIOC,GPIO_PIN_4,EXTI4_IRQ}
#define EXTI_EXTI4PD4   (EXTI_GPIO_Maping_t){EXTI4,GPIOD,GPIO_PIN_4,EXTI4_IRQ}

//EXTI5
#define EXTI_EXTI5PA5   (EXTI_GPIO_Maping_t){EXTI5,GPIOA,GPIO_PIN_5,EXTI5_IRQ}
#define EXTI_EXTI5PB5   (EXTI_GPIO_Maping_t){EXTI5,GPIOB,GPIO_PIN_5,EXTI5_IRQ}
#define EXTI_EXTI5PC5   (EXTI_GPIO_Maping_t){EXTI5,GPIOC,GPIO_PIN_5,EXTI5_IRQ}
#define EXTI_EXTI5PD5   (EXTI_GPIO_Maping_t){EXTI5,GPIOD,GPIO_PIN_5,EXTI5_IRQ}

//EXTI6
#define EXTI_EXTI6PA6   (EXTI_GPIO_Maping_t){EXTI6,GPIOA,GPIO_PIN_6,EXTI6_IRQ}
#define EXTI_EXTI6PB6   (EXTI_GPIO_Maping_t){EXTI6,GPIOB,GPIO_PIN_6,EXTI6_IRQ}
#define EXTI_EXTI6PC6   (EXTI_GPIO_Maping_t){EXTI6,GPIOC,GPIO_PIN_6,EXTI6_IRQ}
#define EXTI_EXTI6PD6   (EXTI_GPIO_Maping_t){EXTI6,GPIOD,GPIO_PIN_6,EXTI6_IRQ}

//EXTI7
#define EXTI_EXTI7PA7   (EXTI_GPIO_Maping_t){EXTI7,GPIOA,GPIO_PIN_7,EXTI7_IRQ}
#define EXTI_EXTI7PB7   (EXTI_GPIO_Maping_t){EXTI7,GPIOB,GPIO_PIN_7,EXTI7_IRQ}
#define EXTI_EXTI7PC7   (EXTI_GPIO_Maping_t){EXTI7,GPIOC,GPIO_PIN_7,EXTI7_IRQ}
#define EXTI_EXTI7PD7   (EXTI_GPIO_Maping_t){EXTI7,GPIOD,GPIO_PIN_7,EXTI7_IRQ}

//EXTI8
#define EXTI_EXTI8PA8   (EXTI_GPIO_Maping_t){EXTI8,GPIOA,GPIO_PIN_8,EXTI8_IRQ}
#define EXTI_EXTI8PB8   (EXTI_GPIO_Maping_t){EXTI8,GPIOB,GPIO_PIN_8,EXTI8_IRQ}
#define EXTI_EXTI8PC8   (EXTI_GPIO_Maping_t){EXTI8,GPIOC,GPIO_PIN_8,EXTI8_IRQ}
#define EXTI_EXTI8PD8   (EXTI_GPIO_Maping_t){EXTI8,GPIOD,GPIO_PIN_8,EXTI8_IRQ}

//EXTI9
#define EXTI_EXTI9PA9   (EXTI_GPIO_Maping_t){EXTI9,GPIOA,GPIO_PIN_9,EXTI9_IRQ}
#define EXTI_EXTI9PB9   (EXTI_GPIO_Maping_t){EXTI9,GPIOB,GPIO_PIN_9,EXTI9_IRQ}
#define EXTI_EXTI9PC9   (EXTI_GPIO_Maping_t){EXTI9,GPIOC,GPIO_PIN_9,EXTI9_IRQ}
#define EXTI_EXTI9PD9   (EXTI_GPIO_Maping_t){EXTI9,GPIOD,GPIO_PIN_9,EXTI9_IRQ}

//EXTI10
#define EXTI_EXTI10PA10   (EXTI_GPIO_Maping_t){EXTI10,GPIOA,GPIO_PIN_10,EXTI10_IRQ}
#define EXTI_EXTI10PB10   (EXTI_GPIO_Maping_t){EXTI10,GPIOB,GPIO_PIN_10,EXTI10_IRQ}
#define EXTI_EXTI10PC10   (EXTI_GPIO_Maping_t){EXTI10,GPIOC,GPIO_PIN_10,EXTI10_IRQ}
#define EXTI_EXTI10PD10   (EXTI_GPIO_Maping_t){EXTI10,GPIOD,GPIO_PIN_10,EXTI10_IRQ}

//EXTI11
#define EXTI_EXTI11PA11   (EXTI_GPIO_Maping_t){EXTI11,GPIOA,GPIO_PIN_11,EXTI11_IRQ}
#define EXTI_EXTI11PB11   (EXTI_GPIO_Maping_t){EXTI11,GPIOB,GPIO_PIN_11,EXTI11_IRQ}
#define EXTI_EXTI11PC11   (EXTI_GPIO_Maping_t){EXTI11,GPIOC,GPIO_PIN_11,EXTI11_IRQ}
#define EXTI_EXTI11PD11   (EXTI_GPIO_Maping_t){EXTI11,GPIOD,GPIO_PIN_11,EXTI11_IRQ}

//EXTI12
#define EXTI_EXTI12PA12   (EXTI_GPIO_Maping_t){EXTI12,GPIOA,GPIO_PIN_12,EXTI12_IRQ}
#define EXTI_EXTI12PB12   (EXTI_GPIO_Maping_t){EXTI12,GPIOB,GPIO_PIN_12,EXTI12_IRQ}
#define EXTI_EXTI12PC12   (EXTI_GPIO_Maping_t){EXTI12,GPIOC,GPIO_PIN_12,EXTI12_IRQ}
#define EXTI_EXTI12PD12   (EXTI_GPIO_Maping_t){EXTI12,GPIOD,GPIO_PIN_12,EXTI12_IRQ}

//EXTI13
#define EXTI_EXTI13PA13   (EXTI_GPIO_Maping_t){EXTI13,GPIOA,GPIO_PIN_13,EXTI13_IRQ}
#define EXTI_EXTI13PB13   (EXTI_GPIO_Maping_t){EXTI13,GPIOB,GPIO_PIN_13,EXTI13_IRQ}
#define EXTI_EXTI13PC13   (EXTI_GPIO_Maping_t){EXTI13,GPIOC,GPIO_PIN_13,EXTI13_IRQ}
#define EXTI_EXTI13PD13   (EXTI_GPIO_Maping_t){EXTI13,GPIOD,GPIO_PIN_13,EXTI13_IRQ}

//EXTI14
#define EXTI_EXTI14PA14   (EXTI_GPIO_Maping_t){EXTI14,GPIOA,GPIO_PIN_14,EXTI14_IRQ}
#define EXTI_EXTI14PB14   (EXTI_GPIO_Maping_t){EXTI14,GPIOB,GPIO_PIN_14,EXTI14_IRQ}
#define EXTI_EXTI14PC14   (EXTI_GPIO_Maping_t){EXTI14,GPIOC,GPIO_PIN_14,EXTI14_IRQ}
#define EXTI_EXTI14PD14   (EXTI_GPIO_Maping_t){EXTI14,GPIOD,GPIO_PIN_14,EXTI14_IRQ}

//EXTI15
#define EXTI_EXTI15PA15   (EXTI_GPIO_Maping_t){EXTI15,GPIOA,GPIO_PIN_15,EXTI15_IRQ}
#define EXTI_EXTI15PB15   (EXTI_GPIO_Maping_t){EXTI15,GPIOB,GPIO_PIN_15,EXTI15_IRQ}
#define EXTI_EXTI15PC15   (EXTI_GPIO_Maping_t){EXTI15,GPIOC,GPIO_PIN_15,EXTI15_IRQ}
#define EXTI_EXTI15PD15   (EXTI_GPIO_Maping_t){EXTI15,GPIOD,GPIO_PIN_15,EXTI15_IRQ}
//------------------------------------------------------------//
//@ref EXTI_Trigger_define
#define EXTI_Trigger_Rising    			 0
#define EXTI_Trigger_Falling   			 1
#define EXTI_Trigger_Rising_Falling  	 2
//------------------------------------------------------------//
//@ref EXTI_IRQ_define
#define EXTI_IRQ_Enable					 1
#define EXTI_IRQ_Disable				 0

// Macros Configuration References //
#define EXTI0 		0
#define EXTI1 		1
#define EXTI2 		2
#define EXTI3 		3
#define EXTI4 		4
#define EXTI5 		5
#define EXTI6 		6
#define EXTI7 		7
#define EXTI8 		8
#define EXTI9 		9
#define EXTI10 		10
#define EXTI11 		11
#define EXTI12 		12
#define EXTI13		13
#define EXTI14		14
#define EXTI15		15

/*
 * ============================================================================
 *					 APIs Supported by "MCAL GPIO DRIVER"
 * ============================================================================
 */
void MCAL_EXTI_GPIO_DeInit(void);
void MCAL_EXTI_GPIO_Init(EXTI_PinConfig_t * EXTI_Config);
void MCAL_EXTI_GPIO_Update(EXTI_PinConfig_t * EXTI_Config);




#endif /* INC_STM32F103C6_EXTI_DRIVER_H_ */
