#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "printd.hpp"
# include "Brain.hpp"
# include <iostream>

class	Dog :	public AAnimal
{
private:

	Brain	*brain;

public:

	Dog();

	~Dog();

	Dog(const Dog& that);

	Dog&	operator=(const Dog& that);

	void	makeSound() const;

	Brain	*getBrain() const;

	void		setIdea(int index, const std::string& idea);

	std::string	getIdea(int index) const;
};

#endif
