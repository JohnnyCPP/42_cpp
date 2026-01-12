#ifndef MATERIA_SOURCE_HPP
# define MATERIA_SOURCE_HPP

# include "IMateriaSource.hpp"
# include "AMateria.hpp"
# include "Ice.hpp"
# include "Cure.hpp"
# include "print.hpp"
# include "constants.hpp"

class	MateriaSource :	public IMateriaSource
{
private:

	AMateria*	templates[TEMPLATE_SIZE];

	void	initializeTemplates();

	void	clearTemplates();

	void	copyTemplates(MateriaSource const& that);

public:

	MateriaSource();

	virtual	~MateriaSource();

	MateriaSource(MateriaSource const& that);

	MateriaSource&	operator=(MateriaSource const& that);

	void	learnMateria(AMateria* m);
	AMateria*	createMateria(std::string const& type);

	void	printTemplates() const;
};

#endif
