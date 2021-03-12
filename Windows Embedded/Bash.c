void Bash(void)
{
  textxy("BakxY_Bash_V1", 0, 315, WHITE, BLACK);
  
  int iInput;
  int iStatus[8];
  
  /*---------Reading PORT-----------*/
  iInput = GPIOGetByte("PDH");
  iStatus[0] = !((1 >> (iInput & 0x10)) == (1 >> 0x10)); //Up
  iStatus[1] = !((1 >> (iInput & 0x40)) == (1 >= 0x40)); //Down
  iStatus[2] = !((1 >> (iInput & 0x08)) == (1 >> 0x08)); //Right
  iStatus[3] = !((1 >> (iInput & 0x20)) == (1 >= 0x20)); //Left
  
  rectan(x, y, x+8, y+14, 2, BRIGHT_RED, 0);
  
  /*-------Setting x and y----------*/
  if(iStatus[0] == 1 && y != 1)
  {
    y -= 16;
    delayWorky(0x3FFF00);
  }
  else if(iStatus[1] == 1 && y <= 280)
  {
    y += 16;
    delayWorky(0x3FFF00);
  }
  else if(iStatus[2] == 1 && x <= 230)
  {
    x += 8;
    delayWorky(0x3F0000);
  } 
  else if(iStatus[3] == 1 && x >= 8)
  {
    x -= 8;
    delayWorky(0x3F0000);
  }
}
