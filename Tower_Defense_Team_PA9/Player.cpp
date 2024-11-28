#include "Player.hpp"

//constructor
Player::Player(
	const int& playerID,
	const int& HP,
	const sf::Sprite& body
) : Entity(HP, body) {
	this->mplayerID = playerID;
	

	//filling extra values with garbage, set later!
	this->input = "";
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

std::string Player::getInput() const
{
	return this->input;
}

int Player::getPoints() const
{
	return this->points;
}

void Player::setPoints(int newPoints)
{
	this->points = newPoints;
}

void Player::processInput()
{
	// :o
}
