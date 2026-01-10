#include "Brain.hpp"

Brain::Brain()
{
	printd("Default constructor of Brain class...");
	int	i;

	i = 0;
	while (i < 100)
	{
		ideas[i] = "Idea #" + i;
		i ++;
	}
}

Brain::~Brain()
{
	printd("Destructor of Brain class...");
}

Brain::Brain(const Brain& that)
{
	printd("Copy constructor of Brain class...");
	int	i;

	i = 0;
	while (i < 100)
	{
		ideas[i] = that.ideas[i];
		i ++;
	}
}

Brain&	Brain::operator=(const Brain& that)
{
	int	i;

	printd("Copy assignment operator of Brain class...");
	if (this != &that)
	{
		i = 0;
		while (i < 100)
		{
			ideas[i] = that.ideas[i];
			i ++;
		}
	}
	return (*this);
}

void	Brain::setIdea(int index, const std::string& idea)
{
	if (0 <= index && index <= 99)
		this->ideas[index] = idea;
}

std::string	Brain::getIdea(int index) const
{
	if (0 <= index && index <= 99)
		return (this->ideas[index]);
	return "";
}
