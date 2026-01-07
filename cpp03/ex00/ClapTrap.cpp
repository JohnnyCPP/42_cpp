#include "ClapTrap.hpp"

::ClapTrap::ClapTrap() :	name(""), hitPoints(10), energyPoints(10), attackDamage(0)
{}

::ClapTrap::~ClapTrap()
{}

ClapTrap(const ClapTrap& that);

ClapTrap&	operator=(const ClapTrap& that);

::ClapTrap::ClapTrap(const std::string& name) :	name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{}

void	attack(const std::string& target);

void	takeDamage(unsigned int amount);

void	beRepaired(unsigned int amount);
