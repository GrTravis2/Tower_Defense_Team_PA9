#include "testCases.hpp"

//public run tests only!
void runTests() {
	testCases t;
	std::cout
	<< "--------- START TESTS --------- " << std::endl
	<< "testContinuousKeyInput() pass: : " << t.testContinuousKeyInput() << std::endl
	<< "testComputeDirection() pass: " << t.testComputeDirection() << std::endl
	<< "testGetandSetHP() pass: " << t.testGetandSetHP() << std::endl
	<< "testIsDead() pass: " << t.testIsDead() << std::endl
	<< "testAttackUnitlDead() pass: " << t.testAttackUntilDead() << std::endl
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
	bool testCases::testComputeDirection() {
		bool ok = false;

		Entity one(5, sf::RectangleShape(sf::Vector2f(1,1)), ZERO_VEC, ZERO_VEC, 0);
		Entity two(5, sf::RectangleShape(sf::Vector2f(1,1)), ZERO_VEC, ZERO_VEC, 0);

		sf::Vector2f out = computeDirection(one, two);

		if (out.x == one.x && out.y == one.y) {

			Entity three(5, sf::RectangleShape(sf::Vector2f(5,5)), ZERO_VEC, ZERO_VEC, 0);

			out = computeDirection(one, three);
			if (out.x == 1000 && out.y == 1000) {
				// should never get here, verify vec formula T_T
				ok = true;
			}
		}

		return ok;
	}

	bool testCases::testGetandSetHP() {
		bool ok = false;

		Entity one(5, sf::RectangleShape(sf::Vector2f(1,1)), ZERO_VEC, ZERO_VEC, 0);

		if (one.getHP() == 5) {
			one.setHP(25);

			if (one.getHP() == 25) {

				one.setHP(7);
				if (one.getHP() == 7) {ok = true;}
			}
		}

		return ok;
	}

	bool testCases::testIsDead() {
		bool ok = false;

		Entity one(5, sf::RectangleShape(sf::Vector2f(1,1)), ZERO_VEC, ZERO_VEC, 0);

		if (one.isDead() == false) {

			one.setHP(0);

			if (one.isDead() == true) {

				one.setHP(-50);

				if (one.isDead() == true) {ok = true;}
			}
		}

		return ok;
	}

	bool testCases::testAttackUntilDead() {
		bool ok = false;

		Entity one(5, sf::RectangleShape(sf::Vector2f(1,1)), ZERO_VEC, ZERO_VEC, 0);
		Entity two(5, sf::RectangleShape(sf::Vector2f(1,1)), ZERO_VEC, ZERO_VEC, 0);

		attackUntilDead(one, two);
		if (one.isDead() && two.isDead()) {

			one.setHP(5);
			two.setHP(4);
			attackUntilDead(one, two);

			if (one.getHP() == 1 && two.isDead()) {

				one.setHP(6);
				two.setHP(7);
				attackUntilDead(one, two);
				if (one.isDead() && two.getHP() == 1) {ok = true;}
			}
		}

		return ok;
	}

	//TowerDefenseGame tests
	bool testCases::testGetPlayer() {

	}

	bool testCases::getHostPlayer() {

	}

	//bool testRun(); //-> not needed calls main funcs
	bool testCases::testMapBonus() {

	}
