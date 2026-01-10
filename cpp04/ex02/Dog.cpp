#include "Dog.hpp"

Dog::Dog() :	brain(new Brain())
{
	type = "Dog";
	printd("Default constructor of Dog class...");
}

Dog::~Dog()
{
	printd("Destructor of Dog class...");
	delete this->brain;
}

Dog::Dog(const Dog& that) :	AAnimal(that), brain(new Brain(*that.brain))
{
	printd("Copy constructor of Dog class...");
}

Dog&	Dog::operator=(const Dog& that)
{
	printd("Copy assignment operator of Dog class...");
	if (this != &that)
	{
		AAnimal::operator=(that);
		delete brain;
		this->brain = new Brain(*that.brain);
	}
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "Woof, woof, woof." << std::endl;
}

Brain	*Dog::getBrain() const
{
	return (this->brain);
}

void	Dog::setIdea(int index, const std::string& idea)
{
	if (this->brain)
		this->brain->setIdea(index, idea);
}

std::string	Dog::getIdea(int index) const
{
	if (this->brain)
		return (this->brain->getIdea(index));
	return ("");
}
