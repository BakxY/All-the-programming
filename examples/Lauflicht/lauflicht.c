/*-----------------------------------
* Project:  Lauflicht         			*
* Autor:    SSP             				*
* Date:     11.03.2021		          *
* Dep:      b4 microcontrollers		  *
* uC:       STM32F107VC			      	*
------------------------------------*/

/*----------Libraries---------------*/
#include <stm32f10x.h>								//include header file for uC
#include "TouchP0P1.h"								//include header file for display
/*----------Defines-----------------*/
#define TRUE 1										    //define a constant for 1
#define FALSE 0										    //define a constant for 0

#define MASK_S0 0x01								  //define masks for bit masking
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
int main(void) 										    //main function
{
	int iBuffer;                        //P1Controll will store the value of P1 for data computing
  int x;                              //x is a temporary variable used for storage
  
	InitTouchP0P1("1r");								//Display initialisation r -> rotated display
	
  P1 = 0x11;                          //A start value is given to P1, in this case 0x11 (Bin: 0001'0001).
  
	while (1)
	{
		iBuffer = P1;                     //The value of P1 is written to iBuffer
    iBuffer = iBuffer << 1;           //The value of iBuffer is shifted by 1 to the left
    P1 = P1 << 1;                     //The value of P1 is shifted by 1 to the left
    x = iBuffer & 0x100;              //x is set to iBuffer and 0x100 logically connected
    P1 |= x>>8;                       //P1 is set ti the value of P1 and the 8 time right shifted value of x
    delay_ms(250);                    //250ms of delay
	}
}
