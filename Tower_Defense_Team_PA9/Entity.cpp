
#include "Entity.hpp"

//helpers
	Entity* makeGnome() {
        Entity* pNew = new Entity(1, sf::CircleShape(5.f));

        return pNew;
    }