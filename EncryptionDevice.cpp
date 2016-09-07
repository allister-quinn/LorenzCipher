#include "stdafx.h"
#include "EncryptionDevice.h"

EncryptionDevice::EncryptionDevice(void)
{
	setWheels();
}


EncryptionDevice::~EncryptionDevice(void)
{
}


int EncryptionDevice::encryptITA2(int ITA2)
{
	// XOR ITA2 code with key, return.
	ITA2 ^= getEncryptionKey();
	turnWheels();
	return ITA2;
}


// Creates encryption key by concatenating from left to right the values of
// the "facing pins" of the 5 Chi wheels into a 5-digit binary string. It then
// does the same for the Psi Wheels, creating 2 5-digit binary strings. Finally, 
// it XORs these two 5-digit strings together to give the key. As an example:
// 
//		Wheel:  CHI1 CHI2 CHI3 CHI4 CHI5  M37 M61  PSI1 PSI2 PSI3 PSI4 PSI5  
//		Pin:	 1    0    0    0    1     0   1    1    1    1    0    0
//
// Here, the function will return 10001 ^ 11100, which is 01101.
int EncryptionDevice::getEncryptionKey(void)
{
	// Get pin value of leftmost Wheel in Psi and Chi sets.
	int chiKey = chi[0].getCurrentPin();
	int psiKey = psi[0].getCurrentPin();

	// Bitshift this value left then OR with next leftmost pin value,
	// 4 times, to concantenate the values into a bitstring.
	for(int i = 1; i < 5; i++)
	{
		chiKey <<= 1;
		chiKey |= chi[i].getCurrentPin();
		psiKey <<= 1;
		psiKey |= psi[i].getCurrentPin();
	}
	
	// Return the key, the XOR value of the two bitstrings.
	return (chiKey ^ psiKey);
}


void EncryptionDevice::turnWheels(void)
{
	// 1) Always turn the Chi wheels
	for(int i = 0; i < 5; i++)
	{
		chi[i].turnWheel();
	}

	// 2) If M37 is 1, turn the Psi Wheels
	if(m37.getCurrentPin() == 1)
	{
		for(int i = 0; i < 5; i++)
		{
			psi[i].turnWheel();
		}
	}

	// 3) If M61 is 1, turn the M37 Wheel
	if(m61.getCurrentPin() == 1)
	{
		m37.turnWheel();
	}

	// 4) Always turn the M61 Wheel
	m61.turnWheel();
}


void EncryptionDevice::setWheels(void)
{
	// Get pin data from file, store in string pinSettings
	std::string pinSettings;
	std::ifstream infile;
	infile.open("pinsettings.dat");
	getline(infile,pinSettings);
	infile.close(); 

	// Send substrings of pinSettings to Wheels as per information in the
	// coursework specification. setPins will create and configure pins.
	psi[0].setPins(pinSettings.substr(0, 43));  
	psi[1].setPins(pinSettings.substr(43, 47));
	psi[2].setPins(pinSettings.substr(90, 51));
	psi[3].setPins(pinSettings.substr(141, 53));
	psi[4].setPins(pinSettings.substr(194, 59));

	m37.setPins(pinSettings.substr(253, 37));
	m61.setPins(pinSettings.substr(290, 61));

	chi[0].setPins(pinSettings.substr(351, 41));
	chi[1].setPins(pinSettings.substr(392, 31));
	chi[2].setPins(pinSettings.substr(423, 29));
	chi[3].setPins(pinSettings.substr(452, 26));
	chi[4].setPins(pinSettings.substr(478, 23));
}
