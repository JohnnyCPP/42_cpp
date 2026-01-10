#include <cstdlib>
#include <iostream>
#include "ClapTrap.hpp"

void	testBasicFunctionality()
{
	std::cout << "\n=== TEST 1: Basic Functionality ===\n";
	ClapTrap	clap("CL4P-TP");

	clap.attack("Bandit");
	clap.takeDamage(5);
	clap.beRepaired(3);
}

void	testEnergyManagement()
{
	std::cout << "\n=== TEST 2: Energy Management ===\n";
	ClapTrap	clap("ENERGY-TEST");
	int			i;

	i = 0;
	while (i ++ < 12)
		clap.attack("Target");
}

void	testHealthManagement()
{
	std::cout << "\n=== TEST 3: Health Management ===\n";
	ClapTrap	clap("HEALTH-TEST");

	clap.takeDamage(5);
	clap.beRepaired(2);
	clap.takeDamage(8);
	clap.beRepaired(1);
	clap.takeDamage(10);
	clap.attack("Target");
	clap.beRepaired(5);
}

void	testEdgeCases()
{
	std::cout << "\n=== TEST 4: Edge Cases ===\n";
	ClapTrap	clap2("BIG-HEAL");
	ClapTrap	clap3("OVERFLOW");

	clap2.takeDamage(5);
	clap2.beRepaired(2000);
	clap3.takeDamage(1000);
}

void	testCopyAndAssignment()
{
	std::cout << "\n=== TEST 5: Copy and Assignment ===\n";
	ClapTrap	original("ORIGINAL");

	original.takeDamage(3);
	ClapTrap	copy(original);
	copy.beRepaired(2);
	copy.attack("CopyTarget");
	ClapTrap	assigned("TEMP");
	assigned = original;
	assigned.attack("AssignedTarget");
}

void	testMultipleInstances()
{
	std::cout << "\n=== TEST 6: Multiple Instances ===\n";
	ClapTrap	clap1("CLAP-1");
	ClapTrap	clap2("CLAP-2");
	ClapTrap	clap3("CLAP-3");
	int			i;

	clap1.attack("Enemy");
	clap2.takeDamage(3);
	clap3.beRepaired(2);
	std::cout << "\n--- Testing independence ---\n";
	i = 0;
	while (i ++ < 5)
	{
		clap1.attack("Enemy1");
		clap2.attack("Enemy2");
	}
}

void	testAttackVariations()
{
	std::cout << "\n=== TEST 7: Attack Variations ===\n";
	ClapTrap	clap("ATTACKER");

	clap.attack("Bandit");
	clap.attack("Psycho");
	clap.attack("Skag");
	clap.attack("");
}

int	main()
{
	testBasicFunctionality();
	testEnergyManagement();
	testHealthManagement();
	testEdgeCases();
	testCopyAndAssignment();
	testMultipleInstances();
	testAttackVariations();
	return (EXIT_SUCCESS);
}
