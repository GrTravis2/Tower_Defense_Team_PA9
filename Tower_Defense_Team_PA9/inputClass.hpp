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


/*

Expected features (I think):
- "Autocomplete"
	- allows for automatic processing of a word without having to hit enter 
- Backspace 
	- allows for a player to erase a previously typed letter if it doesn't match any of prompted words 
- Renders in the draw class
- No Target
	- Checks player typing progress against all words being prompted, player does not have to manually 
	select which word to type 
- Generates attack target randomly 
- Accounts for 4th cell for "wildcard" inputs

*/

class inputClass
{
private:
	
	
	string currentInput;
	

public:
	inputClass();

	void updateInput();
	void clearInput();
	void printInput();
	string getCurrentInput();

};



