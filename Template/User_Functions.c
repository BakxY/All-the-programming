/*-----Function for reading single pin-----*/
int ReadPin(int iPin)								//function for reading pin input
{
  int iMask[] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80}; //array for masks which are used to read the status
	int iStatus;                      //variable for storing status of pin
	iStatus = (1 >> (P0 & iMask[iPin])) == (1 >> iMask[iPin]);	//get status of selected pin
	return(iStatus);                  //returning pin status
}
/*-----Function for setting full PORT from array-----*/
void OutputPort(int iStatePort[])
{
  int iMaskP[] = {0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01};  //array for masks which are used to set the port to 1
  int iMaskN[] = {0x7F, 0xBF, 0xDF, 0xEF, 0xF7, 0xFB, 0xFD, 0xFE};  //array for masks which are used to set the port to 0
  int iCount;                              //placeholder variable for the for loops
  
  for(iCount = 0; iCount <= 8; iCount++)             //for loop which is used to cycle the masks 
  {
    if(iStatePort[iCount] == 1)            //compare wanted state of pin with 1
    {
      P1 |= iMaskP[iCount];                //set single pin with the positiv mask
    }
    else if(iStatePort[iCount] == 0)
    {
      P1 &= iMaskN[iCount];                //set single pin with the negativ mask
    }
  }
}

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
