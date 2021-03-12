/*-----Function for reading single pin-----*/
int ReadPin(int iMASK)								//function for reading pin input !!! needs mask in calling -> S5 = ReadPin(MASK_S5); !!!
{
	int iStatus;									//create variable
	iStatus = (1 >> (P0 & iMASK)) == (1 >> iMASK);	//get status of selected button
	return iStatus;									//return status of selected pin	
}
//use in main
int main(void)
{
	int iPIN2;
	iPIN2 = ReadPin(MASK_S2);						//Masks found in Defines.c
}
/*-----Function for reading full PORT in array-----*/
int* ReadPort(void)									//function for reading port input
{	
	int iPinArray[8];
	for (int i = 0; i < 8; i++)						//for loop for scaning the seperate pins
	{
		iPinArray[i] = P0 & 0x01 << i && 1;			//saving of seperate pins in array
	}
	return iPinArray;								//return the port in array !!! needs to be safed in int pointer -> int* iPinArray; -> iPinArray = ReadPort(); !!!
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
//use in main
int main(void)
{
	int* iPinArray;									//create pointer variable
	iPinArray = ReadPort();
}
