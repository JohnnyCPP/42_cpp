#include "HumanB.hpp"

::HumanB::HumanB(const std::string& name) :	weapon(NULL), name(name)
{}

::HumanB::~HumanB()
{}

::HumanB::HumanB(const HumanB& that) :	weapon(that.weapon), name(that.name)
{}

HumanB&	::HumanB::operator=(const HumanB& that)
{
	if (this != &that)
	{
		this->weapon = that.weapon;
		this->name = that.name;
	}
	return (*this);
}

void	::HumanB::attack() const
{
	if (!this->weapon)
	{
		std::cout	<< this->name
					<< " lacks weapon."
					<< std::endl;
		return ;
	}
	std::cout	<< this->name
				<< " attacks with their "
				<< this->weapon->getType()
				<< std::endl;
}

void	::HumanB::setWeapon(Weapon& weapon)
{
	this->weapon = &weapon;
}

Weapon	*::HumanB::getWeapon() const
{
	return (this->weapon);
}

void				::HumanB::setName(const std::string& name)
{
	this->name = name;
}

const std::string&	::HumanB::getName() const
{
	return (this->name);
}
