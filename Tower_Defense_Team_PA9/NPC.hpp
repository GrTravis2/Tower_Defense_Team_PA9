#pragma once
#include <ctime>
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
	float mDelaySeconds; //set to spawn bonuses by time?
	clock_t mNextBonusTime; // when past time spawn bonus!

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
	float getDelaySeconds() const;

	//setters
	void setNextBonusTime(const clock_t& newTime);

	//public
	bool isReady() const;// -> check if ready to send bonus

	Bonus rollBonus() const;// -> generate a random bonus from pool
};

