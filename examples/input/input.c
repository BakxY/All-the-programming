/*------------------------------------------
* Projekt: Input										       *
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
	
//Variable decleration
uint16_t iInput = 0;

int main(void) 										//main function
{
	InitTouchP0P1("1");							//Display initialisation
	
	while(1)												//Loop forever
	{
		iInput = P0_0;								//Read the status of Port 0 Pin 0
		
		if(iInput == true)						//Compare iInput and true
		{
			P1_0 = true;								//Set Port 1 Pin 0 to true
		}
		else													//else state for Port 0 Pin 0 if not true
		{
			P1_0 = false;								//Set Port 1 Pin 0 to false
		}
	}
}