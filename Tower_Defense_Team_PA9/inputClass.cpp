#include "inputClass.hpp"

inputClass::inputClass()
{
	currentInput = "";
}

void inputClass::updateInput(char typedLetter)
{

	if (typedLetter >= 32 && typedLetter <= 126) // all typeable characters
	{
		currentInput += typedLetter; // appends to input string
	}
	if (typedLetter == '\b' && !currentInput.empty()) // backspace 
	{
		currentInput.pop_back();
	}
}

void inputClass::clearInput()
{
	currentInput.clear();
}

void inputClass::printInput()
{
	cout << "Word entered: " << currentInput << endl;
}

string inputClass::getCurrentInput()
{
	return currentInput;
}







