//				***Teleprinter***
//
// The Teleprinter represents the teleprinter attachment.
//
// It has two functions: to accept a character and return its corresponding
// Baudot-Murray ITA2 code (a unique 5 digit binary string code representing 
// each character) and vice versa to return the corresponding character for 
// an ITA2 code.
//
// Data of which character corresponds with each ITA2 code and vice versa are
// stored inside the object.

#pragma once
#include <map>

class Teleprinter
{
public:
	// Default Constructor.
	// Runs populateMaps() at object instantiation.
	Teleprinter(void);

	//Default Destructor.
	~Teleprinter(void);

	// Takes an input character and returns its corresponding ITA2 code using a map.
	// Parameters: char input - The character for which the corresponding ITA2 code will be returned.
	// Returns: Returns the corresponding ITA2 code for the input. The ITA2 code is in decimal
	// form, for example if 'B' is input, the function will return 25 (the decimal value
	// of the binary ITA2 code for B, 11001).
	int letterToITA2(char input);

	// Takes an input ITA2 code and returns its corresponding character using a map.
	// Parameters: int input - The ITA2 code for which the corresponding character will be returned.
	// Returns: Returns the corresponding character for the input ITA2 code.
	char ITA2ToLetter(int input);

private:
	// Populates the maps letterToITA2Map and ITA2ToLetterMap with the Baudot-Murray codes
	// from Table 1 in the coursework specification.
	// Parameters: None. 
	// Returns: None.
	void populateMaps(void);

	// Maps to hold Baudot-Murray codes from Table 1 in the specification.
	std::map<char,int> letterToITA2Map;
	std::map<int, char> ITA2ToLetterMap;
};

