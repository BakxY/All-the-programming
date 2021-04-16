/*-----------------------------------
* Library:  MCB32D.h				*
* Autor:    Severin Sprenger		*
* Date:     08.04.2021				*
* Dep:      b4 microcontrollers		*
* uC:       STM32F107VC				*
------------------------------------*/

/*-------------Includes-------------*/
#include "MCB32D.h"
#include "TouchP0P1.h"

/*-----------------------------------
* Function: ReadPin					*
* Autor:    Severin Sprenger		*
* Date:     08.04.2021				*
* Desc: Reading a single pin		*
------------------------------------*/
int ReadPin(int iPin)					//function for reading pin input
{
	int iMask[] = { 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80 }; //array for masks which are used to read the status
	int iStatus;						//variable for storing status of pin
	iStatus = (1 >> (P0 & iMask[iPin])) == (1 >> iMask[iPin]); //get status of selected pin
	return(iStatus);					//returning pin status
}

/*-----------------------------------
* Function: EdgeDet					*
* Autor:    Alessandro Hofmann		*
* Date:     08.04.2021				*
* Desc: Detecting an edge on a pin	*
------------------------------------*/
int EdgeDet(int* iStatusOld, int* iStatusNew, int iEdgeType) //function for edge detection (iEdgeType -> 0 = NEG / 1 = POS)
{
	if (*iStatusOld != *iStatusNew)		//compare old status to new status
	{
		if (*iStatusNew == iEdgeType)	//check for positive or negative edge (dependent on iEdgeType)
		{
			*iStatusOld = *iStatusNew;
			return(1);					//return 1 if it has an edge
		}
		else
		{
			*iStatusOld = *iStatusNew;	//set old status to new status
      return(0);
		}
	}
	else
	{
		return(0);						//return 0 if it doesn't have a flag
	}
}

/*-----------------------------------
* Function: ReadPort				*
* Autor:    Severin Sprenger		*
* Date:     08.04.2021				*
* Desc: Read a full port to a array	*
------------------------------------*/
void ReadPort(int* iStatusArray)		//function for reading a full port into pointer array
{
	int iCounter;                       //decleration of iCounter
	for (iCounter = 0; iCounter <= 7; iCounter++) //for loop for reading pins and storing in array
	{
		iStatusArray[iCounter] = (P0 & (0x01 << iCounter)) >> iCounter; //reading port, masking and shiffting
	}
}

/*-----------------------------------
* Function: BlinkLED				*
* Autor:    Alessandro Hofmann		*
* Date:     08.04.2021				*
* Desc: Blink a LED with set times 	*
------------------------------------*/
int BlinkLED(int iOn, int iOff, int* iTimer) //function for LED blinking
{
	if (*iTimer < iOn)					//check if timer reached value of iOn
	{
		return(1);						//return status 1
	}
	else if (*iTimer < (iOn + iOff))	//check if timer reached value of iOn + iOff
	{
		return(0);						//return status 0
	}
	else								//else for if the if isn't true
	{
		*iTimer = 0;					//reset timer
		return(0);						//return status 0
	}
}

/*-----------------------------------
* Function: SendPort				*
* Autor:    Alessandro Hofmann		*
* Date:     09.04.2021				*
* Desc: Write to port from array 	*
------------------------------------*/
void SendPort(int *iStatusArray)					//function for sending full port from a pointer array
{
	int iCounter;									//decleration of iCounter
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

/*-----------------------------------
* Function: ClearPort				*
* Autor:    Alessandro Hofmann		*
* Date:     09.04.2021				*
* Desc: Set a port to 0x00			*
------------------------------------*/
void ClearArray(int *iStatusArray)					//function for clearing an array
{ 
  int iCounter;             						//declaration of iCounter          
  for(iCounter = 0; iCounter <= 7; iCounter++)		//for loop for setting array to 0
  {
    iStatusArray[iCounter] = 0;						//set selected array to 0
  }
}
