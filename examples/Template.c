/*-----------------------------------
* Project:  "Project Title"	    *
* Autor:    "Your Name"		    *
* Date:     "Date of commit"	    *
* Dep:      b4 microcontrollers     *
* uC:       STM32F107VC             *
------------------------------------*/

/*----------Libraries---------------*/
#include <stm32f10x.h>
#include "TouchP0P1.h"
/*----------Defines-----------------*/
#define TRUE 1
#define FALSE 0

#define MASK_S0 0x01
#define MASK_S1 0x02
#define MASK_S2 0x04
#define MASK_S3 0x08
#define MASK_S4 0x10
#define MASK_S5 0x20
#define MASK_S6 0x40
#define MASK_S7 0x80
/*----------Variables---------------*/

/*----------User functions----------*/
int ReadPin(int iMASK)													//function for reading pin input
{
	int iStatus;
	iStatus = (1 >> (P0 & iMASK)) == (1 >> iMASK);
	return(iStatus);
}
/*----------User code---------------*/
int main(void) 														//main function
{
	
	InitTouchP0P1("1");												//Display initialisation
	
  while (1)														//Loop forever
  {
    //write 10/10 code here
  }
}
