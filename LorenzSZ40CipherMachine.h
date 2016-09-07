//				***LorenzSZ40CipherMachine***
//
// The LorenzSZ40CipherMachine represents the entire physical machine, 
// including the teleprinter attachment.
//
// It will accept a character from the user, and using its Teleprinter 
// and EncryptionDevice objects return it fully encrypted. 
// It essentially controls the flow of information from the user to the 
// Teleprinter, EncryptionDevice and back to the user.
//
// Provided the internal configuration is correct, the 
// LorenzSZ40CipherMachine can also take an encrypted character and
// decrypt it with the same process as above.

#pragma once
#include "Teleprinter.h"
#include "EncryptionDevice.h"

class LorenzSZ40CipherMachine
{
public:
	// Default Constructor
	LorenzSZ40CipherMachine(void);

	// Default Constructor
	~LorenzSZ40CipherMachine(void);

	// Takes an input character, encrypts it and returns it to the 
	// user, using the Teleprinter and EncryptionDevice objects.
	// Parameters: char input - The input letter to be encrypted.
	// Returns: Returns the encrypted character, as type char.
	char processCharacter(char input);
	
private:
	Teleprinter teleprinter;
	EncryptionDevice encryptionDevice;
};

