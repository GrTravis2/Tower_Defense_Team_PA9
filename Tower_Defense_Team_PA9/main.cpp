

#include <SFML/Graphics.hpp>


#include "inputClass.hpp"
#include "testCases.hpp"
#include "TowerDefenseGame.hpp"

int main(void) {

	//testCases t;
	//t.runTests();

	std::srand(std::time(nullptr)); // seed for random number


	/*testCases t;
	t.runTests();*/

	TowerDefenseGame app;
	//app.run();
	app.assign3Words();

	return 0;
}