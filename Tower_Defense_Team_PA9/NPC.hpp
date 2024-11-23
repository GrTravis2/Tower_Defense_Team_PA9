#pragma once

#include "Player.hpp"

class NPC : public Player {

private:
	//what data should go here
	int mWordsPerMinute; //set to spawn bonuses by time?
	int mCountDown; //timer to spawn next bonus based on words

	//helpers

public:

	//constructor

	//destructor

	//getters

	//setters

	//public

};

enum difficulty {
	easy,
	medium,
	hard,
	evil,
};