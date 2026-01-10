#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "printd.hpp"
# include "Brain.hpp"
# include <iostream>

class	Cat :	public Animal
{
private:

	Brain	*brain;

public:

	Cat();

	~Cat();

	Cat(const Cat& that);

	Cat&	operator=(const Cat& that);

	void	makeSound() const;

	Brain	*getBrain() const;

	void		setIdea(int index, const std::string& idea);

	std::string	getIdea(int index) const;
};

#endif
