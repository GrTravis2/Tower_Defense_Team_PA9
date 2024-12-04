#include "NPC.hpp"

//constructor
NPC::NPC (
    const teamNumber& playerID,
    const sf::Sprite& body,
    const difficulty& diff
    ) : Player(playerID, 30, body) {
    this->mWordsPerMinute = 50;
    this->mCountDown = -1;
}

//destructor
NPC::~NPC() {
    //do absolutely nothin'
}