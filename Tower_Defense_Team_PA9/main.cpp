

#include <SFML/Graphics.hpp>


#include "inputClass.hpp"
#include "testCases.hpp"
#include "TowerDefenseGame.hpp"

int main(void) {

	std::srand(std::time(nullptr)); // seed for random number


	testCases t;
	t.runTests();
	TowerDefenseGame test;
	test.run();


	//TowerDefenseGame app;
	//app.run();

	//sf::CircleShape circle(5.f);
	//circle.move()


	
	return 0;
}