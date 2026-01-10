#ifndef WRONG_CAT_HPP
# define WRONG_CAT_HPP

# include "WrongAnimal.hpp"
# include "printd.hpp"
# include <iostream>

class	WrongCat :	public WrongAnimal
{
public:

	WrongCat();

	~WrongCat();

	WrongCat(const WrongCat& that);

	WrongCat&	operator=(const WrongCat& that);

	void	makeSound() const;
};

#endif
