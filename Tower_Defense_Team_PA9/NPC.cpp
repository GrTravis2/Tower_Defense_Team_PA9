#include "NPC.hpp"

//constructor
NPC::NPC (
    const teamNumber& playerID,
    const sf::Sprite& body,
    const difficulty& diff
    ) : Player(playerID, 30, body) {

        int wordsPerMin = -1;
    switch(diff) {
        case easy:
            wordsPerMin = 50;
            break;
        case medium:
            wordsPerMin = 70;
            break;
        case hard:
            wordsPerMin = 100;
            break;
        case evil:
            wordsPerMin = 150;
            break;
    }

    this->mDelaySeconds = 60.f / wordsPerMin; // -> evals to (seconds / word) time delay
    this->mNextBonusTime = clock() + (CLOCKS_PER_SEC * this->mDelaySeconds);// -> next due
}

//destructor
NPC::~NPC() {
    //do absolutely nothin'
}

//getters
float NPC::getDelaySeconds() const {
    return this->mDelaySeconds;
}

//setters
void NPC::setNextBonusTime(const clock_t& newTime) {
    this->mNextBonusTime = newTime;
}

//public
bool NPC::isReady() const {
    bool ready = false;

    if(clock() > this->mNextBonusTime) {ready = true;}

    return ready;
}

Bonus NPC::rollBonus() const {// -> generate a random bonus from pool

    //int bonus = (std::rand() % spawn5) + 1;// -> set to last when all bonuses are written
    int bonus = 0;
    return static_cast<Bonus>(bonus);// -> sketchy cast of rand int -> enum might break >:) 
}