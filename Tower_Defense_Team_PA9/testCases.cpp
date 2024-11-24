#include "testCases.hpp"

void testCases::testContinuousKeyInput()
{
	sf::Event event;
	inputClass testInput;

	// simulating a key press 
	event.type = sf::Event::KeyPressed;
	event.key.code = sf::Keyboard::A;
	testInput.processEvent(event);
	if (testInput.getCurrentInput() == "a")
	{
		cout << "Test successful, keyboard event adds a to current input" << endl;
	}
	else
	{
		cout << "Test failed, simulated key press did not add to current input as expected" << endl;
	}

}
