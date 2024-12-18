#include "testCases.hpp"
#include "TowerDefenseGame.hpp"

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
    << "testWordDisplay() pass: " << testWordDisplay() << std::endl
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
    inputClass testInputClass;
    sf::Event event;
    char testInput;
    bool success = false;

    // simulating a key press 
    event.type = sf::Event::KeyPressed;
    event.key.code = sf::Keyboard::A;
    testInput = static_cast<char>(event.key.code = sf::Keyboard::A);
    testInputClass.updateInput(testInput);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        success = true;
        //cout << "Test successful, keyboard event adds a to current input" << endl;
    }
    else
    {
        //cout << "Test failed, simulated key press did not add to current input as expected" << endl;
    }

    return success;
}

//entity tests
bool testCases::testComputeDirection() {
	bool ok = false;
	float tol = 0.001; // precision issues, adding tolerance for some leeway

	//
	Entity one(5, four, this->s->getGnome());
	Entity two(5, four, this->s->getGnome());
	one.mBody.setPosition(sf::Vector2f(0,0));
	two.mBody.setPosition(sf::Vector2f(1,1));
	

	sf::Vector2f out = computeDirection(one.mBody.getPosition(), two.mBody.getPosition(), sqrt(2));

	if (//check x, y pos in an acceptable range
		out.x <= two.mBody.getPosition().x + tol
		&&
		out.x >= two.mBody.getPosition().x - tol
		&&
		out.y <= two.mBody.getPosition().y + tol
		&&
		out.y >= two.mBody.getPosition().y - tol
		) {

		Entity three(5, four, this->s->getGnome());
		three.mBody.setPosition(5,5);

		out = computeDirection(one.mBody.getPosition(), three.mBody.getPosition(), sqrt(32));
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

	Entity one(5, three, this->s->getGnome());

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

	Entity one(5, three, this->s->getGnome());

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
    

	Entity one(5, three, this->s->getGnome());
	Entity two(5, four, this->s->getGnome());

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
	copyGnome.setPosition(500, 500);

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

bool testCases::testWordDisplay() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Word Display Test");
    WordDisplay wordDisplay;
    Player player1(one, 30, sf::Sprite());

    // Set words for player1
    for (int i = 0; i < 3; ++i) {
        player1.setWord(i, generateRandomWord());
    }
    player1.setWord(3, generateExtremeWord()); // Add the extreme word

    // Set rewards for word display
    std::string rewards[4] = {"Reward 1", "Reward 2", "Reward 3", "Reward 4"};
    wordDisplay.setRewards(rewards);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        wordDisplay.displayPlayerWords(window, &player1);
        window.display();
    }

    return true; // Visual test, if words and rewards appear correctly, the test is successful
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



