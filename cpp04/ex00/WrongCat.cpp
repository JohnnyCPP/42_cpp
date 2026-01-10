#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	type = "WrongCat";
	printd("Default constructor of WrongCat class...");
}

WrongCat::~WrongCat()
{
	printd("Destructor of WrongCat class...");
}

WrongCat::WrongCat(const WrongCat& that) :	WrongAnimal(that)
{
	printd("Copy constructor of WrongCat class...");
}

WrongCat&	WrongCat::operator=(const WrongCat& that)
{
	printd("Copy assignment operator of WrongCat class...");
	if (this != &that)
		WrongAnimal::operator=(that);
	return (*this);
}

void	WrongCat::makeSound() const
{
	std::cout << "Miau, miau, miau. But is wrong." << std::endl;
}
