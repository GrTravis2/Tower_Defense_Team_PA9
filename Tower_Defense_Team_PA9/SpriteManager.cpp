
#include "SpriteManager.hpp"

//constructor
SpriteManager::SpriteManager() {//loads all textures from file

    //init gnome data
    this->gnome = new sf::Texture();// -> get heap mem
    this->gnome->loadFromFile("assets/gnome2.png");// -> set image

    //init mushroomTower
    this->mushroomTower = new sf::Texture();// -> get heap mem
    this->mushroomTower->loadFromFile("assets/mushroomHouse2.png");// -> set image
}

//destructor
SpriteManager::~SpriteManager() {
    delete this->gnome;
    delete this->mushroomTower;
}

//copy sprites from data member reference texture

sf::Sprite SpriteManager::getGnome() {
    sf::Sprite result((*this->gnome));
    result.setOrigin(GNOME_OFFSET_X, GNOME_OFFSET_Y);
    result.setScale(0.05, 0.05);

    return result;
}

sf::Sprite SpriteManager::getBigGnome() {
    sf::Sprite result((*this->gnome));
    result.setOrigin(GNOME_OFFSET_X, GNOME_OFFSET_Y);
    result.setScale(0.15, 0.15);

    return result;
}

sf::Sprite SpriteManager::getMushroomTower() {
    sf::Sprite result((*this->mushroomTower));
    result.setOrigin(MUSHROOM_OFFSET_X, MUSHROOM_OFFSET_Y);
    result.setScale(0.20, 0.20);

    return result;
}