#ifndef FLOOR_HPP
# define FLOOR_HPP

# include "AMateria.hpp"
# include "print.hpp"
# include "constants.hpp"

class	Floor
{
private:

	AMateria*	droppedMaterias[FLOOR_SIZE];
	int			count;

	void	initializeFloor();

	int	findByType(std::string const& type) const;

public:

	Floor();

	~Floor();

	Floor(Floor const& that);

	Floor&	operator=(Floor const& that);

	void	dropMateria(AMateria* m);

	AMateria*	pickUp(int idx);

	AMateria*	pickUp(std::string const& type);

	void	clearFloor();

	void	printFloor() const;

	int	getCount() const;

	bool	isEmpty() const;

	int	getEmptySlot() const;
};

#endif
