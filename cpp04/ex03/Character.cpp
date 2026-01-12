#include "Character.hpp"

Character::~Character()
{
	this->clearInventory();
	if (this->ownsFloor && this->floor != NULL)
		delete this->floor;
}

Character::Character(Character const& that) :	name(that.name), floor(NULL), ownsFloor(false)
{
	if (that.ownsFloor && that.floor != NULL)
	{
		this->floor = new Floor(*that.floor);
		this->ownsFloor = true;
	}
	else
	{
		this->floor = that.floor;
		this->ownsFloor = false;
	}
	this->initializeInventory();
	this->copyInventory(that);
}

Character&	Character::operator=(Character const& that)
{
	if (this != &that)
	{
		this->clearInventory();
		if (this->ownsFloor && this->floor != NULL)
			delete this->floor;
		this->name = that.name;
		if (that.ownsFloor && that.floor != NULL)
		{
			this->floor = new Floor(*that.floor);
			this->ownsFloor = true;
		}
		else
		{
			this->floor = that.floor;
			this->ownsFloor = false;
		}
		this->copyInventory(that);
	}
	return (*this);
}

Character::Character(std::string const& name) :	name(name), floor(new Floor()), ownsFloor(true)
{
	this->initializeInventory();
}

Character::Character(std::string const& name, Floor* floor) :	name(name), floor(floor), ownsFloor(false)
{
	this->initializeInventory();
}

void	Character::initializeInventory()
{
	int	i;

	i = 0;
	while (i < INVENTORY_SIZE)
		this->inventory[i ++] = NULL;
}

void	Character::clearInventory()
{
	int	i;

	i = 0;
	while (i < INVENTORY_SIZE)
	{
		if (this->inventory[i] != NULL)
		{
			delete this->inventory[i];
			this->inventory[i] = NULL;
		}
		i ++;
	}
}

void	Character::copyInventory(Character const& that)
{
	int	i;

	i = 0;
	while (i < INVENTORY_SIZE)
	{
		if (that.inventory[i] != NULL)
			this->inventory[i] = that.inventory[i]->clone();
		else
			this->inventory[i] = NULL;
		i ++;
	}
}

std::string const&	Character::getName() const
{
	return (this->name);
}

void	Character::equip(AMateria* m)
{
	int	i;

	if (m == NULL)
	{
		println("Cannot equip NULL materia.");
		return ;
	}
	i = 0;
	while (i < INVENTORY_SIZE)
	{
		if (this->inventory[i] == NULL)
		{
			this->inventory[i] = m;
			return ;
		}
		i ++;
	}
	println(this->name + "'s inventory is full. Cannot equip " + m->getType());
}

void	Character::unequip(int idx)
{
	if (idx < 0 || 4 <= idx)
	{
		println("Index #" + toString(idx) + " is not a valid slot.");
		return ;
	}
	if (this->inventory[idx] == NULL)
	{
		println("Index #" + toString(idx) + " is already empty.");
		return ;
	}
	if (this->floor != NULL)
		this->floor->dropMateria(this->inventory[idx]);
	this->inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || 4 <= idx)
	{
		println("Index #" + toString(idx) + " is not a valid slot.");
		return ;
	}
	if (this->inventory[idx] == NULL)
	{
		println("Index #" + toString(idx) + " is empty.");
		return ;
	}
	this->inventory[idx]->use(target);
}

void	Character::printInventory() const
{
	int	i;

	println(this->name + "'s inventory:");
	i = 0;
	while (i < INVENTORY_SIZE)
	{
		if (this->inventory[i] != NULL)
			println("#" + toString(i) + ": " + this->inventory[i]->getType());
		else
			println("#" + toString(i) + ": empty");
		i ++;
	}
}

Floor*	Character::getFloor() const
{
	return (this->floor);
}

bool	Character::pickUp(int floorIdx)
{
	AMateria*	materia;
	int			slot;

	if (!this->hasEmptySlot())
	{
		println(this->name + "'s inventory is full. Cannot pick up from the floor.");
		return (false);
	}
	materia = this->floor->pickUp(floorIdx);
	if (materia == NULL)
		return (false);
	slot = this->getEmptySlot();
	if (slot == NOT_FOUND)
		return (false);
	this->inventory[slot] = materia;
	println(this->name + " picked up " + materia->getType() + " from the floor and equipped it in slot " + toString(slot));
	return (true);
}

bool	Character::pickUp(std::string const& typeOnFloor)
{
	AMateria*	materia;
	int			slot;

	if (!this->hasEmptySlot())
	{
		println(this->name + "'s inventory is full. Cannot pick up from the floor.");
		return (false);
	}
	materia = this->floor->pickUp(typeOnFloor);
	if (materia == NULL)
		return (false);
	slot = this->getEmptySlot();
	if (slot == NOT_FOUND)
		return (false);
	this->inventory[slot] = materia;
	println(this->name + " picked up " + materia->getType() + " from the floor and equipped it in slot " + toString(slot));
	return (true);
}

bool	Character::hasEmptySlot() const
{
	int	i;

	i = 0;
	while (i < INVENTORY_SIZE)
	{
		if (this->inventory[i ++] == NULL)
			return (true);
	}
	return (false);
}

int	Character::getEmptySlot() const
{
	int	i;

	i = 0;
	while (i < INVENTORY_SIZE)
	{
		if (this->inventory[i] == NULL)
			return (i);
		i ++;
	}
	return (NOT_FOUND);
}
