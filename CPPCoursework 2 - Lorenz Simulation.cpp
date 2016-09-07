#include "stdafx.h"
#include <iostream>
#include "LorenzSZ40CipherMachine.h"

int _tmain(int argc, _TCHAR* argv[])
{
	while(true)
	{
		// Instantiate machine. Machine will set up maps and pins and is ready to use.
		LorenzSZ40CipherMachine lorenzSZ40CipherMachine;
		int choice = 0;

		// Message to be encrypted.
		std::string message = "";
		std::cout << "Choose 1 to 4 for messages in Block 2 Workbook Task 2.4." << std::endl;
		std::cin >> choice;
		switch(choice)
		{
		case 1:
			message = "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG";
			break;
		case 2:
			message = "A MAN PROVIDED WITH PAPER PENCIL AND RUBBER AND SUBJECT TO STRICT DISCIPLINE IS IN EFFECT A UNIVERSAL MACHINE";
			break;
		case 3:
			message = "KIK!F*AOYTUUU,VGBDQKDP*GPVAZMROTX,VCF!C AFS NUARKLOGISGU*FBG!EBLQ-H* LX*K";
			break;
		case 4:
			message = "BVJM,*V*TMAK*ZMK-XHGDVEMGOZUER .XWNIASN NCOVJ,ABELCLOUG,AD*OBRFLJXH! APZ*HJFHG.CQJRB";
			break;
		}
		
		// Display original message, encrypt and display encrypted message.
		std:: cout << message << std::endl;
		for(std::size_t i = 0; i < message.size(); i++)
		{
			message[i] = lorenzSZ40CipherMachine.processCharacter(message[i]);
		}
		std::cout << message << std::endl << std::endl;
		std::cin.ignore();
	}
	return 0;
}