/*-----------------------------------
* Project:  "Project Title"		      *
* Autor:    "Your Name"				      *
* Date:     "Date of commit"	      *
* Dep:      b4 microcontrollers     *
* uC:       STM32F107VC             *
------------------------------------*/
/*----------Libraries---------------*/
#include <stm32f10x.h>
#include "TouchP0P1.h"
/*----------Defines-----------------*/
#define TRUE 1
#define FALSE 0
/*----------Variables---------------*/

/*----------User functions----------*/

/*----------User code---------------*/
int main(void) 														//main function
{
	
	InitTouchP0P1("1");											//Display initialisation
	
  while (1)																//Loop forever
  {
    //write 10/10 code here
  }
}
