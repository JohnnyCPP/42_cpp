#include "HumanA.hpp"

::HumanA::HumanA(Weapon& weapon) :	weapon(weapon), name("")
{}

::HumanA::HumanA(const std::string& name, Weapon& weapon) :	weapon(weapon), name(name)
{}

::HumanA::~HumanA()
{}

::HumanA::HumanA(const HumanA& that) :	weapon(that.weapon), name(that.name)
{}

HumanA&	::HumanA::operator=(const HumanA& that)
{
	if (this != &that)
	{
		this->weapon = that.weapon;
		this->name = that.name;
	}
	return (*this);
}

void	::HumanA::attack() const
{
	std::cout	<< this->name
				<< " attacks with their "
				<< this->weapon.getType()
				<< std::endl;
}

void			::HumanA::setWeapon(const Weapon& weapon)
{
	this->weapon = weapon;
}

const Weapon&	::HumanA::getWeapon() const
{
	return (this->weapon);
}

void				::HumanA::setName(const std::string& name)
{
	this->name = name;
}

const std::string&	::HumanA::getName() const
{
	return (this->name);
}
