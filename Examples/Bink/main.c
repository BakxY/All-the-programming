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

//Variable decleration
uint16_t iFlanke = 0;

int main(void) 										//main function
{
	InitTouchP0P1("1");							//Display initialisation
	
	while(1)												//Loop forever
	{
		if(P0_0 == true)							//Compare the state of Port 0 Pin 0 with true
		{
			if(iFlanke == false)				//Compare iFlanke with false
			{
				P1_0 = !P1_0;							//Change state of P1_0 to its invertet state
			}
			iFlanke = true;							//Set iFlanke to true
		}
		else													//else state for Port 0 Pin 0 if not true
		{
			iFlanke = false;						//Set iFlanke to false
		}
	}
}
