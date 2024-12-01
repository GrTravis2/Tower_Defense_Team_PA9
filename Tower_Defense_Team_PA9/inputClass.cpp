#include "inputClass.hpp"

inputClass::inputClass()
{
	currentInput = "";
}

void inputClass::updateInput()
{
	bool backspacePressed = false;
	for (int i = sf::Keyboard::A; i <= sf::Keyboard::Z; i++) // setting index to the key value of keyboard press A
	{														// the loop goes on until you hit z
		if (sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(i))) // casting the integer i to enum keyboard type, allowing it to be evaluated 
		{																	// checks if "this" key is pressed
			char inputChar = 'a' + (i - sf::Keyboard::A);	// i = int value of key
			// calculated offset based on ascii values 

			currentInput += inputChar;

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
		{
			if (!backspacePressed && !currentInput.empty()) // if the current input isnt empty + bksp pressed
			{
				//cout << "A letter is supposed to be removed here" << endl;
				currentInput.pop_back();
				backspacePressed = true;
			}
			else
			{
				backspacePressed = false;
			}
		}
	}
}

void inputClass::clearInput()
{
	//cout << "Hi I'm clearInput() in the input class" << endl;
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

void inputClass::setNewChoices()
{

}






