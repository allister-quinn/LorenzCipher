#include "stdafx.h"
#include "Wheel.h"


Wheel::Wheel(void)
{
	// Facing pin set to the first pin at instantiation.
	currentPinLocation = 0;
}


Wheel::~Wheel(void)
{
}


// Here, the Wheel is not actually turned at all, in the sense that none
// of the pin values in the vector<int> pins ever move. Rather, we use
// the int currentPinLocation to hold the index of the "current" pin, and
// when the Wheel is "turned", the index is incremented so that it "points" 
// to the next pin.
void Wheel::turnWheel(void)
{
	currentPinLocation++;

	// When currentPinLocation points to the last pin and is incremented
	// set back to 0 to "loop" through the Wheel.
	if(currentPinLocation >= pins.size())
	{
		currentPinLocation = 0;
	}
}

// Return the "facing" pin with currentPinLocation as index of vector.
int Wheel::getCurrentPin(void)
{
	return pins[currentPinLocation];
}

// Sets the values of the pins of the Wheel to either 1 or 0, by reading from
// the binary string pinSettings which was extracted from the data file.
void Wheel::setPins(std::string pinSettings)
{
	for(std::size_t i = 0; i < pinSettings.length(); i++)
	{
		// Here we minus the character '0' to get the numeric value of the character 
		// rather than the ASCII value which would be 48 for 0 or 49 for 1.
		int pin = pinSettings[i] - '0'; 
		this->pins.push_back(pin);
	}
}