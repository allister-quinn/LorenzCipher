#include "stdafx.h"
#include "Teleprinter.h"
#include <iostream>


Teleprinter::Teleprinter(void)
{
	populateMaps();
}


Teleprinter::~Teleprinter(void)
{
}


int Teleprinter::letterToITA2(char input)
{
	if(letterToITA2Map.count(input) == 1)
	{
		// Return ITA2 code if character found in map
		return letterToITA2Map[input];
	}
	else
	{
		// Notify user if invalid character.
		std::cout << "Error. Character " << input << " not found in map. Returning 0.\n";
		return 0;
	}
}


char Teleprinter::ITA2ToLetter(int input)
{
	if(ITA2ToLetterMap.count(input) == 1)
	{
		// Return character if ITA2 code found in map
		return ITA2ToLetterMap[input];
	}
	else
	{
		// Notify user if invalid ITA2. 
		std::cout << "Error. ITA2 code " << input << " not found in map. Returning 0.\n";
		return 0;
	}
}


void Teleprinter::populateMaps(void)
{
	// Populate letterToITA2Map.
	letterToITA2Map['A'] = 3;
	letterToITA2Map['B'] = 25;
	letterToITA2Map['C'] = 14;
	letterToITA2Map['D'] = 9;
	letterToITA2Map['E'] = 1;

	letterToITA2Map['F'] = 13;
	letterToITA2Map['G'] = 26;
	letterToITA2Map['H'] = 20;
	letterToITA2Map['I'] = 6;
	letterToITA2Map['J'] = 11;

	letterToITA2Map['K'] = 15;
	letterToITA2Map['L'] = 18;
	letterToITA2Map['M'] = 28;
	letterToITA2Map['N'] = 12;
	letterToITA2Map['O'] = 24;

	letterToITA2Map['P'] = 22;
	letterToITA2Map['Q'] = 23;
	letterToITA2Map['R'] = 10;
	letterToITA2Map['S'] = 5;
	letterToITA2Map['T'] = 16;

	letterToITA2Map['U'] = 7;
	letterToITA2Map['V'] = 30;
	letterToITA2Map['W'] = 19;
	letterToITA2Map['X'] = 29;
	letterToITA2Map['Y'] = 21;
	letterToITA2Map['Z'] = 17;

	letterToITA2Map['*'] = 0;
	letterToITA2Map[' '] = 4;
	letterToITA2Map[','] = 8;
	letterToITA2Map['-'] = 2;
	letterToITA2Map['!'] = 27;
	letterToITA2Map['.'] = 31;


	// Populate letterToITA2Map.
	ITA2ToLetterMap[3] = 'A';
	ITA2ToLetterMap[25] = 'B';
	ITA2ToLetterMap[14] = 'C';
	ITA2ToLetterMap[9] = 'D';
	ITA2ToLetterMap[1] = 'E';

	ITA2ToLetterMap[13] = 'F';
	ITA2ToLetterMap[26] = 'G';
	ITA2ToLetterMap[20] = 'H';
	ITA2ToLetterMap[6] = 'I';
	ITA2ToLetterMap[11] = 'J';

	ITA2ToLetterMap[15] = 'K';
	ITA2ToLetterMap[18] = 'L';
	ITA2ToLetterMap[28] = 'M';
	ITA2ToLetterMap[12] = 'N';
	ITA2ToLetterMap[24] = 'O';

	ITA2ToLetterMap[22] = 'P';
	ITA2ToLetterMap[23] = 'Q';
	ITA2ToLetterMap[10] = 'R';
	ITA2ToLetterMap[5] = 'S';
	ITA2ToLetterMap[16] = 'T';

	ITA2ToLetterMap[7] = 'U';
	ITA2ToLetterMap[30] = 'V';
	ITA2ToLetterMap[19] = 'W';
	ITA2ToLetterMap[29] = 'X';
	ITA2ToLetterMap[21] = 'Y';
	ITA2ToLetterMap[17] = 'Z';

	ITA2ToLetterMap[0] = '*';
	ITA2ToLetterMap[4] = ' ';
	ITA2ToLetterMap[8] = ',';
	ITA2ToLetterMap[2] = '-';
	ITA2ToLetterMap[27] = '!';
	ITA2ToLetterMap[31] = '.';
}