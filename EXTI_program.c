/**********************************************/
/* Author  			: Mahmoud Sayed 	      */
/* Date    			: 1 jan 2024             */
/* Version 			: V02                     */
/* Microcontroller  : STM32F446xx             */
/**********************************************/

#include <stdint.h>
#include "STM32F446xx.h"
#include "ERRTYPE.h"
#include "EXTI_interfaces.h"
#include "EXTI_private.h"

static void (*EXTI_PvcallBackfunc[NUM_EXTI_LINE])(void)={0};

uint8_t EXTI_Init(const EXTI_Config* EXTIConfig)
{
	uint8_t Local_ErrorState =OK;


	SET_BIT(EXTI->IMR,EXTIConfig->num);
	if(EXTIConfig->Rising_trigger==Rising_trigger_enabled)
	{
		SET_BIT(EXTI->RTSR,EXTIConfig->num);
	}
	else
	{
		CLR_BIT(EXTI->RTSR,EXTIConfig->num);
	}
	if(EXTIConfig->Falling_trigger==Falling_trigger_enabled)
	{
		SET_BIT(EXTI->FTSR,EXTIConfig->num);
	}
	else
	{
		CLR_BIT(EXTI->FTSR,EXTIConfig->num);
	}
	if(EXTIConfig->CallBackfunc !=NULL)
	{
		EXTI_PvcallBackfunc[EXTIConfig->num]=EXTIConfig->CallBackfunc;
	}
	else
	{
		Local_ErrorState=NULL_PTR_ERR;
	}

	return Local_ErrorState;
}

uint8_t EXTI_Disable(const EXTI_Config* EXTIConfig)
{
	uint8_t Local_ErrorState =OK;

	CLR_BIT(EXTI->IMR,EXTIConfig->num);

	return Local_ErrorState;
}

uint8_t EXTI_ClearPendingFlag(const EXTI_Config* EXTIConfig)
{
	uint8_t Local_ErrorState =OK;

	SET_BIT(EXTI->PR,EXTIConfig->num);

	return Local_ErrorState;
}

uint8_t EXTI_ReadPendingFlag(const EXTI_Config* EXTIConfig,uint8_t* stateflag)
{
	uint8_t Local_ErrorState =OK;

	*stateflag=GET_BIT(EXTI->PR,EXTIConfig->num);

	return Local_ErrorState;
}


uint8_t SYSCFG_Init(EXTI_Config* EXTIconfec)
{
	uint8_t Local_ErrorState =OK;

	uint8_t EXTICRREG;
	uint8_t EXTICRprt;

	EXTICRREG=(EXTIconfec->num/EXTI_PIN_ACCESS_BITS);
	EXTICRprt=((EXTIconfec->num%EXTI_PIN_ACCESS_BITS)*EXTI_PIN_ACCESS_BITS);

	SYSCFG->CR[EXTICRREG] &= ~(EXTICRx_MASK_bits<<EXTICRprt);
	SYSCFG->CR[EXTICRREG] |=  (EXTIconfec->port<<EXTICRprt);

	return Local_ErrorState;
}



void EXTI0_IRQHandler(void)
{
	SET_BIT(EXTI->PR,EXTI_0);
	EXTI_PvcallBackfunc[EXTI_0]();
}
void EXTI1_IRQHandler(void)
{
	SET_BIT(EXTI->PR,EXTI_1);
	EXTI_PvcallBackfunc[EXTI_1]();
}
void EXTI2_IRQHandler(void)
{
	SET_BIT(EXTI->PR,EXTI_2);
	EXTI_PvcallBackfunc[EXTI_2]();
}
void EXTI3_IRQHandler(void)
{
	SET_BIT(EXTI->PR,EXTI_3);
	EXTI_PvcallBackfunc[EXTI_3]();
}
void EXTI4_IRQHandler(void)
{
	SET_BIT(EXTI->PR,EXTI_4);
	EXTI_PvcallBackfunc[EXTI_4]();
}
void EXTI9_5_IRQHandler(void)
{
	if(EXTI5_FLAG==Raised)
	{
		SET_BIT(EXTI->PR,EXTI_5);
		EXTI_PvcallBackfunc[EXTI_5]();
	}
	if(EXTI6_FLAG==Raised)
	{
		SET_BIT(EXTI->PR,EXTI_6);
		EXTI_PvcallBackfunc[EXTI_6]();
	}
	if(EXTI7_FLAG==Raised)
	{
		SET_BIT(EXTI->PR,EXTI_7);
		EXTI_PvcallBackfunc[EXTI_7]();
	}
	if(EXTI8_FLAG==Raised)
	{
		SET_BIT(EXTI->PR,EXTI_8);
		EXTI_PvcallBackfunc[EXTI_8]();
	}
	if(EXTI9_FLAG==Raised)
	{
		SET_BIT(EXTI->PR,EXTI_9);
		EXTI_PvcallBackfunc[EXTI_9]();
	}
}
void EXTI15_10_IRQHandler(void)
{
	if(EXTI10_FLAG==Raised)
	{
		SET_BIT(EXTI->PR,EXTI_10);
		EXTI_PvcallBackfunc[EXTI_10]();
	}
	if(EXTI11_FLAG==Raised)
	{
		SET_BIT(EXTI->PR,EXTI_11);
		EXTI_PvcallBackfunc[EXTI_11]();
	}
	if(EXTI12_FLAG==Raised)
	{
		SET_BIT(EXTI->PR,EXTI_12);
		EXTI_PvcallBackfunc[EXTI_12]();
	}
	if(EXTI13_FLAG==Raised)
	{
		SET_BIT(EXTI->PR,EXTI_13);
		EXTI_PvcallBackfunc[EXTI_13]();
	}
	if(EXTI14_FLAG==Raised)
	{
		SET_BIT(EXTI->PR,EXTI_14);
		EXTI_PvcallBackfunc[EXTI_14]();
	}
	if(EXTI15_FLAG==Raised)
	{
		SET_BIT(EXTI->PR,EXTI_15);
		EXTI_PvcallBackfunc[EXTI_15]();
	}
}
