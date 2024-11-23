#pragma once

#include <list>
#include "Player.hpp"

class TowerDefenseGame {
private:
	Player* mPlayers[4] = {};
	Player* mHostPlayer;
	std::list<Entity*> mMasterList; //list of entities on the heap, should this be pub??
	sf::Window mGameWindow;//?????? will need to check I got right.. Public as well?

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


	//public

	void processInput();// -> for handling keyboard event process!

	void updateWords();// -> for handling word and bonus options!

	// takes bonus enum and adds bonus entity(s) to master list
	void mapBonus(enum Bonus& bonus);

	//updates shape positions, checks for intersections, and then draws all!
	void updateEntities();

};

//non-member data
/*
We talked about having all of the word choices and bonuses here!
I will start the arrays but we will have to fill as we go!
*/

const std::string wordPool[]{
	"walnut",
	"yo",
	"queue", // ;)
	"algorithm",
	"nerd",
	"sorcerer",
	"carrot",
};

