#include "Player.hpp"
#include "WordDisplay.hpp"

Player::Player(const teamNumber& team, const int& HP, const sf::Sprite& body) : Entity(HP, team, body)
{
	this->playerInput.clearInput();
	this->wordTimer = -1;
	this->wordTimerMax = -1;
	this->wordOptions[0] = "";
	this->wordOptions[1] = "";
	this->wordOptions[2] = "";
	this->wordOptions[3] = "";
	this->points = -1;
}

//destructor
Player::~Player() {
	//nothing for now...
}

std::string Player::getInput() 
{
	return playerInput.getCurrentInput();
}

int Player::getPoints() const
{
	return this->points;
}

void Player::setPoints(int newPoints)
{
	this->points = newPoints;
}

void Player::updateInput(char newChar)
{
	playerInput.updateInput(newChar);
}

void Player::clearInput()
{
	playerInput.clearInput();
}

int Player::processPlayerInput()
{
	string currentInput = playerInput.getCurrentInput();
	cout << "Current input: " << currentInput << endl;
	
	for (int i = 0; i < 3; i++)
	{
		
		if (currentInput == wordOptions[0])
		{
			playerInput.clearInput();
			return 1; 
		}
		else if (currentInput == wordOptions[1]) 
		{
			playerInput.clearInput();
			return 2;
		}
		else if (currentInput == wordOptions[2]) 
		{
			playerInput.clearInput();
			return 3;
		}
		else if (currentInput == wordOptions[3])
		{
			playerInput.clearInput();
			return 4;
		}
	}

	return -1;
}

void Player::setWord(int index, string newWord)
{
	wordOptions[index] = newWord;
}

std::string Player::getWord(int index) const {
    return wordOptions[index];
}

std::vector<bool> Player::validateInput()
{
	std::vector<bool> results(playerInput.getCurrentInput().length(), false);
	for (int i = 0; i < playerInput.getCurrentInput().length(); i++)
	{
		for (auto& word : wordOptions)
		{
			if (word.size() > i && word[i] == playerInput.getCurrentInput()[i])
			{
				results[i] = true;
			}
		}
	}
	return results; 
}

void Player::setWordDisplay(WordDisplay* wd) {
    wordDisplay = wd;
}

void Player::displayWords(sf::RenderWindow& window) {
    if (wordDisplay) {
        wordDisplay->displayPlayerWords(window, this);
    } else {
        for (int i = 0; i < 4; i++) {
            std::cout << "Word #" << i + 1 << ":" << wordOptions[i] << std::endl;
            std::cout << "\n";
        }
    }
}

