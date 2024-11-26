#pragma once

#include <string>
#include "Entity.hpp"

#define PLAYER_BODY_WIDTH 10.f
#define PLAYER_SPEED 0.f

class Player : public Entity {
private:
	//player specific data
	int mplayerID;
	//network stuff??

	//typing specific data
	std::string input; //string that holds current input
	int wordTimer; //count up timer for word update
	int wordTimerMax; // value word will update when timer reaches
	std::string wordOptions[3]; //word options to type
	int points;
	
	//helpers

public:
	//constructor
	Player();

	//destructor

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