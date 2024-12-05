#include <SFML/Graphics.hpp>
#include "inputClass.hpp"
#include "testCases.hpp"
#include "TowerDefenseGame.hpp"

int main(void) {
    std::srand(std::time(NULL)); // seed for random number

 	TowerDefenseGame app;

    //testCases t;
    //t.runTests();

   
    app.run();

    return 0;
}