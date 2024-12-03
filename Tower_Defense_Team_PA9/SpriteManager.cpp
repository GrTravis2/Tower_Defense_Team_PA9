#include <iostream>
#include "SpriteManager.hpp"

//constructor
SpriteManager::SpriteManager() {//loads all textures from file

    this->grass = new sf::Texture();
    this->grass->loadFromFile("assets/grass.png");

    //init gnome data
    this->gnome = new sf::Texture();// -> get heap mem
    this->gnome->loadFromFile("assets/gnome2.png");// -> set image
    if (this->gnome->loadFromFile("assets/gnome2.png"))
    {
        std::cout << "This loaded properly!" << std::endl;
    }

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

sf::Sprite SpriteManager::getGrass()
{
    sf::Sprite result((*this->grass));
    result.setOrigin(0,0);
    result.setScale(0.5, 0.5);

    return result;
}

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