#include "Player.hpp"


////constructor
//Player::Player(
//	const int& playerID,
//	const int& HP,
//	const sf::Sprite& body
//) : Entity(HP, body) {
//	this->mplayerID = playerID;
//	
//
//	//filling extra values with garbage, set later!
//	this->playerInput.clearInput();
//	this->wordTimer = -1;
//	this->wordTimerMax = -1;
//	this->wordOptions[0] = "";
//	this->wordOptions[1] = "";
//	this->wordOptions[2] = "";
//	this->wordOptions[3] = "";
//	this->points = -1;
//
//}

Player::Player(const int& playerID, const int& HP, const sf::Sprite& body) : Entity(HP, body)
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

bool Player::processPlayerInput()
{
	string currentInput = playerInput.getCurrentInput();
	
	for (int i = 0; i < 3; i++)
	{
		if (currentInput == wordOptions[i])
		{
			cout << "Word matched!" << endl;
			playerInput.clearInput();
			return true; 
		}
	}
	return false;
	
}

void Player::setWordChoices()
{
	
}



void Player::displayWords()
{
	for (int i = 0; i < 3; i++)
	{
		cout << "Word #" << i + 1 << ":" << wordOptions[i] << endl;
	}
}

