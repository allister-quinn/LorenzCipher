#include "stdafx.h"
#include "LorenzSZ40CipherMachine.h"

LorenzSZ40CipherMachine::LorenzSZ40CipherMachine(void)
{
}


LorenzSZ40CipherMachine::~LorenzSZ40CipherMachine(void)
{
}


char LorenzSZ40CipherMachine::processCharacter(char input)
{
	// Convert to ITA2, encrypt, convert back to character, return.
	input = teleprinter.letterToITA2(input);
	input = encryptionDevice.encryptITA2(input);
	input = teleprinter.ITA2ToLetter(input);
	return input;
}
