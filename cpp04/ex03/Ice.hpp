#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"
# include "print.hpp"
# include "constants.hpp"

class	Ice :	public AMateria
{
public:

	Ice();

	~Ice();

	Ice(Ice const& that);

	Ice&	operator=(Ice const& that);

	AMateria*	clone() const;

	void	use(ICharacter& target);
};

#endif
