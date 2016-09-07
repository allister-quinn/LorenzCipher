//				***EncryptionDevice***
//
// The EncryptionDevice represents the encryption unit.
//
// It is what actually encrypts a given ITA2 code, using // a key formed
// from the current state of the facing pins of its Wheels (see below).
//
// It is also responsible for turning the Wheels, so that every time an 
// encryption is performed it either will turn or not turn each individual
// Wheel according to a pre-defined set of logic rules.

#pragma once
#include "Wheel.h"
#include <fstream>
#include <string>
#include <iostream>

class EncryptionDevice
{
public:
	// Default Constructor
	EncryptionDevice(void);

	// Default Constructor
	~EncryptionDevice(void);


	// Encrypts and returns an inputted ITA2 code by XOR-ing it with an encryption key. 
	// Also runs the turnWheels() function with every encryption. 
	// Parameters: int ITA2 - The ITA2 code to be encrypted.
	// Returns: Returns the encrypted ITA2 code in the form of an int.
	int encryptITA2(int ITA2);

private:
	// Returns the current encryption key, which is based on the value of the "facing"
	// pin values of the Psi and Chi wheels. 
	// Parameters: None.
	// Returns: Returns encryption key as in int.
	int getEncryptionKey(void);

	// Turns the Wheels based on a set of predefined logical rules as per specification.
	// Parameters: None.
	// Returns:	None.
	void turnWheels(void);

	// Gets the initial pin settings for all the wheels from a data file, and sends the 
	// relevant portion of data to each corresponding Wheel. The Wheel itself will then 
	// create and configure its own pins with the setPins() function.
	// Parameters: None.
	// Returns: None.
	void setWheels(void);
	
	// Wheels as per the coursework specification.
	Wheel chi[5];
	Wheel psi[5];
	Wheel m37;
	Wheel m61;
};

