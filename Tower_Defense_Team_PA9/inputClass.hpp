#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <string>
#include <iostream>
#include <vector>
using std::string;
using std::endl;
using std::cin;
using std::cout;

class inputClass
{
private:
	string currentInput;
	
public:

	// constructor
	inputClass();

	//public functions
	void updateInput(char typedLetter);
	void clearInput();
	void printInput();
	string getCurrentInput();
};



