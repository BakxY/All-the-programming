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
//use in main
int main(void)
{
	int* iPinArray;									//create pointer variable
	iPinArray = ReadPort();
}
