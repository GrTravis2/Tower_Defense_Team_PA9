#pragma once

#include <SFML/Graphics.hpp>

class Entity {
private:
	int mHealthPoints;
	sf::CircleShape mBody; //placeholder for whatever visual component we have for the entity
	//We also talked about adding some stats here, maybe should go into derived class for more custom stats?
	//I think the shape will also wrap position and movement functions with it! But we should verify the docs
	//Also not sure if we should make the shape public? it already has protected methods so should be ok??

	//helpers

public:
	
	//constructor
	Entity();
	Entity(
		const int& HP,
		const sf::CircleShape& body,
	);

	//destructor
	~Entity();

	//getters
	int getHP() const;
	//dont think we want one for shape? leaving empty for now

	//setters
	void setHP(const int& newHP);

	//public
	//move function? -> should be in SFML class


};