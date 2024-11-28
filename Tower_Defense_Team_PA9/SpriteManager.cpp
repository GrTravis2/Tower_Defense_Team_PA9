
#include "SpriteManager.hpp"

//constructor
SpriteManager::SpriteManager() {//loads all textures from file
    sf::Texture texture;

    //init gnome data
    texture.loadFromFile("assets/gnome.png");
    this->gnome = new sf::Sprite(texture);// -> set image
    this->gnome->setScale(sf::Vector2f(1.0, 1.0));// -> scale size

    //note that both gnomes share artwork, just different size. No texture reload!
    this->bigGnome = new sf::Sprite(texture);// -> set image
    this->bigGnome->setScale(sf::Vector2f(10.0, 10.0));// -> scale size

    //init mushroomTower
    texture.loadFromFile("assets/mushroomHouse.png");
    this->mushroomTower = new sf::Sprite(texture);// -> set image
    this->gnome->setScale(sf::Vector2f(20.0, 20.0));// -> scale size
}

//destructor
SpriteManager::~SpriteManager() {
    delete this->gnome;
    delete this->bigGnome;
    delete this->mushroomTower;
}

//copy sprites from data member reference sprite

sf::Sprite SpriteManager::getGnome() {
    sf::Sprite result(*this->gnome);

    return result;
}

sf::Sprite SpriteManager::getBigGnome() {
    sf::Sprite result(*this->bigGnome);

    return result;
}

sf::Sprite SpriteManager::getMushroomTower() {
    sf::Sprite result(*this->mushroomTower);

    return result;
}