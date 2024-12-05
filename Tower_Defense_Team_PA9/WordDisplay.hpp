#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

class Player; // Forward declaration

#include "Player.hpp"

class WordDisplay {
private:
    sf::Font font;
    sf::Text words[4]; // Update to handle four words
    sf::Text rewards[4]; // Array to store reward texts

public:
    WordDisplay();
    void setWords(const std::string wordArray[4]); // Update to handle four words
    void setRewards(const std::string rewardArray[4]); // Method to set rewards
    void draw(sf::RenderWindow& window);
    void displayPlayerWords(sf::RenderWindow& window, Player* player); //display player's words
};

