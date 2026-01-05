#include "Zombie.hpp"

const std::string	Zombie::ANNOUNCEMENT = "BraiiiiiiinnnzzzZ...";

::Zombie::Zombie() :	name("")
{}

::Zombie::Zombie(const std::string name) :	name(name)
{}

::Zombie::~Zombie()
{
	std::cout	<< this->name 
				<< ": "
				<< "has been destroyed"
				<< std::endl;
}

::Zombie::Zombie(const Zombie& that) :	name(that.name)
{}

Zombie&	::Zombie::operator=(const Zombie& that)
{
	if (this != &that)
	{
		this->name = that.name;
	}
	return (*this);
}

void	::Zombie::setName(const std::string& name)
{
	this->name = name;
}

std::string&	::Zombie::getName()
{
	return (this->name);
}

void	::Zombie::announce(void) const
{
	std::cout	<< this->name 
				<< ": "
				<< ::Zombie::ANNOUNCEMENT
				<< std::endl;
}
