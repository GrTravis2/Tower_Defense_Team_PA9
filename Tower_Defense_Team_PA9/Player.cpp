#include "Player.hpp"
#include "WordDisplay.hpp"

Player::Player(const teamNumber& team, const int& HP, const sf::Sprite& body) : Entity(HP, team, body)
{
	this->playerInput.clearInput();
	this->wordTimer = -1;
	this->wordTimerMax = -1;
	this->wordOptions[0] = "";
	this->wordOptions[1] = "";
	this->wordOptions[2] = "";
	this->wordOptions[3] = "";
	this->points = -1;

}

//destructor
Player::~Player() {
	//nothing for now...
}

std::string Player::getInput() 
{
	return playerInput.getCurrentInput();
}

int Player::getPoints() const
{
	return this->points;
}

// I think this code is redundent b/c player inherits from entity which
// can call: entity->mBody->getPosition()!!! which is a tried and tested SFML function
// if you already have it working though its not a big deal -Gavin
sf::Vector2f Player::getPlayerPosition(int playerID)
{
	sf::Vector2f centerWindow(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
	switch (playerID)
	{
	case 1:
		return sf::Vector2f(centerWindow.x + P1_X, centerWindow.y + P1_Y);
	case 2:
		return sf::Vector2f(centerWindow.x + P2_X, centerWindow.y + P2_Y);
	case 3:
		return sf::Vector2f(centerWindow.x + P3_X, centerWindow.y + P3_Y);
	case 4:
		return sf::Vector2f(centerWindow.x + P4_X, centerWindow.y + P4_Y);
	default:
		std::cout << "zoo-wee-mama" << std::endl;
		return sf::Vector2f(0, 0);
	}

}

void Player::setPoints(int newPoints)
{
	this->points = newPoints;
}

void Player::updateInput()
{
	playerInput.updateInput();
}

void Player::clearInput()
{
	playerInput.clearInput();
}

int Player::processPlayerInput()
{
	string currentInput = playerInput.getCurrentInput();

	for (int i = 0; i < 3; i++)
	{
		if (currentInput == wordOptions[0]) //target player 2 
		{
			playerInput.clearInput();
			return 1; 
		}
		else if (currentInput == wordOptions[1]) // target player 3
		{
			playerInput.clearInput();
			return 2;
		}
		else if (currentInput == wordOptions[2]) // target player 4
		{
			playerInput.clearInput();
			return 3;
		}
		else if (currentInput == wordOptions[3]) // extreme word solved, random target?
		{
			playerInput.clearInput();
			return 4;
		}
	}

	return -1;
}

void Player::setWord(int index, string newWord)
{
	wordOptions[index] = newWord;
}

std::string Player::getWord(int index) const {
    return wordOptions[index];
}

void Player::setWordDisplay(WordDisplay* wd) {
    wordDisplay = wd;
}

void Player::displayWords(sf::RenderWindow& window) {
    if (wordDisplay) {
        wordDisplay->displayPlayerWords(window, this);
    } else {
        for (int i = 0; i < 4; i++) {
            std::cout << "Word #" << i + 1 << ":" << wordOptions[i] << std::endl;
            std::cout << "\n";
        }
    }
}

