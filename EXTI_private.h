/**********************************************/
/* Author  			: Mahmoud Sayed 	      */
/* Date    			: 28 DES 2023             */
/* Version 			: V02                     */
/* Microcontroller  : STM32F103xx             */
/**********************************************/

#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_

#define NULL_PTR 3

#define NUM_EXTI_LINE 15

#define Raised 1

#define EXTICRx_MASK_bits 0b1111

#define EXTI5_FLAG 		GET_BIT(EXTI->PR,EXTI_5)
#define EXTI6_FLAG 		GET_BIT(EXTI->PR,EXTI_6)
#define EXTI7_FLAG 		GET_BIT(EXTI->PR,EXTI_7)
#define EXTI8_FLAG 		GET_BIT(EXTI->PR,EXTI_8)
#define EXTI9_FLAG 		GET_BIT(EXTI->PR,EXTI_9)
#define EXTI10_FLAG 	GET_BIT(EXTI->PR,EXTI_10)
#define EXTI11_FLAG 	GET_BIT(EXTI->PR,EXTI_11)
#define EXTI12_FLAG 	GET_BIT(EXTI->PR,EXTI_12)
#define EXTI13_FLAG 	GET_BIT(EXTI->PR,EXTI_13)
#define EXTI14_FLAG 	GET_BIT(EXTI->PR,EXTI_14)
#define EXTI15_FLAG 	GET_BIT(EXTI->PR,EXTI_15)

#define EXTI_PIN_ACCESS_BITS 4

#endif

