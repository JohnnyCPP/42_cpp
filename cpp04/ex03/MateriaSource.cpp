#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	this->initializeTemplates();
}

MateriaSource::~MateriaSource()
{
	this->clearTemplates();
}

MateriaSource::MateriaSource(MateriaSource const& that)
{
	this->initializeTemplates();
	this->copyTemplates(that);
}

MateriaSource&	MateriaSource::operator=(MateriaSource const& that)
{
	if (this != &that)
	{
		this->clearTemplates();
		this->copyTemplates(that);
	}
	return (*this);
}

void	MateriaSource::initializeTemplates()
{
	int	i;

	i = 0;
	while (i < TEMPLATE_SIZE)
		this->templates[i ++] = NULL;
}

void	MateriaSource::clearTemplates()
{
	int	i;

	i = 0;
	while (i < TEMPLATE_SIZE)
	{
		if (this->templates[i] != NULL)
		{
			delete this->templates[i];
			this->templates[i] = NULL;
		}
		i ++;
	}
}

void	MateriaSource::copyTemplates(MateriaSource const& that)
{
	int	i;

	i = 0;
	while (i < TEMPLATE_SIZE)
	{
		if (that.templates[i] != NULL)
			this->templates[i] = that.templates[i]->clone();
		else
			this->templates[i] = NULL;
		i ++;
	}
}

void	MateriaSource::learnMateria(AMateria* m)
{
	int	i;

	if (m == NULL)
	{
		println("Cannot learn NULL materia.");
		return ;
	}
	i = 0;
	while (i < TEMPLATE_SIZE)
	{
		if (this->templates[i] == NULL)
		{
			this->templates[i] = m;
			return ;
		}
		i ++;
	}
	println("MateriaSource is full. Cannot learn " + m->getType());
}

AMateria*	MateriaSource::createMateria(std::string const& type)
{
	int	i;

	i = 0;
	while (i < TEMPLATE_SIZE)
	{
		if (this->templates[i] != NULL && this->templates[i]->getType() == type)
			return (this->templates[i]->clone());
		i ++;
	}
	println("Cannot create materia. Type not found.");
	return (0);
}

void	MateriaSource::printTemplates() const
{
	int	i;

	println("MateriaSource templates:");
	i = 0;
	while (i < TEMPLATE_SIZE)
	{
		if (this->templates[i] != NULL)
			println("#" + toString(i) + ": " + this->templates[i]->getType());
		else
			println("#" + toString(i) + ": empty");
		i ++;
	}
}
