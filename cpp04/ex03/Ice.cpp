#include "Ice.hpp"

Ice::Ice() :	AMateria(MATERIA_ICE)
{}

Ice::~Ice()
{}

Ice::Ice(Ice const& that) :	AMateria(that)
{}

Ice&	Ice::operator=(Ice const& that)
{
	if (this != &that)
		AMateria::operator=(that);
	return (*this);
}

AMateria*	Ice::clone() const
{
	return (new Ice(*this));
}

void	Ice::use(ICharacter& target)
{
	println("* shoots an ice bolt at " + target.getName() + " *");
}
