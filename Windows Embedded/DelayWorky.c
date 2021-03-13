void delayWorky(int time)
{
	while(time--) //do until time = 0
	{
        __nop(); //uC skipps 1 cycle of operation
	}
}
