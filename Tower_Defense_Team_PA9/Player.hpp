
#include <string>
#include "Entity.hpp"

class Player : public Entity {
private:
	//player specific data
	enum playerID;
	//network stuff??

	//typing specific data
	std::string input; //string that holds current input
	int wordTimer; //count up timer for word update
	int wordTimerMax; // value word will update when timer reaches
	std::string wordOptions[3]; //word options to type
	
	//helpers

	void printMenu() const;// for join/create game

public:
	//constructor

	//destructor

	//getters

	//setters

	//public funcs

	void processInput();// -> for handling keyboard event process!

	void updateWords();// -> for handling word and bonus options!

	//updates shape positions, checks for intersections, and then draws all!
	void updateEntities();
};

enum playerID {
	player1,
	player2,
	player3,
	player4,
};

//we can give these more specific names when we lock down the bonuses
enum Bonus {
	spawn1,
	spawn5,
	spawnBigGnome,
};