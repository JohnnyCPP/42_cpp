#include "Zombie.hpp"

const std::string	Zombie::ANNOUNCEMENT = "BraiiiiiiinnnzzzZ...";

::Zombie::Zombie() :	name(""), index(0)
{}

::Zombie::Zombie(const std::string name) :	name(name)
{}

::Zombie::~Zombie()
{
	std::cout	<< this->name 
				<< " #" << this->index
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

void	::Zombie::setIndex(const int index)
{
	this->index = index;
}

int&	::Zombie::getIndex()
{
	return (this->index);
}

void	::Zombie::announce(void) const
{
	std::cout	<< this->name 
				<< ": "
				<< ::Zombie::ANNOUNCEMENT
				<< std::endl;
}
