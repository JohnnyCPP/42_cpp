#include <cstdlib>
#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

void	testBasicClapTrap()
{
	std::cout << "\n=== TEST 1: Basic ClapTrap ===" << std::endl;

	ClapTrap	robot1;
	std::string	targetName;

	targetName = "TargetDummy";
	robot1.setName("BasicBot");
	robot1.attack(targetName);
	robot1.takeDamage(5);
	robot1.beRepaired(3);

	std::cout << "--- End of Basic ClapTrap Test ---" << std::endl;
}

void	testClapTrapEnergy()
{
	std::cout << "\n=== TEST 2: ClapTrap Energy Depletion ===" << std::endl;

	ClapTrap	robot2;
	std::string	enemyName;
	int			counter;

	robot2.setName("EnergyBot");
	enemyName = "BadGuy";
	counter = 0;

	while (counter < 12)
	{
		robot2.attack(enemyName);
		counter++;
	}

	std::cout << "--- End of Energy Test ---" << std::endl;
}

void	testClapTrapHealth()
{
	std::cout << "\n=== TEST 3: ClapTrap Health Depletion ===" << std::endl;

	ClapTrap	robot3;
	int			damageCounter;

	robot3.setName("TankBot");
	damageCounter = 0;

	while (damageCounter < 5)
	{
		robot3.takeDamage(3);
		damageCounter++;
	}

	robot3.beRepaired(2);
	robot3.attack("SomeTarget");

	std::cout << "--- End of Health Test ---" << std::endl;
}

void	testScavTrapConstruction()
{
	std::cout << "\n=== TEST 4: ScavTrap Construction Chain ===" << std::endl;

	std::cout << "Creating ScavTrap..." << std::endl;
	ScavTrap	scav1("Guardian");

	std::cout << "\nCreating another ScavTrap via copy..." << std::endl;
	ScavTrap	scav2(scav1);

	std::cout << "\nCreating third ScavTrap via assignment..." << std::endl;
	ScavTrap	scav3;
	scav3 = scav2;

	std::cout << "--- End of Construction Test ---" << std::endl;
}

void	testScavTrapSpecial()
{
	std::cout << "\n=== TEST 5: ScavTrap Special Ability ===" << std::endl;

	ScavTrap	scav;
	std::string	target;
	int			guardCount;

	scav.setName("GateKeeper");
	target = "Intruder";
	guardCount = 0;

	scav.attack(target);
	scav.guardGate();

	while (guardCount < 3)
	{
		scav.guardGate();
		guardCount++;
	}

	std::cout << "--- End of Special Ability Test ---" << std::endl;
}

void	testScavTrapAttack()
{
	std::cout << "\n=== TEST 6: ScavTrap Attack Override ===" << std::endl;

	ScavTrap	scavBot;
	ClapTrap	clapBot;
	std::string	enemy;
	int			attackCount;

	scavBot.setName("Scavenger");
	clapBot.setName("Clapper");
	enemy = "CommonEnemy";
	attackCount = 0;

	std::cout << "\nScavTrap attacking:" << std::endl;
	while (attackCount < 3)
	{
		scavBot.attack(enemy);
		attackCount++;
	}

	std::cout << "\nClapTrap attacking:" << std::endl;
	attackCount = 0;
	while (attackCount < 2)
	{
		clapBot.attack(enemy);
		attackCount++;
	}

	std::cout << "--- End of Attack Override Test ---" << std::endl;
}

void	testResourceManagement()
{
	std::cout << "\n=== TEST 7: Resource Management ===" << std::endl;

	ScavTrap*	scavPtr;
	int			testCounter;

	scavPtr = new ScavTrap("ResourceTest");
	testCounter = 0;

	while (testCounter < 4)
	{
		scavPtr->attack("Dummy");
		scavPtr->takeDamage(25);
		testCounter++;
	}

	scavPtr->beRepaired(10);
	scavPtr->guardGate();

	delete scavPtr;
	scavPtr = NULL;

	std::cout << "--- End of Resource Management Test ---" << std::endl;
}

void	testMixedObjects()
{
	std::cout << "\n=== TEST 8: Mixed Object Array ===" << std::endl;

	ClapTrap*	robots[4];
	int			index;
	std::string	name;

	index = 0;
	while (index < 4)
	{
		if (index % 2 == 0)
		{
			name = "ClapBot_";
			name += static_cast<char>('A' + index);
			robots[index] = new ClapTrap(name);
		}
		else
		{
			name = "ScavBot_";
			name += static_cast<char>('A' + index);
			robots[index] = new ScavTrap(name);
		}
		index++;
	}

	index = 0;
	while (index < 4)
	{
		robots[index]->attack("Target");
		index++;
	}

	index = 0;
	while (index < 4)
	{
		delete robots[index];
		robots[index] = NULL;
		index++;
	}

	std::cout << "--- End of Mixed Objects Test ---" << std::endl;
}

void	testEdgeCases()
{
	std::cout << "\n=== TEST 9: Edge Cases ===" << std::endl;

	ScavTrap	edgeBot;
	int			zeroCounter;
	unsigned	largeAmount;

	edgeBot.setName("EdgeCase");
	zeroCounter = 0;
	largeAmount = 1000;

	while (zeroCounter < 3)
	{
		edgeBot.takeDamage(0);
		edgeBot.beRepaired(0);
		zeroCounter++;
	}

	edgeBot.takeDamage(largeAmount);
	edgeBot.beRepaired(largeAmount);
	edgeBot.attack("Ghost");

	std::cout << "--- End of Edge Cases Test ---" << std::endl;
}

int	main()
{
	testBasicClapTrap();
	testClapTrapEnergy();
	testClapTrapHealth();
	testScavTrapConstruction();
	testScavTrapSpecial();
	testScavTrapAttack();
	testResourceManagement();
	testMixedObjects();
	testEdgeCases();
	return (EXIT_SUCCESS);
}
