void SystemCheck(void)
{
	/*----------VERSION TEXT----------*/
	textxy("FischerTG_SystemCheck_V2.1", 0, 315, WHITE, BLACK);
	/*-----------VARIABLES------------*/
	int iCount;
	int iMCount = 1;
	/*----------TITLE TEXT------------*/
	printAt(0, "System check started");
	printAt(1, "--------------------");
	
	while(iCount < 10)
	{
		setTextcolor(WHITE);
	/*----------SPINNI BOY-----------*/
		printAt(3, "/");
		delayWorky(0x100000);
		printAt(3, "-");
		delayWorky(0x100000);
		printAt(3, "\\");
		delayWorky(0x100000);
		printAt(3, "|");
		delayWorky(0x100000);
	/*------------LOADING------------*/
		iMCount = iCount;
		while(iMCount > 0)
		{
			print(" o");
			iMCount--;
		}
		iCount++;
	/*-----------CHECK TEST----------*/
		setTextcolor(BRIGHT_GREEN);
		switch(iCount)
		{
			case 2:
				printAt(5, "uController: STM32F107VC");
				break;
			case 3:
				printAt(6, "uC Initialisation OK");
				break;
			case 4:
				printAt(7, "LCD Initialisation OK");
				break;
			case 5:
				printAt(8, "Systemclock 12MHZ OK");
				break;
			case 6:
				printAt(9, "RAM Check OK");
				break;
			case 7:
				printAt(10, "Driver updated OK");
				break;
			case 8:
				printAt(11, "OS System updated OK");
				break;
			case 9:
				printAt(12, "Securing from NDB");
				break;
			case 10:
				printAt(15, "All OK starting OS");
				delayWorky(0xF00000);
				clearScreen(BLACK);
				break;
			default:
				break;
		}
	}
}
