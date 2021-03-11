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

#define MASK_S0 0x01								//define masks for bit masking
#define MASK_S1 0x02
#define MASK_S2 0x04
#define MASK_S3 0x08
#define MASK_S4 0x10
#define MASK_S5 0x20
#define MASK_S6 0x40
#define MASK_S7 0x80
/*----------Variables---------------*/
//local variables are prefered
/*----------User functions----------*/
int ReadPin(int iMASK)								//function for reading pin input
{
	int iStatus;
	iStatus = (1 >> (P0 & iMASK)) == (1 >> iMASK);	//get status of selested button
	return(iStatus);
}
/*----------User code---------------*/
int main(void) 										//main function
{
	
	InitTouchP0P1("1r");								//Display initialisation r -> rotated display
	
	while (1)
	{
		//write epic 10/10 code here
	}
}
