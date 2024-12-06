#include "WordDisplay.hpp"
#include "Player.hpp" // Include Player header

WordDisplay::WordDisplay() {
    if (!font.loadFromFile("assets/arial.ttf")) {
        std::cerr << "Error loading font from assets/arial.ttf\n";
    } else {
        std::cout << "Font loaded successfully from assets/arial.ttf\n";
    }
    for (int i = 0; i < 4; ++i) {
        words[i].setFont(font);
        words[i].setCharacterSize(24);
        words[i].setFillColor(sf::Color::White);
        // Position will be set in draw method

        rewards[i].setFont(font);
        rewards[i].setCharacterSize(18);
        rewards[i].setFillColor(sf::Color::Yellow);
    }
}

void WordDisplay::setWords(const std::string wordArray[4]) {
    for (int i = 0; i < 4; ++i) {
        words[i].setString(wordArray[i]);
        std::cout << "Setting word " << i << ": " << wordArray[i] << std::endl; // Debug output
    }
}

void WordDisplay::setRewards(const std::string rewardArray[4]) {
    for (int i = 0; i < 4; ++i) {
        rewards[i].setString(rewardArray[i]);
        std::cout << "Setting reward " << i << ": " << rewardArray[i] << std::endl; // Debug output
    }
}

void WordDisplay::draw(sf::RenderWindow& window) {
    sf::RectangleShape rectangles[4];
    float rectWidth = window.getSize().x / 4.0f;
    float rectHeight = 50.0f;
    float padding = 5.0f; // Add padding between rectangles

    for (int i = 0; i < 4; ++i) {
        rectangles[i].setSize(sf::Vector2f(rectWidth - padding * 2, rectHeight - padding * 2));
        rectangles[i].setFillColor(sf::Color::Transparent);
        rectangles[i].setOutlineColor(i == 3 ? sf::Color::Red : sf::Color::White);
        rectangles[i].setOutlineThickness(2);
        rectangles[i].setPosition(i * rectWidth + padding, padding);

        // Set reward text
        sf::FloatRect rewardTextRect = rewards[i].getLocalBounds();
        rewards[i].setOrigin(rewardTextRect.left + rewardTextRect.width / 2.0f, rewardTextRect.top + rewardTextRect.height / 2.0f);
        rewards[i].setPosition(rectangles[i].getPosition().x + rectWidth / 2.0f - padding, rectangles[i].getPosition().y + rectHeight + padding);

        window.draw(rectangles[i]);
        window.draw(rewards[i]);

        // Center the text within the rectangle
        sf::FloatRect textRect = words[i].getLocalBounds();
        words[i].setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
        words[i].setPosition(rectangles[i].getPosition().x + rectWidth / 2.0f - padding, rectangles[i].getPosition().y + rectHeight / 2.0f - padding);

        window.draw(words[i]);
    }
}

void WordDisplay::displayPlayerWords(sf::RenderWindow& window, Player* player) {
    std::string playerWords[4];
    for (int i = 0; i < 4; ++i) {
        playerWords[i] = player->getWord(i);
    }
    setWords(playerWords);
    draw(window);
}