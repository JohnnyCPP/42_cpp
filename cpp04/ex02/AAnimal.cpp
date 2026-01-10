#include "AAnimal.hpp"

AAnimal::AAnimal() :	type("AAnimal")
{
	printd("Default constructor of AAnimal class...");
}

AAnimal::~AAnimal()
{
	printd("Destructor of AAnimal class...");
}

AAnimal::AAnimal(const AAnimal& that) :	type(that.type)
{
	printd("Copy constructor of AAnimal class...");
}

AAnimal&	AAnimal::operator=(const AAnimal& that)
{
	printd("Copy assignment operator of AAnimal class...");
	if (this != &that)
		this->type = that.type;
	return (*this);
}

std::string	AAnimal::getType() const
{
	return (this->type);
}
