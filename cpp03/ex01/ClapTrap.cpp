#include "ClapTrap.hpp"

::ClapTrap::ClapTrap() :	name(""), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout	<< "ClapTrap default constructor executed." 
				<< std::endl;
}

::ClapTrap::~ClapTrap()
{
	std::cout	<< "ClapTrap destructor executed." 
				<< std::endl;
}

::ClapTrap::ClapTrap(const ClapTrap& that) :	name(that.name), hitPoints(that.hitPoints), energyPoints(that.energyPoints), attackDamage(that.attackDamage)
{
	std::cout	<< "ClapTrap copy constructor executed." 
				<< std::endl;
}

ClapTrap&	::ClapTrap::operator=(const ClapTrap& that)
{
	std::cout	<< "ClapTrap copy assignment operator executed." 
				<< std::endl;
	if (this != &that)
	{
		this->name = that.name;
		this->hitPoints = that.hitPoints;
		this->energyPoints = that.energyPoints;
		this->attackDamage = that.attackDamage;
	}
	return (*this);
}

::ClapTrap::ClapTrap(const std::string& name) :	name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout	<< "ClapTrap name constructor executed." 
				<< std::endl;
}

::ClapTrap::ClapTrap(const std::string& name, int hitPoints, int energyPoints, int attackDamage) :	name(name), hitPoints(hitPoints), energyPoints(energyPoints), attackDamage(attackDamage)
{
	std::cout	<< "ClapTrap(std::string, int, int, int) executed."
				<< std::endl;
}

void			::ClapTrap::setName(const std::string& name)
{
	this->name = name;
}

std::string		ClapTrap::getName() const
{
	return (this->name);
}

void	::ClapTrap::setHitPoints(const int hitPoints)
{
	this->hitPoints = hitPoints;
}

int		::ClapTrap::getHitPoints() const
{
	return (this->hitPoints);
}

void	::ClapTrap::setEnergyPoints(const int energyPoints)
{
	this->energyPoints = energyPoints;
}

int		::ClapTrap::getEnergyPoints() const
{
	return (this->energyPoints);
}

void	::ClapTrap::setAttackDamage(const int attackDamage)
{
	this->attackDamage = attackDamage;
}

int		::ClapTrap::getAttackDamage() const
{
	return (this->attackDamage);
}

void	::ClapTrap::attack(const std::string& target)
{
	if (this->hitPoints <= 0)
	{
		std::cout	<< "ClapTrap " << this->name
					<< " cannot attack. Not enough hit points."
					<< std::endl;
		return ;
	}
	if (this->energyPoints <= 0)
	{
		std::cout	<< "ClapTrap " << this->name
					<< " cannot attack. Not enough energy points."
					<< std::endl;
		return ;
	}
	this->energyPoints --;
	std::cout	<< "ClapTrap " << this->name
				<< " attacks " << target
				<< ", causing " << this->attackDamage
				<< " points of damage!"
				<< std::endl;
}

void	::ClapTrap::takeDamage(unsigned int amount)
{
	int	before = this->hitPoints;

	if (this->hitPoints <= 0)
	{
		std::cout	<< "ClapTrap " << this->name
					<< " cannot take more damage. Out of hit points."
					<< std::endl;
		return ;
	}
	if (this->hitPoints - (signed) amount <= 0)
		this->hitPoints = 0;
	else
		this->hitPoints -= amount;
	std::cout	<< "ClapTrap " << this->name
				<< " took " << amount 
				<< " of damage and has " << this->hitPoints
				<< " hit points now. It had " << before
				<< " hit points."
				<< std::endl;
}

void	::ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hitPoints <= 0)
	{
		std::cout	<< "ClapTrap " << this->name
					<< " cannot be repaired. Not enough hit points."
					<< std::endl;
		return ;
	}
	if (this->energyPoints <= 0)
	{
		std::cout	<< "ClapTrap " << this->name
					<< " cannot be repaired. Not enough energy points."
					<< std::endl;
		return ;
	}
	this->energyPoints --;
	if (this->hitPoints + amount >= 1000)
	{
		this->hitPoints = 1000;
		std::cout	<< "ClapTrap " << this->name
					<< " hit points reached the maximum (1000)."
					<< std::endl;
	}
	else
	{
		this->hitPoints += amount;
		std::cout	<< "ClapTrap " << this->name
					<< " hit points restored by " << amount
					<< " for a total of " << this->hitPoints
					<< " hit points."
					<< std::endl;
	}
}
