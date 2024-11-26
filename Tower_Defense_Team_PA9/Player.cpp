#include "Player.hpp"

//constructor
Player::Player(
	const int& playerID,
	const int& HP,
	const sf::RectangleShape& body,
	const Entity& start,
	const Entity& end,
	const float& speed
) : Entity(HP, body, start, end, speed) {
	this->mplayerID = playerID;
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
