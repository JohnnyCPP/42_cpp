#include "Cat.hpp"

Cat::Cat()
{
	type = "Cat";
	printd("Default constructor of Cat class...");
}

Cat::~Cat()
{
	printd("Destructor of Cat class...");
}

Cat::Cat(const Cat& that) :	Animal(that)
{
	printd("Copy constructor of Cat class...");
}

Cat&	Cat::operator=(const Cat& that)
{
	printd("Copy assignment operator of Cat class...");
	if (this != &that)
		Animal::operator=(that);
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "Miau, miau, miau." << std::endl;
}
