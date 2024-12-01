#include "testCases.hpp"

//public run tests only!
void testCases::runTests() {
	std::cout
	<< "--------- START TESTS --------- " << std::endl
	<< "testContinuousKeyInput() pass: : " << testContinuousKeyInput() << std::endl
	<< "testComputeDirection() pass: " << testComputeDirection() << std::endl
	<< "testGetandSetHP() pass: " << testGetandSetHP() << std::endl
	<< "testIsDead() pass: " << testIsDead() << std::endl
	<< "testAttackUntilDead() pass: " << testAttackUntilDead() << std::endl
	<< "testLoadSprite() pass: " << testLoadSprite() << std::endl
	<< "--------- END TESTS --------- " << std::endl;
}

//default constructor + destructor :(
testCases::testCases() {
	this->s = new SpriteManager();
}
testCases::~testCases() {
	delete this->s;
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
	float tol = 0.001; // precision issues, adding tolerance for some leeway

	//
	Entity one(5, this->s->getGnome());
	Entity two(5, this->s->getGnome());
	one.mBody.setPosition(sf::Vector2f(0,0));
	two.mBody.setPosition(sf::Vector2f(1,1));
	

	sf::Vector2f out = computeDirection(one, two, sqrt(2));

	if (//check x, y pos in an acceptable range
		out.x <= two.mBody.getPosition().x + tol
		&&
		out.x >= two.mBody.getPosition().x - tol
		&&
		out.y <= two.mBody.getPosition().y + tol
		&&
		out.y >= two.mBody.getPosition().y - tol
		) {

		Entity three(5, this->s->getGnome());
		three.mBody.setPosition(5,5);

		out = computeDirection(one, three, sqrt(32));
		int expectedX = 4;
		int expectedY = 4;
		if (
			out.x <= expectedX + tol
			&&
			out.x >= expectedX - tol
			&&
			out.y <= expectedY + tol
			&&
			out.y >= expectedY - tol
		) {
			//woohoo! Vector math :D
			ok = true;
		}
	}

	return ok;
}

bool testCases::testGetandSetHP() {
	bool ok = false;

	Entity one(5, this->s->getGnome());

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

	Entity one(5, this->s->getGnome());

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
	

	Entity one(5, this->s->getGnome());
	Entity two(5, this->s->getGnome());

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

// SpriteManager tests
bool testCases::testLoadSprite() {
	bool ok = false;

	sf::Event event;

	SpriteManager s;
	sf::RenderWindow window(
        sf::VideoMode(1000, 1000),
        "gnome sprite test"
        );

	// gnome from file
	sf::Texture t; // load straight from file
	t.loadFromFile("assets/gnome2.png");
	sf::Sprite fileGnome(t); // -> check output

	// ***CLOSE WINDOW TO ADVANCE THRU TEST***

	while (window.isOpen()) {

		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.draw(fileGnome);
		window.display();
		window.clear(sf::Color::Black);
	}
	window.create(sf::VideoMode(1000, 1000), "mushroom sprite test");

	// mushroom from file
	t.loadFromFile("assets/mushroomHouse2.png");
	sf::Sprite fileMushroom(t);

	while (window.isOpen()) {

		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.draw(fileMushroom);
		window.display();
		window.clear(sf::Color::Black);
	}
	window.create(sf::VideoMode(1000, 1000), "copy gnome sprite test");

	// create sprite from loaded gnome!
	sf::Sprite copyGnome(s.getGnome());

	while (window.isOpen()) {

		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.draw(copyGnome);
		window.display();
		window.clear(sf::Color::Black);
	}
	window.create(sf::VideoMode(1000, 1000), "copy mushroom sprite test");

	// create sprite from loaded gnome!
	sf::Sprite copyMushroom(s.getMushroomTower());

	while (window.isOpen()) {

		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.draw(copyMushroom);
		window.display();
		window.clear(sf::Color::Black);
		//step += step;
		//while (clock() < step) {;}
	}
	window.create(sf::VideoMode(1000, 1000), "copy big gnome sprite test");

	// create sprite from loaded gnome!
	sf::Sprite copyBigGnome(s.getBigGnome());

	while (window.isOpen()) {

		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.draw(copyBigGnome);
		window.display();
		window.clear(sf::Color::Black);
		//step += step;
		//while (clock() < step) {;}
	}

	return true;// -> visual test good!
}

//TowerDefenseGame tests
bool testCases::testGetPlayer() {
	return false;
}

bool testCases::getHostPlayer() {
	return false;
}

//bool testRun(); //-> not needed calls main funcs

bool testCases::testMapBonus() {
	return false;
}


