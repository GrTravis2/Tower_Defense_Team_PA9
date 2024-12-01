#pragma once

#include <list>
#include <ctime>
#include <iostream>
#include <SFML/Graphics.hpp>

#include "Player.hpp"
#include "NPC.hpp"
#include "Entity.hpp"
#include "SpriteManager.hpp"
#include "inputClass.hpp"


//Game Constants!!

//window size constants
#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 1000

//player info
#define MAX_PLAYERS 4
#define P1_XPOS 0
#define P1_YPOS 0
//other place 

//Time constants
#define MAX_FPS 60 //frames per second

//path and movement constants
//right now position/direction are based on enitity locations!

class TowerDefenseGame {
private:
	Player* mPlayer1;// players, might as well be hard coded :D
	Player* mPlayer2;
	Player* mPlayer3;
	Player* mPlayer4;
	Player* mHostPlayer;// leaving uncoupled for now in case networking
	std::list<Entity*>* mMasterList; // all objects to update
	sf::RenderWindow* mGameWindow;// view window (does drawing)
	SpriteManager* spawner; //spawns sprite types

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

	//setup game
	void setupGame();

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
	"cowboy",
	"synergy",
	"frame",
	"monitor",
	"webcam",
	"sanitize",
	"pop",
	"break",
	"time",
	"gather",
	"cougar"
};

string* getWordChoices();



