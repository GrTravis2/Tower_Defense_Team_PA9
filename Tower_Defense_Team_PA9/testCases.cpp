#include "testCases.hpp"

/*
* Test function for continuous input:
* this function simulates 3 button presses (a, b, and backspace) and tests are passed/failed depending 
* on whether the letter is successfully added/removed from the current input string initialized in the inputClass class

*/
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
		cout << "Test 1 successful, keyboard event adds 'a' to current input" << endl;
	}
	else
	{
		cout << "Test 1 failed, simulated key press did not add to current input as expected" << endl;
	}

	// simulating a second key press
	event.key.code = sf::Keyboard::B;
	testInput.processEvent(event);
	if (testInput.getCurrentInput() == "ab")
	{
		cout << "Test 2 successful, 'b' added to current input" << endl;
	}
	else
	{
		cout << "Test 2 failed, simulated key press did not add to current input as expected" << endl;
	}

	// simulating a backspace press
	event.key.code = sf::Keyboard::BackSpace;
	testInput.processEvent(event);
	if (testInput.getCurrentInput() == "a")
	{
		cout << "Test 3 successful, 'b' removed from current input" << endl;
	}
	else
	{
		cout << "Test 3 failed, simulated key press did not remove 'b' from current input as expected" << endl;
	}

}

void testCases::testClearInput()
{
	sf::Event event;
	inputClass testInput;

	event.type = sf::Event::KeyPressed;
	event.key.code = sf::Keyboard::A;
	testInput.processEvent(event);
	event.key.code = sf::Keyboard::B;
	testInput.processEvent(event);

	if (testInput.getCurrentInput() == "ab")
	{
		cout << "Current input: " << testInput.getCurrentInput() << endl;
	}
	else
	{
		cout << "Input not adjusted as expected!" << endl;
	}
	testInput.clearInput();
	cout << "Clearing input..." << endl;
	if (testInput.getCurrentInput() == "")
	{
		cout << "Test successful, current input is empty!" << endl;
	}
	else
	{
		cout << "Test unsuccessful, current input still contains data!" << endl;
	}
	
}
