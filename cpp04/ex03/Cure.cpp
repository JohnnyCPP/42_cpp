#include "Cure.hpp"

Cure::Cure() :	AMateria(MATERIA_CURE)
{}

Cure::~Cure()
{}

Cure::Cure(Cure const& that) :	AMateria(that)
{}

Cure&	Cure::operator=(Cure const& that)
{
	if (this != &that)
		AMateria::operator=(that);
	return (*this);
}

AMateria*	Cure::clone() const
{
	return (new Cure(*this));
}

void	Cure::use(ICharacter& target)
{
	println("* heals " + target.getName() + "'s wounds *");
}
