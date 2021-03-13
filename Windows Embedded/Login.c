void Login(void)
{
	/*-----------VERSION TEXT----------*/
	textxy("FischerTG_Login_V1.1", 0, 315, WHITE, BLACK);
	/*-----------VARIABLES-------------*/
	char *cUser = "User";
	char *cPass = "Pass";
	/*----------WELCOME TEXT-----------*/
	textxy("#  # ### #   #   ###    ### ", 8, 15, WHITE, BLACK);
	textxy("#  # #   #   #   # #  # #  #", 8, 30, WHITE, BLACK);
	textxy("#### ##  #   #   # #    #  #", 8, 45, WHITE, BLACK);
	textxy("#  # #   #   #   # #  # #  #", 8, 60, WHITE, BLACK);
	textxy("#  # ### ### ### ###    ### ", 8, 75, WHITE, BLACK);
	/*-----------LOGIN LOGO------------*/
	circle(120, 120, 15, 4, WHITE, 0);
	circle(120, 165, 30, 4, WHITE, 0);
	rectan(80, 165, 160, 200, 1, BLACK, 1);
	circle(120, 140, 50, 4, WHITE, 0);
	/*-----------LOGIN TEXT------------*/
	textxy("Username:", 50, 220, WHITE, BLACK);
	textxy(cUser, 125, 220, WHITE, BLACK);
	textxy("Password:", 50, 235, WHITE, BLACK);
	textxy(cPass, 125, 235, WHITE, BLACK);
}
