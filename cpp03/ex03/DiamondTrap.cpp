#include "DiamondTrap.hpp"

::DiamondTrap::DiamondTrap() :	ClapTrap("_clap_name"), ScavTrap(), FragTrap()
{
	this->name = "DefaultDiamond";
	ClapTrap::name = "DefaultDiamond_clap_name";
	this->hitPoints = FragTrap::hitPoints;
	this->energyPoints = ScavTrap::energyPoints;
	this->attackDamage = FragTrap::attackDamage;
	std::cout	<< "DiamondTrap default constructor executed."
				<< std::endl;
}

::DiamondTrap::~DiamondTrap()
{
	std::cout	<< "DiamondTrap destructor executed."
				<< std::endl;
}

::DiamondTrap::DiamondTrap(const DiamondTrap& that) :	ClapTrap(that), ScavTrap(that), FragTrap(that)
{
	this->name = that.name;
	this->hitPoints = that.hitPoints;
	this->energyPoints = that.energyPoints;
	this->attackDamage = that.attackDamage;
	std::cout	<< "DiamondTrap copy constructor executed."
				<< std::endl;
}

DiamondTrap&	::DiamondTrap::operator=(const DiamondTrap& that)
{
	std::cout	<< "DiamondTrap copy assignment operator executed."
				<< std::endl;
	if (this != &that)
	{
		ClapTrap::operator=(that);
		this->name = that.name;
		this->hitPoints = that.hitPoints;
		this->energyPoints = that.energyPoints;
		this->attackDamage = that.attackDamage;
	}
	return (*this);
}

::DiamondTrap::DiamondTrap(const std::string& name) :	ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	this->name = name;
	ClapTrap::name = this->name + "_clap_name";
	this->hitPoints = FragTrap::hitPoints;
	this->energyPoints = ScavTrap::energyPoints;
	this->attackDamage = FragTrap::attackDamage;
	std::cout	<< "DiamondTrap name constructor executed."
				<< std::endl;
}

void	::DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void	::DiamondTrap::whoAmI(void)
{
	std::cout	<< "Initializing DiamondTrap whoAmI protocol..."
				<< std::endl;
	std::cout	<< "My DiamondTrap name is " << this->name
				<< std::endl;
	std::cout	<< "My ClapTrap name is " << ClapTrap::name 
				<< std::endl;
}

std::string	DiamondTrap::getClapName(void) const
{
	return (ClapTrap::name);
}

int	::DiamondTrap::getDiamondHitPoints(void) const
{
	return (this->hitPoints);
}

int	::DiamondTrap::getDiamondEnergyPoints(void) const
{
	return (this->energyPoints);
}

int	::DiamondTrap::getDiamondAttackDamage(void) const
{
	return (this->attackDamage);
}
