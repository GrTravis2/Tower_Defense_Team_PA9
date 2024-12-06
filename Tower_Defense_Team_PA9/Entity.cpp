#include "Entity.hpp"

//constructor
Entity::Entity(// -> for static entities (players)
		const int& HP,
        const teamNumber& team,
		const sf::Sprite& body
	) {
    this->mHealthPoints = HP;
    this->mTeamNumber = team;
    this->mBody = body;
    this->mDirection = sf::Vector2f(0.0, 0.0);
}
Entity::Entity(
    const int& HP, // -> obj HP, when it hits 0 will get deleted!
    const teamNumber& team, // -> for ignoring friendly fire
    const sf::Sprite& body,// -> pass shape constructor
    const Entity& start,// -> spawning tower ref
    const Entity& end,// -> target tower ref
    const float& speed// -> define constant in wrapper by type
    ) {
    this->mHealthPoints = HP;
    this->mTeamNumber = team;
    this->mBody = body;//init body with reference to body
    this->mBody.setPosition(start.mBody.getPosition());// start at spawning player
    this->mDirection = computeDirection(start.mBody.getPosition(), end.mBody.getPosition(), 0.075); //set direction vec
    //this->mDirection = computeDirection(start, end, 0.1); //set direction vec
}

//destructor
Entity::~Entity() {
    // no heap data, do nothing :)
}

//getters
int Entity::getHP() const {
    return this->mHealthPoints;
}

sf::Vector2f Entity::getDirection() const {
    return this->mDirection;
}

teamNumber Entity::getTeamNumber() const {
    return this->mTeamNumber;
}

//setters
void Entity::setHP(const int& newHP) {
    this->mHealthPoints = newHP;
}

void Entity::setDirection(const sf::Vector2f& direction){
    mDirection = direction;
}

void Entity::setTeamNumber(const teamNumber& newNumber) {
    this->mTeamNumber = newNumber;
}

//public

bool Entity::isDead() const {
    bool dead = false;

    if (this->getHP() <= 0) { dead = true; }

    return dead;
}

//helpers

sf::Vector2f computeDirection(const sf::Vector2f& start, const sf::Vector2f& end, const float& speed) {

    float xComp = end.x - start.x;// need to double check my vec formulas
    float yComp = end.y - start.y;// i have no internet
    float mag = sqrt(pow(xComp, 2) + pow(yComp, 2));
    if (mag == 0) { mag = 1; } // no dividing by 0 round these parts partner

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
}
