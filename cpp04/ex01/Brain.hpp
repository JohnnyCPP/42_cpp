#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>
# include "printd.hpp"

class	Brain
{
private:

	std::string	ideas[100];

public:

	Brain();

	~Brain();

	Brain(const Brain& that);

	Brain&	operator=(const Brain& that);

	void		setIdea(int index, const std::string& idea);

	std::string	getIdea(int index) const;
};

#endif

