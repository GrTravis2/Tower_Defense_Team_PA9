

#include <SFML/Graphics.hpp>


#include "inputClass.hpp"
#include "testCases.hpp"
#include "TowerDefenseGame.hpp"

int main(void) {

	testCases testContinuous;
	testContinuous.testContinuousKeyInput();

	TowerDefenseGame app;
	app.run();


	
	return 0;
}