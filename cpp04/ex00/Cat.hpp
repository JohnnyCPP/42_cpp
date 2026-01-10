#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "printd.hpp"
# include <iostream>

class	Cat :	public Animal
{
public:

	Cat();

	~Cat();

	Cat(const Cat& that);

	Cat&	operator=(const Cat& that);

	void	makeSound() const;
};

#endif
