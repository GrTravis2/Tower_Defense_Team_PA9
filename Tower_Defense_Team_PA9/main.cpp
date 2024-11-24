#include "inputClass.hpp"
#include "testCases.hpp"
#include <SFML/Graphics.hpp>

int main(void) {

	sf::RenderWindow window(sf::VideoMode(500, 500), "SFML Works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	testCases testContinuous;
	testContinuous.testContinuousKeyInput();
	
	while (window.isOpen()) 
	{
		
		sf::Event event;
		while(window.pollEvent(event)) {

			if (event.type == sf::Event::Closed) { window.close(); }
		}

		
	

		window.clear();
		window.draw(shape);
		window.display();
		
	}




	
	return 0;
}