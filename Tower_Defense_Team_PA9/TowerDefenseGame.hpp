#pragma once

#include <list>
#include <ctime>
#include <iostream>

#include "Player.hpp"
#include "Entity.hpp"

//Game Constants!!

//window size constants
#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 1000

//player info
#define MAX_PLAYERS 4

//Time constants
#define MAX_FPS 60 //frames per second

//path and movement constants
//right now position/direction are based on enitity locations!


class TowerDefenseGame {
private:
	Player* mPlayers;
	Player* mHostPlayer;
	std::list<Entity*>* mMasterList; //list of entities on the heap, should this be pub??
	sf::RenderWindow* mGameWindow;//?????? will need to check I got right.. Public as well?

	//helpers
	void printMultiplayerMenu() const;// for join/create game
	
public:

	//constructor
	TowerDefenseGame();// -> start default and add thru setters?

	//destructor
	~TowerDefenseGame();

	//getters
	Player* getPlayer(const int& playerID) const;
	Player* getHostPlayer() const;

	//setters

	//input player and their ID (player1, player2, player3, player4)
	void setPlayer(const int& playerID, const Player*& player);

	void processInput();// -> for handling keyboard event process!

	void updateWords();// -> for handling word and bonus options!

	// takes bonus enum and adds bonus entity(s) to master list
	void mapBonus(enum Bonus& bonus);

	//updates shape positions, checks for intersections, and then draws all!
	void updateEntities();

	//checks game conditions for if they are over
	bool GameComplete() const;

	//public

	void run();
};

//non-member data
/*
We talked about having all of the word choices and bonuses here!
I will start the arrays but we will have to fill as we go!
*/

const std::string wordPool[] = {
	"walnut",
	"yo",
	"queue", // ;)
	"algorithm",
	"nerd",
	"sorcerer",
	"carrot",
};

