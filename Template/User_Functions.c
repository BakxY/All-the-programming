/*-----Function for reading single pin-----*/
int ReadPin(int iPin)								//function for reading pin input
{
  int iMask[] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80}; //array for masks which are used to read the status
	int iStatus;                      //variable for storing status of pin
	iStatus = (1 >> (P0 & iMask[iPin])) == (1 >> iMask[iPin]);	//get status of selected pin
	return(iStatus);                  //returning pin status
}
/*-----Function for edge detection-----*/
int EdgeDet(int* iStatusOld, int* iStatusNew, int iEdgeType)	//function for edge detection (iEdgeType -> 0 = NEG / 1 = POS)
{
	if(*iStatusOld != *iStatusNew)								//compare old status to new status
	{
		if(*iStatusNew == iEdgeType)							//check for positive or negative edge (dependent on iEdgeType)
		{
			*iStatusOld = *iStatusNew;	
			return(1);											//return 1 if it has an edge
		}
		
		*iStatusOld = *iStatusNew;								//set old status to new status
	}
	return(0);													//return 0 if it doesn't have a flag
}
/*-----Function for reading full port-----*/
void ReadPort(int* iPin0, int* iPin1, int* iPin2, int* iPin3, int* iPin4, int* iPin5, int* iPin6, int* iPin7)
{
	int iPort;
	
	iPort = P0;
	
	*iPin0 = 0x01;
	*iPin1 = 0x02 >> 1;
	*iPin2 = 0x04 >> 2;
	*iPin3 = 0x08 >> 3;
	*iPin4 = 0x10 >> 4;
	*iPin5 = 0x20 >> 5;
	*iPin6 = 0x40 >> 6;
	*iPin7 = 0x80 >> 7;
}

/*-----Function for blinking LED-----*/
int BlinkLED(int iOn, int iOff, int* iTimer)	//function for LED blinking
{
	if(*iTimer < iOn)							//check if timer reached value of iOn
	{
		return(1);								//return status 1
	}
	else if(*iTimer < (iOn + iOff))				//check if timer reached value of iOn + iOff
	{
		return(0);								//return status 0
	}
	else										//else for if the if isn't true
	{
		*iTimer = 0;							//reset timer
		return(0);								//return status 0
	}
}
