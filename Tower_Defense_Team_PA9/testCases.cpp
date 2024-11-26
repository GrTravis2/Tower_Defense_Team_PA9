#include "testCases.hpp"

//public run tests only!
void runTests() {
	std::cout
	<< "--------- START TESTS --------- " << std::endl
	<< "testContinuousKeyInput pass: : " << testContinuousKeyInput() << std::endl
	<< ""
	<< "--------- END TESTS --------- " << std::endl;
}

//private -> actual tests:

bool testCases::testContinuousKeyInput()
{
	sf::Event event;
	inputClass testInput;
	bool success = false;

	// simulating a key press 
	event.type = sf::Event::KeyPressed;
	event.key.code = sf::Keyboard::A;
	testInput.processEvent(event);
	if (testInput.getCurrentInput() == "a")
	{
		success = true;
		cout << "Test successful, keyboard event adds a to current input" << endl;
	}
	else
	{
		cout << "Test failed, simulated key press did not add to current input as expected" << endl;
	}

	return success;
}

//entity tests
	bool testComputeDirection() {
		bool ok = false;

		Entity one(5, sf::RectangleShape(sf::Vector2f(1,1)) );
		Entity two(5, sf::RectangleShape(sf::Vector2f(1,1)) );


	}

	bool testGetHP() {

	}

	bool testsetHP() {

	}

	bool testIsDead() {

	}

	bool testAttackUntilDead() {

	}

	//TowerDefenseGame tests
	bool testGetPlayer() {

	}

	bool getHostPlayer() {

	}

	//bool testRun(); //-> not needed calls main funcs
	bool testMapBonus() {

	}
