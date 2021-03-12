void BlueScreen(void)
{
	clearScreen(BRIGHT_BLUE);
	
	/*-----------VERSION TEXT----------*/
	textxy("FischerTG_BlueScreen_V1", 0, 315, WHITE, BRIGHT_BLUE);
	/*------------BSoD TEXT------------*/
	textxy("    #       ##  ###     ##", 10, 30, WHITE, BRIGHT_BLUE);
	textxy("o  #        # # #       # #", 10, 42, WHITE, BRIGHT_BLUE);
	textxy("   #        ##  ### ### # #", 10, 54, WHITE, BRIGHT_BLUE);
	textxy("o  #        # #   # # # # #", 10, 66, WHITE, BRIGHT_BLUE);
	textxy("    #       ##  ### ### ##", 10, 78, WHITE, BRIGHT_BLUE);
	/*-------------RESTART-------------*/
	textxy("your uController has ran in", 10, 110, WHITE, BRIGHT_BLUE);
	textxy("a problem and needs restart", 10, 125, WHITE, BRIGHT_BLUE);
	delayWorky(0xA00000);
	/*----------ERROR TEXT-------------*/
	textxy("an exception has occurred at", 10, 165, WHITE, BRIGHT_BLUE);
	textxy("0x07FA'884A OVERFLOW ERROR", 10, 180, WHITE, BRIGHT_BLUE);
	textxy("triggered by: infinite loop", 10, 195, WHITE, BRIGHT_BLUE);
	delayWorky(0xA00000);
	/*----------ERROR CODE-------------*/
	textxy("error-code: 404 not found", 10, 250, WHITE, BRIGHT_BLUE);
	delayWorky(0xF00000);
	clearScreen(BLACK);
}
