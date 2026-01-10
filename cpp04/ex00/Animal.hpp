#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>
# include "printd.hpp"

class	Animal
{
protected:

	std::string	type;

public:

	Animal();

	virtual	~Animal();

	Animal(const Animal& that);

	Animal&	operator=(const Animal& that);

	std::string	getType() const;

	virtual	void	makeSound() const;
};

#endif
