#include "Animal.hpp"

Animal::Animal() :	type("Animal")
{
	printd("Default constructor of Animal class...");
}

Animal::~Animal()
{
	printd("Destructor of Animal class...");
}

Animal::Animal(const Animal& that) :	type(that.type)
{
	printd("Copy constructor of Animal class...");
}

Animal&	Animal::operator=(const Animal& that)
{
	printd("Copy assignment operator of Animal class...");
	if (this != &that)
		this->type = that.type;
	return (*this);
}

std::string	Animal::getType() const
{
	return (this->type);
}

void	Animal::makeSound() const
{
	std::cout << "Animal makes a generic sound." << std::endl;
}
