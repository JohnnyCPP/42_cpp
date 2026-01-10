#include "ScavTrap.hpp"

::ScavTrap::ScavTrap() :	ClapTrap("", 100, 50, 20)
{
	std::cout	<< "ScavTrap default constructor executed."
				<< std::endl;
}
	
::ScavTrap::~ScavTrap()
{
	std::cout	<< "ScavTrap destructor executed."
				<< std::endl;
}

::ScavTrap::ScavTrap(const ScavTrap& that) :	ClapTrap(that.getName(), that.getHitPoints(), that.getEnergyPoints(), that.getAttackDamage())
{
	std::cout	<< "ScavTrap copy constructor executed."
				<< std::endl;
}

ScavTrap&	::ScavTrap::operator=(const ScavTrap& that)
{
	std::cout	<< "ScavTrap copy assignment operator executed."
				<< std::endl;
	if (this != &that)
	{
		::ClapTrap::operator=(that);
	}
	return (*this);
}

::ScavTrap::ScavTrap(const std::string& name) :	ClapTrap(name, 100, 50, 20)
{
	std::cout	<< "ScavTrap name constructor executed."
				<< std::endl;
}

void	::ScavTrap::attack(const std::string& target)
{
	if (this->getHitPoints() <= 0)
	{
		std::cout	<< "ScavTrap " << this->getName()
					<< " cannot attack. Not enough hit points."
					<< std::endl;
		return ;
	}
	if (this->getEnergyPoints() <= 0)
	{
		std::cout	<< "ScavTrap " << this->getName()
					<< " cannot attack. Not enough energy points."
					<< std::endl;
		return ;
	}
	this->setEnergyPoints(this->getEnergyPoints() - 1);
	std::cout	<< "ScavTrap " << this->getName()
				<< " attacks " << target
				<< ", causing " << this->getAttackDamage()
				<< " points of damage!"
				<< std::endl;
}

void	::ScavTrap::guardGate()
{
	std::cout	<< "ScavTrap " << this->getName() 
				<< " is now in Gate keeper mode."
				<< std::endl;
}
