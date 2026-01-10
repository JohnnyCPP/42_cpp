#include <cstdlib>
#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

void	testFragTrapConstruction()
{
	std::cout << "\n=== TEST 1: FragTrap Construction Chain ===" << std::endl;

	std::cout << "Creating FragTrap..." << std::endl;
	FragTrap	frag1("HighFiver");

	std::cout << "\nCreating another via copy..." << std::endl;
	FragTrap	frag2(frag1);

	std::cout << "\nCreating third via assignment..." << std::endl;
	FragTrap	frag3;
	frag3 = frag2;

	std::cout << "--- End of Construction Test ---" << std::endl;
}

void	testFragTrapSpecial()
{
	std::cout << "\n=== TEST 2: FragTrap Special Ability ===" << std::endl;

	FragTrap	fragBot;
	int			highFiveCount;

	fragBot.setName("HappyBot");
	highFiveCount = 0;

	while (highFiveCount < 3)
	{
		fragBot.highFivesGuys();
		highFiveCount++;
	}

	std::cout << "--- End of Special Ability Test ---" << std::endl;
}

void	testFragTrapStats()
{
	std::cout << "\n=== TEST 3: FragTrap Attack Stats ===" << std::endl;

	FragTrap	fragBot;
	ScavTrap	scavBot;
	std::string	targetName;
	int			attackCount;

	fragBot.setName("FragAttacker");
	scavBot.setName("ScavAttacker");
	targetName = "PracticeDummy";
	attackCount = 0;

	std::cout << "\nFragTrap attacks (30 damage):" << std::endl;
	while (attackCount < 2)
	{
		fragBot.attack(targetName);
		attackCount++;
	}

	std::cout << "\nScavTrap attacks (20 damage):" << std::endl;
	attackCount = 0;
	while (attackCount < 2)
	{
		scavBot.attack(targetName);
		attackCount++;
	}

	std::cout << "--- End of Stats Test ---" << std::endl;
}

void	testAllThreeRobots()
{
	std::cout << "\n=== TEST 4: All Three Robot Types ===" << std::endl;

	ClapTrap*	robots[3];
	std::string	names[3];
	int			index;

	names[0] = "Clappy";
	names[1] = "Scavy";
	names[2] = "Frag";

	index = 0;
	while (index < 3)
	{
		if (index == 0)
			robots[index] = new ClapTrap(names[index]);
		else if (index == 1)
			robots[index] = new ScavTrap(names[index]);
		else
			robots[index] = new FragTrap(names[index]);
		index++;
	}

	index = 0;
	while (index < 3)
	{
		robots[index]->attack("Target");
		index++;
	}

	index = 0;
	while (index < 3)
	{
		delete robots[index];
		robots[index] = NULL;
		index++;
	}

	std::cout << "--- End of All Three Test ---" << std::endl;
}

void	testFragTrapEnergy()
{
	std::cout << "\n=== TEST 5: FragTrap Energy (100) ===" << std::endl;

	FragTrap	fragBot;
	std::string	enemyName;
	int			attackCounter;

	fragBot.setName("EnergyTester");
	enemyName = "EnemyBot";
	attackCounter = 0;

	while (attackCounter < 102)
	{
		fragBot.attack(enemyName);
		attackCounter++;
	}

	std::cout << "--- End of Energy Test ---" << std::endl;
}

int	main()
{
	testFragTrapConstruction();
	testFragTrapSpecial();
	testFragTrapStats();
	testAllThreeRobots();
	testFragTrapEnergy();
	return (EXIT_SUCCESS);
}
