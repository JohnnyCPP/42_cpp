#include "Weapon.hpp"

::Weapon::Weapon() :	type("")
{}

::Weapon::Weapon(const std::string& type) :	type(type)
{}

::Weapon::~Weapon()
{}

::Weapon::Weapon(const Weapon& that)
{
	this->type = that.type;
}

Weapon&	::Weapon::operator=(const Weapon& that)
{
	if (this != &that)
	{
		this->type = that.type;
	}
	return (*this);
}

void	::Weapon::setType(const std::string& type)
{
	this->type = type;
}

const std::string&	::Weapon::getType() const
{
	return (this->type);
}
