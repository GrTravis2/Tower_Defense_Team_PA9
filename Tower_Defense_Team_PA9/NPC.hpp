#pragma once

#include "Player.hpp"

enum difficulty {
	easy,
	medium,
	hard,
	evil,
};
class NPC : public Player {

private:
	//what data should go here
	int mWordsPerMinute; //set to spawn bonuses by time?
	int mCountDown; //timer to spawn next bonus based on words

	//helpers

public:

	//constructor
	NPC(
		const teamNumber& playerID,
		const sf::Sprite& body,
		const difficulty& diff
		);

	//destructor
	~NPC();

	//getters

	//setters

	//public

};

