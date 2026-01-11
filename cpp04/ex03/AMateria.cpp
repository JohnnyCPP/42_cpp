#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria() :	type("")
{}

AMateria::~AMateria()
{}

AMateria::AMateria(std::string const& type) :	type(type)
{}

AMateria::AMateria(AMateria const& that) :	type(that.type)
{}

AMateria&	AMateria::operator=(AMateria const& that)
{
	if (this != &that)
		this->type = that.type;
	return (*this);
}

std::string const&	AMateria::getType() const
{
	return (this->type);
}

void	AMateria::use(ICharacter& target)
{
	(void) target;
}
