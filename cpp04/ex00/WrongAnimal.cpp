#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() :	type("WrongAnimal")
{
	printd("Default constructor of WrongAnimal class...");
}

WrongAnimal::~WrongAnimal()
{
	printd("Destructor of WrongAnimal class...");
}

WrongAnimal::WrongAnimal(const WrongAnimal& that) :	type(that.type)
{
	printd("Copy constructor of WrongAnimal class...");
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& that)
{
	printd("Copy assignment operator of WrongAnimal class...");
	if (this != &that)
		this->type = that.type;
	return (*this);
}

std::string	WrongAnimal::getType() const
{
	return (this->type);
}

void	WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal makes a generic sound." << std::endl;
}
