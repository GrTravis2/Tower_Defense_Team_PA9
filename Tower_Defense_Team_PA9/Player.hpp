#pragma once

#include <string>
#include "Entity.hpp"

#define PLAYER_BODY_WIDTH 10.f
#define PLAYER_SPEED 0.f
#define PLAYER_HP 30

class Player : public Entity {
private:
	//player specific data
	int mplayerID;
	//network stuff??

	//typing specific data
	std::string input; //string that holds current input
	int wordTimer; //count up timer for word update
	int wordTimerMax; // value word will update when timer reaches
	std::string wordOptions[4]; //word options to type
	int points;//**What will this be doing? -Gavin
	
	//helpers

public:

	//constructor
	Player(
		const int& playerID,
		const int& HP,
		const sf::Sprite& body
		);

	//destructor
	~Player();

	//getters
	std::string getInput() const;

	int getPoints() const;

	//setters
	void setPoints(int newPoints);

	//public funcs

	void processInput();

	
};

//we can give these more specific names when we lock down the bonuses
enum Bonus {
	spawn1,
	spawn5,
	spawnBigGnome,
};