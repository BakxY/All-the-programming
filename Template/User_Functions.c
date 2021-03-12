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
  int iMaskP[] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80};  //array for masks which are used to set the port to 1
  int iMaskN[] = {0xFE ,0xFD ,0xFB ,0xF7 ,0xEF ,0xDF ,0xBF ,0x7F};  //array for masks which are used to set the port to 0
  int i;                              //placeholder variable for the for loops
  
  for(i = 0; i <= 8; i++)             //for loop which is used to cycle the masks 
  {
    if(iStatePort[i] == 1)            //compare wanted state of pin with 1
    {
      P1 |= iMaskP[i];                //set single pin with the positiv mask
    }
  }
  for(i = 0; i <= 8; i++)             //for loop which is used to cycle the masks
  {
    if(iStatePort[i] == 0)            //compare wanted state of pin with 0
    {
      P1 &= iMaskN[i];                //set single pin with the negativ mask
    }
  }
}
//use in main
int main(void)
{
	int* iPinArray;									//create pointer variable
	iPinArray = ReadPort();
}
