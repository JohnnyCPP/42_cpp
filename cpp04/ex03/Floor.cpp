#include "Floor.hpp"

Floor::Floor() :	count(0)
{
	this->initializeFloor();
}

Floor::~Floor()
{
	this->clearFloor();
}

Floor::Floor(Floor const& that) :	count(that.count)
{
	int	i;

	this->initializeFloor();
	i = 0;
	while (i < that.count)
	{
		if (that.droppedMaterias[i] != NULL)
			this->droppedMaterias[i] = that.droppedMaterias[i]->clone();
		else
			this->droppedMaterias[i] = NULL;
		i ++;
	}
	while (i < FLOOR_SIZE)
		this->droppedMaterias[i ++] = NULL;
}

Floor&	Floor::operator=(Floor const& that)
{
	int	i;

	if (this != &that)
	{
		this->clearFloor();
		this->count = that.count;
		i = 0;
		while (i < that.count)
		{
			if (that.droppedMaterias[i] != NULL)
				this->droppedMaterias[i] = that.droppedMaterias[i]->clone();
			else
				this->droppedMaterias[i] = NULL;
			i ++;
		}
		while (i < FLOOR_SIZE)
			this->droppedMaterias[i ++] = NULL;
	}
	return (*this);
}

int	Floor::findByType(std::string const& type) const
{
	int	i;

	i = 0;
	while (i < this->count)
	{
		if (this->droppedMaterias[i] != NULL && this->droppedMaterias[i]->getType() == type)
			return (i);
		i ++;
	}
	return (NOT_FOUND);
}

void	Floor::dropMateria(AMateria* m)
{
	int	i;

	if (m == NULL)
	{
		println("Cannot drop NULL materia.");
		return ;
	}
	if (this->count >= FLOOR_SIZE)
	{
		delete this->droppedMaterias[0];
		i = 0;
		while (i < this->count - 1)
		{
			this->droppedMaterias[i] = this->droppedMaterias[i + 1];
			i ++;
		}
		this->count --;
	}
	this->droppedMaterias[this->count] = m;
	this->count ++;
}

AMateria*	Floor::pickUp(int idx)
{
	AMateria*	materia;
	int			i;

	if (idx < 0 || this->count <= idx)
	{
		println("Index #" + toString(idx) + " is not a valid floor slot.");
		return (NULL);
	}
	if (this->droppedMaterias[idx] == NULL)
	{
		println("Index #" + toString(idx) + " is empty on the floor.");
		return (NULL);
	}
	materia = this->droppedMaterias[idx];
	i = idx;
	while (i < this->count - 1)
	{
		this->droppedMaterias[i] = this->droppedMaterias[i + 1];
		i ++;
	}
	this->droppedMaterias[this->count - 1] = NULL;
	this->count --;
	println("Picked up " + materia->getType() + " from the floor at index #" + toString(idx));
	return (materia);
}

AMateria*	Floor::pickUp(std::string const& type)
{
	int	idx;

	idx = this->findByType(type);
	if (idx == NOT_FOUND)
	{
		println("Materia " + type + " not found on the floor.");
		return (NULL);
	}
	return (this->pickUp(idx));
}

void	Floor::initializeFloor()
{
	int	i;

	i = 0;
	while (i < FLOOR_SIZE)
		this->droppedMaterias[i ++] = NULL;
}

void	Floor::clearFloor()
{
	int	i;

	i = 0;
	while (i < this->count)
	{
		if (this->droppedMaterias[i] != NULL)
		{
			delete this->droppedMaterias[i];
			this->droppedMaterias[i] = NULL;
		}
		i ++;
	}
	this->count = 0;
}

void	Floor::printFloor() const
{
	int	i;

	if (this->count == 0)
	{
		println("The floor is empty.");
		return ;
	}
	println("There are " + toString(this->count) + " materias on the floor:");
	i = 0;
	while (i < this->count)
	{
		if (this->droppedMaterias[i] != NULL)
			println("#" + toString(i) + ": " + this->droppedMaterias[i]->getType());
		i ++;
	}
}

int	Floor::getCount() const
{
	return (this->count);
}

bool	Floor::isEmpty() const
{
	return (this->count == 0);
}
