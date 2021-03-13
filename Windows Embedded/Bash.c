//these variables need to be global
int iOpfer = 0; 											//Opfervariable for evading coruption on array xy
int yx[2] = {1, 0};

void Bash(void)
{
  textxy("BakxY_Bash_V3", 0, 315, WHITE, BLACK);
  
  int iInput;
  int iStatus[8];
  
  /*---------Reading PORT-----------*/
  iInput = GPIOGetByte("PDH");
  iStatus[0] = !((1 >> (iInput & 0x10)) == (1 >> 0x10)); //Up
  iStatus[1] = !((1 >> (iInput & 0x40)) == (1 >= 0x40)); //Down
  iStatus[2] = !((1 >> (iInput & 0x08)) == (1 >> 0x08)); //Right
  iStatus[3] = !((1 >> (iInput & 0x20)) == (1 >= 0x20)); //Left
	
  /*-------Setting x and y----------*/
	if((iStatus[0] == 1) || (iStatus[1] == 1) || (iStatus[2] == 1) || (iStatus[3] == 1))
	{
		rectan(yx[1], yx[0], yx[1]+8, yx[0]+14, 2, BLACK, 0);
		if(iStatus[0] == 1 && yx[0] != 1)
		{
			yx[0] -= 16;
			delayWorky(0x3FFF00);
		}
		else if(iStatus[1] == 1 && yx[0] <= 280)
		{
			yx[0] += 16;
			delayWorky(0x3FFF00);
		}
		else if(iStatus[2] == 1 && yx[1] <= 230)
		{
			yx[1] += 8;
			delayWorky(0x3F0000);
		} 
		else if(iStatus[3] == 1 && yx[1] >= 8)
		{
			yx[1] -= 8;
			delayWorky(0x3F0000);
		}
		rectan(yx[1], yx[0], yx[1]+8, yx[0]+14, 2, BRIGHT_RED, 0);
	}
}
