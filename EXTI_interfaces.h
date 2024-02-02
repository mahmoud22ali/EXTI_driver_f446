/**********************************************/
/* Author  			: Mahmoud Sayed 	      */
/* Date    			: 1 jan 2024             */
/* Version 			: V02                     */
/* Microcontroller  : STM32F446xx             */
/**********************************************/

#ifndef EXTI_INTERFACING_H_
#define EXTI_INTERFACING_H_

typedef enum
{
	EXTI_0=0,
	EXTI_1,
	EXTI_2,
	EXTI_3,
	EXTI_4,
	EXTI_5,
	EXTI_6,
	EXTI_7,
	EXTI_8,
	EXTI_9,
	EXTI_10,
	EXTI_11,
	EXTI_12,
	EXTI_13,
	EXTI_14,
	EXTI_15
}EXTI_num;

typedef enum
{
	EXTIA=0,
	EXTIB,
	EXTIC,
	EXTID,
	EXTIF,
	EXTIG
}EXTI_port;

typedef enum
{
	Rising_trigger_disabled =0,
	Rising_trigger_enabled
}Rising_trigger_selection;

typedef enum
{
	Falling_trigger_disabled =0,
	Falling_trigger_enabled
}Falling_trigger_selection;

typedef struct
{
	EXTI_num num;
	EXTI_port port;
	Rising_trigger_selection Rising_trigger;
	Falling_trigger_selection Falling_trigger;
	void (*CallBackfunc)(void);
}EXTI_Config;

uint8_t EXTI_Init(const EXTI_Config* EXTIConfig);
uint8_t EXTI_Disable(const EXTI_Config* EXTIConfig);
uint8_t EXTI_ClearPendingFlag(const EXTI_Config* EXTIConfig);
uint8_t EXTI_ReadPendingFlag(const EXTI_Config* EXTIConfig,uint8_t* stateflag);
uint8_t SYSCFG_Init(EXTI_Config* EXTIconfec);

#endif 
