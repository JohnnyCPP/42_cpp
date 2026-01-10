#include "Cat.hpp"

Cat::Cat() :	brain(new Brain())
{
	type = "Cat";
	printd("Default constructor of Cat class...");
}

Cat::~Cat()
{
	printd("Destructor of Cat class...");
	delete this->brain;
}

Cat::Cat(const Cat& that) :	AAnimal(that), brain(new Brain(*that.brain))
{
	printd("Copy constructor of Cat class...");
}

Cat&	Cat::operator=(const Cat& that)
{
	printd("Copy assignment operator of Cat class...");
	if (this != &that)
	{
		AAnimal::operator=(that);
		delete brain;
		this->brain = new Brain(*that.brain);
	}
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "Miau, miau, miau." << std::endl;
}

Brain	*Cat::getBrain() const
{
	return (this->brain);
}

void	Cat::setIdea(int index, const std::string& idea)
{
	if (this->brain)
		this->brain->setIdea(index, idea);
}

std::string	Cat::getIdea(int index) const
{
	if (this->brain)
		return (this->brain->getIdea(index));
	return ("");
}
