#pragma once

#include <math.h>
#include <SFML/Graphics.hpp>


//const sf::Vector2f ZERO_VEC(0,0);


class Entity {
private:
	int mHealthPoints; //create helper function that computes changes in HP.
	sf::Vector2f mDirection;// -> controls direction and speed, set once at init!
	

	//helpers
	

public:

	//pubic to access shape methods
	sf::Sprite mBody; //placeholder for whatever visual component we have for the entity
	//We also talked about adding some stats here, maybe should go into derived class for more custom stats?
	//I think the shape will also wrap position and movement functions with it! But we should verify the docs
	//Also not sure if we should make the shape public? it already has protected methods so should be ok??
	
	//constructor
	Entity(// -> for static entities (players)
		const int& HP,
		const sf::Sprite& body
	);
	Entity(// -> for entities that move along a vector!
		const int& HP, // -> obj HP, when it hits 0 will get deleted!
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

	//setters
	void setHP(const int& newHP);
	void setDirection(const sf::Vector2f& direction);

	//public
	//move function? -> should be in SFML class

	bool isDead() const;// -> true if 0 or less HP

	//when two shapes intersect have them subtract HP's from each other
	//and "kill" one when it hits 0 HP
	friend void attackUntilDead(Entity& lhs, Entity& rhs);


};

//non-member

//derives a vector that points between starting and ending entities
//with magnitude speed!
sf::Vector2f computeDirection(const Entity& start, const Entity& end, const float& speed);
