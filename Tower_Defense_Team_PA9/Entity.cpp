
#include "Entity.hpp"

//need to add before it will build :-)

//constructor
Entity::Entity(// -> for static entities (players)
		const int& HP,
		const sf::Sprite& body
	) {
    this->mHealthPoints = HP;
    this->mBody = body;
}
Entity::Entity(
    const int& HP, // -> obj HP, when it hits 0 will get deleted!
    const sf::Sprite& body,// -> pass shape constructor
    const Entity& start,// -> spawning tower ref
    const Entity& end,// -> target tower ref
    const float& speed// -> define constant in wrapper by type
    ) {
    this->mHealthPoints = HP;
    this->mBody = body;//init body with reference to body
    this->mBody.setPosition(start.mBody.getPosition());// start at spawning player
    this->mDirection = computeDirection(start, end, 0.1); //set direction vec
}
	

//destructor
Entity::~Entity() {
    // no heap data, do nothing :)
}

//getters
int Entity::getHP() const {
    return this->mHealthPoints;
}

//setters
void Entity::setHP(const int& newHP) {
    this->mHealthPoints = newHP;
}

//public
//move function? -> should be in SFML class

bool Entity::isDead() const {
    bool dead = false;

    if (this->getHP() <= 0) { dead = true; }

    return dead;
}

//helpers
sf::Vector2f computeDirection(const Entity& start, const Entity& end, const float& speed) {
    sf::Vector2f vecStart = start.mBody.getPosition();
    sf::Vector2f vecEnd = end.mBody.getPosition();
    float xComp = vecEnd.x - vecStart.x;// need to double check my vec formulas
    float yComp = vecEnd.y - vecStart.y;// i have no internet
    float mag = sqrt(pow(xComp, 2) + pow(yComp, 2));

    sf::Vector2f vecResult;
    vecResult.x = speed * (xComp / mag);
    vecResult.y = speed * (yComp / mag);

    return vecResult;
}


//non-member

//when two shapes intersect have them subtract HP's from each other
//until one is "dead" (no HP)
void attackUntilDead(Entity& lhs, Entity& rhs) {
    int leftHP = lhs.getHP();// read out current HPs
    int rightHP = rhs.getHP();

    //do nothing while hps decrement until at least one is 0
    while (leftHP != 0 && rightHP != 0) {
        --leftHP;
        --rightHP;
    }
    
    //update HPs
    lhs.setHP(leftHP);
    rhs.setHP(rightHP);

    //check for dead entity here or in main?
    // -> do in main loop! can do during main loop and cleaup at same time

}
