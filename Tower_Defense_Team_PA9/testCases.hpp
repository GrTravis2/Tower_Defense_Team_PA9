

#include "inputClass.hpp"
#include "Entity.hpp"
class testCases
{
public:
	void runTests();

private:

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
	//bool testRun(); //-> not needed calls main funcs
	bool testMapBonus();


};