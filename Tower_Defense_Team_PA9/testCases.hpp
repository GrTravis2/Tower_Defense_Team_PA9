

#include "inputClass.hpp"
#include "Entity.hpp"
#include "SpriteManager.hpp"
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
	bool testComputeDirection();
	bool testGetandSetHP();
	bool testIsDead();
	bool testAttackUntilDead();

	//TowerDefenseGame tests
	bool testGetPlayer();
	bool getHostPlayer();
	//bool testRun(); // -> not needed calls main funcs
	bool testMapBonus();
	
};