//						 ***Wheel***
//					
// The Wheel represents a single rotor wheel inside the EncryptionDevice.
//
// It is comprised of a variable amount of "pins" which are set to either
// 0 or 1 and are configured on object instantiation. Its purpose is to 
// return the "current" or "facing" pin, which is used to create the 
// encryption key. 
//
// It can also be "turned" by one single pin by the 
// EncryptionDevice after an encryption has been performed.

#pragma once
#include <vector>

class Wheel
{
public:
	// Constructor
	// Initializes currentPinLocation to 0.
	Wheel(void);

	// Destructor
	~Wheel(void);

	// "Turns" the Wheel by one pin. 
	// Parameters: None.
	// Returns: None.
	void turnWheel(void);

	// Returns the current "facing" pin.
	// Parameters: None.
	// Returns: None.
	int getCurrentPin(void);

	// Sets the values of the pins of the Wheel from string pinSettings.
	void setPins(std::string pinSettings);

private:
	// Holds the values of the pins.
	std::vector<int> pins;
	// Holds the index of the "current" pin.
	unsigned int currentPinLocation;
};

