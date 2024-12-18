#pragma once
#include <math.h>
#include <SFML/Graphics.hpp>

enum teamNumber {
	one = 1,
	two,
	three,
	four
};

class Entity {
private:
	int mHealthPoints; //create helper function that computes changes in HP.
	sf::Vector2f mDirection;// -> controls direction and speed, set once at init!
	teamNumber mTeamNumber;

public:

	//pubic to access shape methods
	sf::Sprite mBody; //placeholder for whatever visual component we have for the entity
	//We also talked about adding some stats here, maybe should go into derived class for more custom stats?
	//I think the shape will also wrap position and movement functions with it! But we should verify the docs
	//Also not sure if we should make the shape public? it already has protected methods so should be ok??
	
	//constructor
	Entity(// -> for static entities (players)
		const int& HP,
		const teamNumber& team,
		const sf::Sprite& body
	);
	Entity(// -> for entities that move along a vector!
		const int& HP, // -> obj HP, when it hits 0 will get deleted!
		const teamNumber& team, // -> for ignoring friendly fire
		const sf::Sprite& body,// -> pass shape constructor
		const Entity& start,// -> spawning tower ref
		const Entity& end,// -> target tower ref
		const float& speed// -> define constant in wrapper by type
		);

	//destructor
	~Entity();

	//getters
	int getHP() const;
	sf::Vector2f getDirection() const; 
	teamNumber getTeamNumber() const; 

	//setters
	void setHP(const int& newHP);
	void setDirection(const sf::Vector2f& direction);
	void setTeamNumber(const teamNumber& newNumber);

	//public
	bool isDead() const;// -> true if 0 or less HP

	//when two shapes intersect have them subtract HP's from each other
	//and "kill" one when it hits 0 HP
	friend void attackUntilDead(Entity& lhs, Entity& rhs);
};

//non-member
sf::Vector2f computeDirection(const sf::Vector2f& start, const sf::Vector2f& end, const float& speed);
