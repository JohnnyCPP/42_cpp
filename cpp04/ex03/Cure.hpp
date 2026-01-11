#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"
# include "print.hpp"

class	Cure :	public AMateria
{
public:

	Cure();

	~Cure();

	Cure(Cure const& that);

	Cure&	operator=(Cure const& that);

	AMateria*	clone() const;

	void	use(ICharacter& target);
};

#endif
