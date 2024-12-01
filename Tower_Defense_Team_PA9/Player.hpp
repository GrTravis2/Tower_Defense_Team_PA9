#pragma once

#include <string>
#include "Entity.hpp"
#include "inputClass.hpp"

#define PLAYER_BODY_WIDTH 10.f
#define PLAYER_SPEED 0.f

class Player : public Entity {
private:
	//player specific data
	int mplayerID;
	//network stuff??
	
	
	//typing specific data
	inputClass playerInput; // current input class that holds string + state of keys/mouse

	int wordTimer; //count up timer for word update
	int wordTimerMax; // value word will update when timer reaches
	std::string wordOptions[4]; //word options to type //  added 4th box for wildcard - Ingrid
	int points;//**What will this be doing?? -Gavin
	
	//helpers

public:

	//constructor
	


	Player(
		const int& playerID,
		const int& HP,
		const sf::Sprite& body,
		const Entity& start,
		const Entity& end,
		const float& speed
	);

	
	//// added this because my compiler had an issue with the constructor 
	//Player(const int& playerID, const int& HP, const sf::Sprite& body);

	//destructor
	~Player();

	//getters
	std::string getInput();

	int getPoints() const;

	//setters
	void setPoints(int newPoints);
	

	//public funcs
	void updateInput();
	void clearInput();
	bool processPlayerInput();
	void setWordChoices();
	void displayWords();

	
};

//we can give these more specific names when we lock down the bonuses
enum Bonus {
	spawn1,
	spawn5,
	spawnBigGnome,
};
