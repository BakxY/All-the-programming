void BootLogo(void)
{
	/*-----------VERSION TEXT----------*/
	textxy("FischerTG_BootLogo_V4", 0, 315, WHITE, BLACK);
	/*-----------VARIABLES-------------*/
	int iCount = 0;
	int ix, iy;
	/*-----------RED SQUARE------------*/
	ix = 35;
	iy = 42;
	for(iCount = 0; iCount < 7; iCount++)
	{
		ix += 5;
		iy -= 2;
		rectan(ix, iy, (ix+4), (iy+60), 1, BRIGHT_RED, 1);
	}
	for(iCount = 0; iCount < 5; iCount++)
	{
		ix += 5;
		iy += 2;
		rectan(ix, iy, (ix+4), (iy+60), 1, BRIGHT_RED, 1);
	}
	/*----------GREEN SQUARE-----------*/
	ix = 99;
	iy = 40;
	for(iCount = 0; iCount < 6; iCount++)
	{
		ix += 5;
		iy += 2;
		rectan(ix, iy, (ix+4), (iy+60), 1, BRIGHT_GREEN, 1);
	}
	for(iCount = 0; iCount < 6; iCount++)
	{
		ix += 5;
		iy -= 2;
		rectan(ix, iy, (ix+4), (iy+60), 1, BRIGHT_GREEN, 1);
	}
	/*-----------BLUE SQUARE-----------*/
	ix = 35;
	iy = 107;
	for(iCount = 0; iCount < 7; iCount++)
	{
		ix += 5;
		iy -= 2;
		rectan(ix, iy, (ix+4), (iy+60), 1, BRIGHT_BLUE, 1);
	}
	for(iCount = 0; iCount < 5; iCount++)
	{
		ix += 5;
		iy += 2;
		rectan(ix, iy, (ix+4), (iy+60), 1, BRIGHT_BLUE, 1);
	}
	/*----------YELLOW SQUARE----------*/
	ix = 99;
	iy = 105;
	for(iCount = 0; iCount < 6; iCount++)
	{
		ix += 5;
		iy += 2;
		rectan(ix, iy, (ix+4), (iy+60), 1, BRIGHT_YELLOW, 1);
	}
	for(iCount = 0; iCount < 6; iCount++)
	{
		ix += 5;
		iy -= 2;
		rectan(ix, iy, (ix+4), (iy+60), 1, BRIGHT_YELLOW, 1);
	}
	/*----------WINDOWS TEXT-----------*/
	textxy("MS-DOS 4.20", 40, 190, WHITE, BLACK);
	textxy("Embedded Edition", 40, 205, WHITE, BLACK);
	/*----------LOADING POINTS---------*/
	textxy("MS-DOS is updating", 40, 235, WHITE, BLACK);
	textxy("Please dont shut off", 40, 250, WHITE, BLACK);
	delayWorky(0xA00000);
	textxy("o                10%", 40, 265, WHITE, BLACK);
	delayWorky(0xA00000);
	textxy("o o              21%", 40, 265, WHITE, BLACK);
	delayWorky(0xA00000);
	textxy("o o o            38%", 40, 265, WHITE, BLACK);
	delayWorky(0xA00000);
	textxy("o o o o          51%", 40, 265, WHITE, BLACK);
	delayWorky(0xA00000);
	textxy("o o o o o        69%", 40, 265, WHITE, BLACK);
	delayWorky(0xA00000);
	textxy("o o o o o o      88%", 40, 265, WHITE, BLACK);
	delayWorky(0xA00000);
	textxy("o o o o o o o    99%", 40, 265, WHITE, BLACK);
	delayWorky(0xB00000); 
	textxy("o o o o o o o o 101%", 40, 265, WHITE, BLACK);
	delayWorky(0xA00000);
	/*----------SUCCESS TEXT-----------*/
	for(iCount = 0; iCount < 3; iCount++)
	{
		textxy("SUCCESS !!!", 40, 280, WHITE, BLACK);
		delayWorky(0x800000);
		textxy("           ", 40, 280, WHITE, BLACK);
		delayWorky(0x800000);
	}
	clearScreen(BLACK);
}
