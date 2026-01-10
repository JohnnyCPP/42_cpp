#include <cstdlib>
#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

void	testBasicDiamondTrap()
{
	std::cout << "\n=== TEST 1: Basic DiamondTrap ===" << std::endl;

	DiamondTrap	diamond1;
	std::string	targetName;

	targetName = "TestTarget";
	diamond1.whoAmI();
	diamond1.attack(targetName);

	std::cout << "--- End of Basic Test ---" << std::endl;
}

void	testNamedDiamondTrap()
{
	std::cout << "\n=== TEST 2: Named DiamondTrap ===" << std::endl;

	DiamondTrap	diamond2("ShinyBot");
	std::string	enemyName;

	enemyName = "RustyBot";
	diamond2.whoAmI();
	diamond2.attack(enemyName);

	std::cout << "--- End of Named Test ---" << std::endl;
}

void	testCopyAndAssignment()
{
	std::cout << "\n=== TEST 3: Copy and Assignment ===" << std::endl;

	DiamondTrap	original("OriginalBot");
	DiamondTrap	copy(original);
	DiamondTrap	assigned;

	assigned = original;

	original.whoAmI();
	copy.whoAmI();
	assigned.whoAmI();

	std::cout << "--- End of Copy/Assignment Test ---" << std::endl;
}

void	testAttributes()
{
	std::cout << "\n=== TEST 4: Attribute Verification ===" << std::endl;

	DiamondTrap	diamond("AttributeBot");
	int			hitPoints;
	int			energyPoints;
	int			attackDamage;
	std::string	clapName;

	hitPoints = diamond.getDiamondHitPoints();
	energyPoints = diamond.getDiamondEnergyPoints();
	attackDamage = diamond.getDiamondAttackDamage();
	clapName = diamond.getClapName();

	std::cout << "DiamondTrap attributes:" << std::endl;
	std::cout << "  Hit Points: " << hitPoints << " (should be 100 from FragTrap)" << std::endl;
	std::cout << "  Energy Points: " << energyPoints << " (should be 50 from ScavTrap)" << std::endl;
	std::cout << "  Attack Damage: " << attackDamage << " (should be 30 from FragTrap)" << std::endl;
	std::cout << "  ClapTrap name: " << clapName << " (should be AttributeBot_clap_name)" << std::endl;

	std::cout << "--- End of Attributes Test ---" << std::endl;
}

void	testMultipleAttacks()
{
	std::cout << "\n=== TEST 5: Multiple Attacks ===" << std::endl;

	DiamondTrap	diamond("AttackBot");
	std::string	targetName;
	int			attackCount;

	targetName = "PracticeDummy";
	attackCount = 0;

	while (attackCount < 5)
	{
		diamond.attack(targetName);
		attackCount++;
	}

	std::cout << "--- End of Multiple Attacks Test ---" << std::endl;
}

void	testAllRobotTypes()
{
	std::cout << "\n=== TEST 6: All Robot Types ===" << std::endl;

	ClapTrap	clap("Clappy");
	ScavTrap	scav("Scavy");
	FragTrap	frag("Fraggy");
	DiamondTrap	diamond("Diamond");
	std::string	commonTarget;
	int			testIndex;

	commonTarget = "CommonEnemy";
	testIndex = 0;

	std::cout << "\nTesting attacks from all robot types:" << std::endl;

	while (testIndex < 4)
	{
		if (testIndex == 0)
			clap.attack(commonTarget);
		else if (testIndex == 1)
			scav.attack(commonTarget);
		else if (testIndex == 2)
			frag.attack(commonTarget);
		else
			diamond.attack(commonTarget);

		testIndex++;
	}

	std::cout << "\nTesting special abilities:" << std::endl;
	scav.guardGate();
	frag.highFivesGuys();
	diamond.whoAmI();

	std::cout << "--- End of All Types Test ---" << std::endl;
}

void	testConstructionChain()
{
	std::cout << "\n=== TEST 7: Construction Chain ===" << std::endl;

	std::cout << "Creating DiamondTrap (watch constructor order):" << std::endl;
	DiamondTrap*	diamondPtr;

	diamondPtr = new DiamondTrap("ChainBot");

	std::cout << "\nDestroying DiamondTrap (watch destructor order):" << std::endl;
	delete diamondPtr;
	diamondPtr = NULL;

	std::cout << "--- End of Construction Chain Test ---" << std::endl;
}

void	testEdgeCases()
{
	std::cout << "\n=== TEST 8: Edge Cases ===" << std::endl;

	DiamondTrap	diamond("EdgeBot");
	int			whoAmICount;

	whoAmICount = 0;

	while (whoAmICount < 3)
	{
		diamond.whoAmI();
		whoAmICount++;
	}

	diamond.attack("");
	diamond.attack("VeryLongTargetNameThatMightBreakThings");

	std::cout << "--- End of Edge Cases Test ---" << std::endl;
}

int	main()
{
	testBasicDiamondTrap();
	testNamedDiamondTrap();
	testCopyAndAssignment();
	testAttributes();
	testMultipleAttacks();
	testAllRobotTypes();
	testConstructionChain();
	testEdgeCases();
	return (EXIT_SUCCESS);
}
