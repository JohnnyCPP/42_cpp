#ifndef A_MATERIA_HPP
# define A_MATERIA_HPP

# include "ICharacter.hpp"
# include <string>

class	AMateria
{
protected:

	std::string	type;

	AMateria();

public:

	virtual	~AMateria();

	AMateria(std::string const& type);

	AMateria(AMateria const& that);

	AMateria&	operator=(AMateria const& that);

	std::string const&	getType() const;

	virtual AMateria*	clone() const = 0;

	virtual void	use(ICharacter& target);
};

#endif
