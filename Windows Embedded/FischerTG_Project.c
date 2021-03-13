//komplete inebastlerei

#include <stm32f10x.h>
#include "TouchP0P1.h"

unsigned int x = 8; //These need to be global variables
unsigned int y = 1;

void delayWorky(int time)
{
	while(time--) //do until time = 0
	{
        __nop(); //uC skipps 1 cycle of operation
	}
}
void BootLogo(void)
{
	/*-----------VERSION TEXT----------*/
	textxy("FischerTG_BootLogo_V5", 0, 315, WHITE, BLACK);
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
	delayWorky(0x971B00);
	textxy("o                10%", 40, 265, WHITE, BLACK);
	delayWorky(0x971B00);
	textxy("o o              21%", 40, 265, WHITE, BLACK);
	delayWorky(0x971B00);
	textxy("o o o            38%", 40, 265, WHITE, BLACK);
	delayWorky(0x971B00);
	textxy("o o o o          51%", 40, 265, WHITE, BLACK);
	delayWorky(0x971B00);
	textxy("o o o o o        69%", 40, 265, WHITE, BLACK);
	delayWorky(0x971B00);
	textxy("o o o o o o      88%", 40, 265, WHITE, BLACK);
	delayWorky(0x971B00);
	textxy("o o o o o o o    99%", 40, 265, WHITE, BLACK);
	delayWorky(0x1F71B00); 
	textxy("o o o o o o o o 101%", 40, 265, WHITE, BLACK);
	delayWorky(0x971B00);
	/*----------SUCCESS TEXT-----------*/
	textxy("SUCCESS !!!", 40, 280, WHITE, BLACK);
	delayWorky(0xEE3600);
	
	clearScreen(BLACK);
}

void SystemCheck(void)
{
	/*----------VERSION TEXT----------*/
	textxy("FischerTG_SystemCheck_V3", 0, 315, WHITE, BLACK);
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
		delayWorky(0xDC6C0);
		printAt(3, "-");
		delayWorky(0xDC6C0);
		printAt(3, "\\");
		delayWorky(0xDC6C0);
		printAt(3, "|");
		delayWorky(0xDC6C0);
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
				delayWorky(0xEE3600);
				clearScreen(BLACK);
				break;
			default:
				break;
		}
	}
}

void BlueScreen(int iErrorCode)
{	
	clearScreen(BRIGHT_BLUE);
	
	/*-----------VERSION TEXT----------*/
	textxy("FischerTG_BlueScreen_V2", 0, 315, WHITE, BRIGHT_BLUE);
	/*------------BSoD TEXT------------*/
	textxy("    #       ##  ###     ##", 10, 30, WHITE, BRIGHT_BLUE);
	textxy("o  #        # # #       # #", 10, 42, WHITE, BRIGHT_BLUE);
	textxy("   #        ##  ### ### # #", 10, 54, WHITE, BRIGHT_BLUE);
	textxy("o  #        # #   # # # # #", 10, 66, WHITE, BRIGHT_BLUE);
	textxy("    #       ##  ### ### ##", 10, 78, WHITE, BRIGHT_BLUE);
	/*-------------RESTART-------------*/
	textxy("your uController has ran in", 10, 110, WHITE, BRIGHT_BLUE);
	textxy("a problem and needs restart", 10, 125, WHITE, BRIGHT_BLUE);
	delayWorky(0x971B00);
	/*----------ERROR TEXT-------------*/
	textxy("an exception has occurred at", 10, 165, WHITE, BRIGHT_BLUE);
	textxy("0x07FA'884A OVERFLOW ERROR", 10, 180, WHITE, BRIGHT_BLUE);
	textxy("triggered by: infinite loop", 10, 195, WHITE, BRIGHT_BLUE);
	delayWorky(0x971B00);
	/*----------ERROR CODE-------------*/
	if(iErrorCode == 1)
	{
		textxy("error-code: 360 dis button", 10, 250, WHITE, BRIGHT_BLUE);
	}
	else
	{
		textxy("error-code: 404 not found", 10, 250, WHITE, BRIGHT_BLUE);	
	}
	delayWorky(0xEE3600);
	clearScreen(BLACK);
}

int main(void)
{	
	InitTouchScreen();
	
	SystemCheck();
	BootLogo();
	BlueScreen(0);
}
