#include "inputClass.hpp"

inputClass::inputClass()
{
	// initializing all key and mouse states to false using iteration
	for (int i = 0; i < TOTAL_KEYS; i++)
	{
		stateOfKeys[i] = false;
	}
	for (int i = 0; i < TOTAL_MOUSE_BUTTONS; i++)
	{
		stateOfMouse[i] = false;
	}
	currentInput = "";
}

void inputClass::processEvent(sf::Event& event) // this allows for key presses to be monitored constantly 
{
	if (event.type == sf::Event::KeyPressed)
	{
		stateOfKeys[event.key.code] = true; // marks pressed key to true
		
		if (event.key.code >= sf::Keyboard::A && event.key.code <= sf::Keyboard::Z)
		{
			currentInput += (char)('a' + (event.key.code - sf::Keyboard::A)); //offset based on ascii table 
		}
		else if (event.key.code == sf::Keyboard::BackSpace)
		{
			if (!currentInput.empty()) // if the current input isnt empty 
			{
				currentInput.pop_back();
			}
		}
		
	}
	else if (event.type == sf::Event::KeyReleased) // marks pressed key to false
	{
		stateOfKeys[event.key.code] = false;
	}

}

void inputClass::clearInput()
{
	for (int i = 0; i < TOTAL_KEYS; i++)
	{
		stateOfKeys[i] = false;
	}
	for (int i = 0; i < TOTAL_MOUSE_BUTTONS; i++)
	{
		stateOfMouse[i] = false;
	}
	currentInput = "";
}

void inputClass::printInput()
{
	cout << "Word entered: " << currentInput << endl;
}

string inputClass::getCurrentInput()
{
	return currentInput;
}

bool inputClass::getIsKeyPressed(sf::Keyboard::Key& key)
{	
	return stateOfKeys[key];
}
