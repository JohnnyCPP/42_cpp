#include "FragTrap.hpp"

::FragTrap::FragTrap() :	ClapTrap("", 100, 100, 30)
{
	std::cout	<< "FragTrap default constructor executed."
				<< std::endl;
}

::FragTrap::~FragTrap()
{
	std::cout	<< "FragTrap destructor executed."
				<< std::endl;
}

::FragTrap::FragTrap(const FragTrap& that) :	ClapTrap(that.getName(), that.getHitPoints(), that.getEnergyPoints(), that.getAttackDamage())
{
	std::cout	<< "FragTrap copy constructor executed."
				<< std::endl;
}

::FragTrap::FragTrap(const std::string& name) :	ClapTrap(name, 100, 100, 30)
{
	std::cout	<< "FragTrap name constructor executed for " << name
				<< std::endl;
}

FragTrap&	::FragTrap::operator=(const FragTrap& that)
{
	std::cout	<< "FragTrap copy assignment operator executed."
				<< std::endl;
	if (this != &that)
		ClapTrap::operator=(that);
	return (*this);
}

void	::FragTrap::attack(const std::string& target)
{
	if (this->getHitPoints() <= 0)
	{
		std::cout	<< "FragTrap " << this->getName()
					<< " cannot attack. Not enough hit points."
					<< std::endl;
		return ;
	}
	if (this->getEnergyPoints() <= 0)
	{
		std::cout	<< "FragTrap " << this->getName()
					<< " cannot attack. Not enough energy points."
					<< std::endl;
		return ;
	}
	this->setEnergyPoints(this->getEnergyPoints() - 1);
	std::cout	<< "FragTrap " << this->getName()
				<< " attacks " << target
				<< ", causing " << this->getAttackDamage()
				<< " points of damage!"
				<< std::endl;
}

void	::FragTrap::highFivesGuys(void)
{
	std::cout	<< "FragTrap " << this->getName()
				<< " requests a positive high-fives request on the standard output." << std::endl
				<< "[accept/decline]"
				<< std::endl;
}
