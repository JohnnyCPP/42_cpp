#ifndef A_ANIMAL_HPP
# define A_ANIMAL_HPP

# include <iostream>
# include <string>
# include "printd.hpp"

class	AAnimal
{
protected:

	std::string	type;

public:

	AAnimal();

	virtual	~AAnimal();

	AAnimal(const AAnimal& that);

	AAnimal&	operator=(const AAnimal& that);

	std::string	getType() const;

	// this is a pure virtual function.
	// 1. has no implementation in the base class
	// 2. forces derived classes to provide their own implementation
	// 3. makes the class containing it abstract (cannot be instantiated)
	//
	// the "= 0" is called a "pure specifier", it means 
	// "this function has no implementation here"
	virtual	void	makeSound() const = 0;
};

#endif
