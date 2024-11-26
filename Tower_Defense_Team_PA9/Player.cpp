#include "Player.hpp"

//constructor
	Player::Player(
		const int& playerID,
		
	) {

}

std::string Player::getInput() const
{
	return input;
}

int Player::getPoints() const
{
	return points;
}

void Player::setPoints(int newPoints)
{
	points = newPoints;
}

void Player::processInput()
{

}
