#include "Dog.hpp"

Dog::Dog()
{
	type = "Dog";
	printd("Default constructor of Dog class...");
}

Dog::~Dog()
{
	printd("Destructor of Dog class...");
}

Dog::Dog(const Dog& that) :	Animal(that)
{
	printd("Copy constructor of Dog class...");
}

Dog&	Dog::operator=(const Dog& that)
{
	printd("Copy assignment operator of Dog class...");
	if (this != &that)
		Animal::operator=(that);
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "Woof, woof, woof." << std::endl;
}
