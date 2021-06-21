/*---------------------------------------
* Project:	PROJECT TITLE				*
* Autor:    A.Hofmann					*
* Date:     DD.MM.YYYY					*
* Revision: DD.MM.YYYY / AH				*
* Dep:     	R&D Mechatronics			*
* uC:       STM32F107VC					*
----------------------------------------*/

/*-------------INCLUDES-----------------*/
#include <stm32f10x.h>							//include uC specific header file
#include "TouchP0P1.h"							//include display specific header file
#include "MCB32D.h"								//include board specific custom header file
/*--------------------------------------*/

/*-------------DEFINES------------------*/
#define TRUE 1									//define TRUE as 1 (mainly used in if cases)
#define FALSE 0									//define FALSE as 0 (mainly used in if cases)

/*****INPUTS*****/
//#define BUTTON_function 0						//Button for (function)
//#define BUTTON_function 1						//Button for (function)
//#define BUTTON_function 2						//Button for (function)
//#define BUTTON_function 3						//Button for (function)
//#define BUTTON_function 4						//Button for (function)
//#define BUTTON_function 5						//Button for (function)
//#define BUTTON_function 6						//Button for (function)
//#define BUTTON_function 7						//Button for (function)

/*****OUTPUTS*****/
//#define LED_function 0						//LED for (function)
//#define LED_function 1						//LED for (function)
//#define LED_function 2						//LED for (function)
//#define LED_function 3						//LED for (function)
//#define LED_function 4						//LED for (function)
//#define LED_function 5						//LED for (function)
//#define LED_function 6						//LED for (function)
//#define LED_function 7						//LED for (function)

/*****FLAGS*******/
//#define FLAG_function 0						//Flag for (function)
//#define FLAG_function 0						//Flag for (function)
//#define FLAG_function 0						//Flag for (function)
/*--------------------------------------*/

/*-------------USER CODE----------------*/
int main(void)									//user code goes here
{	
	InitTouchP0P1("1rm");						//initialise touch screen
	MCB32D_InitLED(0);							//initialise GPIO for LEDs without blink sequence

	int iInputArray[8];							//create input array
	int iOutputArray[8];						//create output array
	int iTimer = 0;								//create timer variable for checking runtime
	
	while(1)									//infinite loop
	{
		vReadPort(iInputArray);					//read complete input port and safe in array
		
		//epic 10/10 code
		
		vSendPort(iOutputArray);				//send complete array to output port
		
		vClearArray(iInputArray);				//clear the input array
		vClearArray(iOutputArray);				//clear the output array
		
		iTimer += 5;							//increase timer by 5
		delay_ms(5);							//pause system for 5ms
	}
}
