/*---------------------------------------
* Library:  MCB32D.c					*
* Autor:    S.Sprenger & A.Hofmann		*
* Date:     08.04.2021					*
* Revision: 17.06.2021 / AH				*
* Dep:      b4 microcontrollers			*
* uC:       STM32F107VC					*
----------------------------------------*/

/*---------------------------------------
* Revision history
-----------------------------------------
* Revision 10.06.2021 / AH
* Small edits on functions
* Revision 17.06.2021 / AH
* Visual cleanup of functions
* Simplification of functions
* Comments -> explaining variables
* MCB32D_InitLED function
----------------------------------------*/

/*-------------INCLUDES-----------------*/
#include <stm32f10x.h>							//include uC specific header file
#include "TouchP0P1.h"							//include display specific header file
#include "MCB32D.h"								//include board specific custom header file
/*---------------------------------------
* Function: iReadPin					*
* Autor:    Severin Sprenger			*
* Date:     08.04.2021					*
* Desc: 	Reading a single pin		*
----------------------------------------*/
int iReadPin(int iPin)								//function for reading pin input, iPin -> selected pin of input port
{
	int iStatus;									//create variable iStatus
	iStatus = !(1 >> (P0 & (0x01 << iPin))); 		//get status of selected pin
	return(iStatus);								//returning pin status
}

/*---------------------------------------
* Function: iEdgeDet					*
* Autor:    Alessandro Hofmann			*
* Date:     08.04.2021					*
* Desc: 	Detecting an edge on a pin	*	
----------------------------------------*/
int iEdgeDet(int* piStatusOld, int* piStatusNew, int iEdgeType)	//function for edge detection, piStatusOld -> old button state, piStatusNew -> new button state, iEdgeType -> for which edge to check 0 = NEG / 1 = POS
{	
	if (*piStatusOld != *piStatusNew)		//compare old status to new status
	{
		if (*piStatusNew == iEdgeType)		//check for positive or negative edge (dependent on iEdgeType)
		{
			*piStatusOld = *piStatusNew;	//set old status to new status
			return(1);						//return 1 if it has the selected edge
		}
		else								//else for if the if isn't true
		{
			*piStatusOld = *piStatusNew;	//set old status to new status
			return(0);						//return 0 if it doesn't have the selected edge
		}
	}
	else									//else for if the if isn't true
	{
		return(0);							//return 0 if new state equals old state
	}
}

/*---------------------------------------
* Function: vReadPort					*
* Autor:    Severin Sprenger			*
* Date:     08.04.2021					*
* Revision: 17.06.2021 / AH				*
* Desc: 	Read a full port to a array	*
----------------------------------------*/
void vReadPort(int iStatusArray[8])					//function for reading a full port into array, iStatusArray -> array in which the values are stored
{
	int iCounter;                       			//create variable iCounter
	for (iCounter = 0; iCounter <= 7; iCounter++) 	//for loop for reading all 8 pins
	{
		iStatusArray[iCounter] = (P0 & (0x01 << iCounter)) >> iCounter; //shift mask and mask port, shift back for 1 or 0, safe in array
	}
}

/*---------------------------------------
* Function: iBlinkLED					*
* Autor:    Alessandro Hofmann			*
* Date:     08.04.2021					*
* Revision: 17.06.2021 / AH				*
* Desc: 	Blink a LED with set times	*
----------------------------------------*/
int iBlinkLED(int iOn, int iOff, int* piTimer)	//function for LED blinking, iOn -> on period, iOff -> off period, piTimer -> Timer for blinking LED
{
	if (*piTimer < iOn)					//check if timer value is smaller than iOn value
	{
		return(1);						//return status 1
	}
	else if (*piTimer < (iOn + iOff))	//check if timer value is smaller than iOn + iOff value
	{
		return(0);						//return status 0
	}
	else								//else for if the if isn't true
	{
		*piTimer = 0;					//reset timer
		return(0);						//return status 0
	}
}

/*---------------------------------------
* Function: vSendPort					*
* Autor:    Alessandro Hofmann			*
* Date:     09.04.2021					*
* Revision: 17.06.2021 / AH				*
* Desc: 	Write to port from array	*
----------------------------------------*/
void vSendPort(int iStatusArray[8])					//function for sending full port from array, iStatusArray -> array from which the values are read
{
	int iCounter;									//create variable iCounter
	for(iCounter = 0; iCounter <= 7; iCounter++)	//for loop for sending status to pins
	{
		if(iStatusArray[iCounter] == 1)				//check if the status is 1
		{
			P1 |= (0x01 << iCounter);				//write mask for 1 on port 1
		}
		else										//else for if the if isn't true
		{
			P1 &= ((0x01 << iCounter) ^ 0xFF);		//write mask for 0 on port 1
		}
	}
}

/*---------------------------------------
* Function: vClearPort					*
* Autor:    Alessandro Hofmann			*
* Date:     09.04.2021					*
* Revision: 17.06.2021 / AH				*
* Desc: 	Set an array to 0x00		*
----------------------------------------*/
void vClearArray(int iStatusArray[8])				//function for clearing an array, iStatusArray -> array which is set to 0x00
{ 
	int iCounter;             						//create variable iCounter          
	for(iCounter = 0; iCounter <= 7; iCounter++)	//for loop for setting array to 0
	{
		iStatusArray[iCounter] = 0;					//set selected array to 0
	}
}

/*---------------------------------------
* Function: MCB32D_InitLED				*
* Autor:    Alessandro Hofmann			*
* Date:     17.06.2021					*
* Desc: 	Initialise GPIOs for LEDs	*
----------------------------------------*/
void MCB32D_InitLED(void)				//function for initialising GPIOs for correct LED behaviour
{
	GPIOE->CRH = 0x33333333;			//configurate pins E8 - E15 to push-pull and 50MHz update rate
	
	GPIOE->ODR = 0xFF00;				//set PORT E 0xFF00
	delay_ms(500);						//wait 500ms
	GPIOE->ODR = 0x0000;				//set PORT e 0x0000
}
