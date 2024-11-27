

#include <SFML/Graphics.hpp>

class SpriteManager {
private:
    sf::Sprite* gnome;
    sf::Sprite* mushroomTower;

    //helpers

public:

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

    sf::Sprite getMushroomTower();
};