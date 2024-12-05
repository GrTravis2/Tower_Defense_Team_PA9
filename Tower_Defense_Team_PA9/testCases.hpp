#include <ctime>

#include "inputClass.hpp"
#include "Entity.hpp"
#include "SpriteManager.hpp"
#include "WordDisplay.hpp"
class testCases
{
public:
	void runTests();

	//default constructor + destructor :(
	testCases();
	~testCases();

private:
	//data stuff
	SpriteManager* s;

	//inputClass tests
	bool testContinuousKeyInput();

	//entity tests
	//bool testComputeDirection();
	bool testGetandSetHP();
	bool testIsDead();
	bool testAttackUntilDead();

	// SpriteManager tests
	bool testLoadSprite();

	//TowerDefenseGame tests
	bool testGetPlayer();
	bool getHostPlayer();
	//bool testRun(); // -> not needed calls main funcs
	bool testMapBonus();

	void testProcessInput();
	bool testWordDisplay();
	
};