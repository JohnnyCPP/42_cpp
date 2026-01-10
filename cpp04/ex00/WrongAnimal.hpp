#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

# include <iostream>
# include <string>
# include "printd.hpp"

class	WrongAnimal
{
protected:

	std::string	type;

public:

	WrongAnimal();

	~WrongAnimal();

	WrongAnimal(const WrongAnimal& that);

	WrongAnimal&	operator=(const WrongAnimal& that);

	std::string	getType() const;

	void	makeSound() const;
};

#endif
