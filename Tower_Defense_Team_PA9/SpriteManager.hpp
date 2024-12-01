#pragma once

#include <SFML/Graphics.hpp>

#define GNOME_OFFSET_X 450
#define GNOME_OFFSET_Y 325
#define MUSHROOM_OFFSET_X 450
#define MUSHROOM_OFFSET_Y 400

class SpriteManager {
private:
    

    //helpers

public:

    sf::Texture* gnome;
    sf::Texture* mushroomTower;

    //constructor
    SpriteManager();//loads all textures from file

    //destructor
    ~SpriteManager();


    /* Maker funcs that return
    ptr to new Entity on the heap!
    Worry about position and stuff 
    in game logic. this class just
    handles all asset stuff and 
    memory allocation!  */

    //copy sprites
    sf::Sprite getGnome();
    sf::Sprite getBigGnome();
    sf::Sprite getMushroomTower();
};