#pragma once
#include <string>
#include "Entity.hpp"
#include "inputClass.hpp"
using std::vector;
class WordDisplay; // Forward declaration

#define PLAYER_BODY_WIDTH 10.f
#define PLAYER_SPEED 0.f

#define P1_X 60 // -> p1 Position
#define P1_Y 70

#define P2_X -60 // -> p2 position
#define P2_Y 70

#define P3_X 60 // -> p3 position
#define P3_Y -50

#define P4_X -60 // -> p4 position
#define P4_Y -50

//window size constants
#define WINDOW_WIDTH 1500
#define WINDOW_HEIGHT 1000

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
    WordDisplay* wordDisplay; // Reference to WordDisplay

public:

	//constructor
	Player(
		const int& HP,
		const teamNumber& team,
		const sf::Sprite& body,
		const Entity& start,
		const Entity& end,
		const float& speed
	);

	
	//// added this because my compiler had an issue with the constructor 
	Player(const teamNumber& team, const int& HP, const sf::Sprite& body);

	//destructor
	virtual ~Player(); // -> virtual for death sound/animation

	//getters
	std::string getInput();
	int getPoints() const;

	//setters
	void setPoints(int newPoints);
    void setWordDisplay(WordDisplay* wd); // Setter for WordDisplay

	//public funcs
	void updateInput(char newChar);
	void clearInput();
	int processPlayerInput();
	void setWord(int index, string newWord);
	void displayWords(sf::RenderWindow& window); // Updated to take window parameter
	string getWord(int index) const;
	vector<bool> validateInput();
};

//we can give these more specific names when we lock down the bonuses
enum Bonus {
	spawn1,
	spawn5,
	plus5HP,
	plus10HP,
	spawnBigGnome,
	plus15HP,
	first = spawn1, // please update these if they change!!!
	last = plus15HP // they are used for rolling all bonuses
};
