#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "printd.hpp"
# include <iostream>

class	Dog :	public Animal
{
public:

	Dog();

	~Dog();

	Dog(const Dog& that);

	Dog&	operator=(const Dog& that);

	void	makeSound() const;
};

#endif
