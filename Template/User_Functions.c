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
