/*-----------------------------------
* Project:  "Project Title"			*
* Autor:    "Your Name"				*
* Date:     "Date of commit"		*
* Dep:      b4 microcontrollers		*
* uC:       STM32F107VC				*
------------------------------------*/

/*----------Libraries---------------*/
#include <stm32f10x.h>								//include header file for uC
#include "TouchP0P1.h"								//include header file for display
/*----------Defines-----------------*/
#define TRUE 1										//define a constant for 1
#define FALSE 0										//define a constant for 0

#define MASK 0x01									//define mask for bit masking
/*----------Variables---------------*/
//local variables are prefered
/*----------User functions----------*/
int* ReadPort(void)									//function for reading port input
{	
	int iPinArray[8];
	for (int i = 0; i < 8; i++)						//for loop for scaning the seperate pins
	{
		iPinArray[i] = P0 & 0x01 << i && 1;			//saving of seperate pins in array
	}
	return iPinArray;
}
/*----------User code---------------*/
int main(void) 										//main function
{	
	int* iPinArray;									//variable for receiving Port status -> iPinArray = ReadPin();
	InitTouchP0P1("1r");							//Display initialisation r -> rotated display
	
	while (1)
	{	
		//write epic 10/10 code here
	}
}
