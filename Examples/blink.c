/*------------------------------------------
* Projekt: Blink										       *
* Autor: SSP															 *
* Date: 10.03.2021												 *
* Dep: b4 Microcontrollers								 *
* uC: STM32F107														 *
-------------------------------------------*/

//Librarys for standart use
#include <stm32f10x.h>
#include "TouchP0P1.h"

//defines
#define true 1
#define false 0
	
int main(void) 										//main function
{
	InitTouchP0P1("1");							//Display initialisation
	
	while(1)												//Loop forever
	{
		P1_0 = true;									//Set Port 1 Pin 0 to true
		delay_ms(1000);								//Delay of 1000ms (1s)
		P1_0 = false;									//Set Port 1 Pin 0 to false
		delay_ms(1000);								//Delay of 1000ms (1s)
	}
}