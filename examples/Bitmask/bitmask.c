/*-----------------------------------
* Project:  Reads with Bitmask			*
* Autor:    SSP				              *
* Date:     11.03.2021		          *
* Dep:      b4 microcontrollers		  *
* uC:       STM32F107VC				      *
------------------------------------*/

/*----------Libraries---------------*/
#include <stm32f10x.h>								    //include header file for uC
#include "TouchP0P1.h"								    //include header file for display
/*----------Defines-----------------*/
#define true 1										        //define a constant for 1
#define false 0										        //define a constant for 0

#define MASK_S0 0x01								      //define masks for bit masking
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
int ReadPin(int iMASK)								    //function for reading pin input
{
	int iStatus;
	iStatus = (1 >> (P0 & iMASK)) == (1 >> iMASK);	//get status of selested button
	return(iStatus);
}
/*----------User code---------------*/
int main(void) 														//main function
{
	int iStatusPin0;                        //creating iStatusPin0 for storing the value of Pin 0 Port 0
  
	InitTouchP0P1("1r");										//Display initialisation
	
  while (1)																//Loop forever
  {
    iStatusPin0 = ReadPin(MASK_S0);       //Pin 0 of Port 0 is read with the readPin() function and stored in the iStatusPin0 variable
    
    if(iStatusPin0 == true)               //iStatusPin0 is compared to true
    {
      P1_0 = true;                        //Pin 0 of Port 1 is set to true
    }
    else                                  //else for iStatusPin0 is compared to true if not correct
    {
      P1_0 = false;                       //Pin 0 of Port 1 is set to false
    }
  }
}
