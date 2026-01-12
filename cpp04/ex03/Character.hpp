#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"
# include "Floor.hpp"
# include "print.hpp"
# include "constants.hpp"
# include <string>

class	Character :	public ICharacter
{
private:

	std::string	name;
	AMateria*	inventory[INVENTORY_SIZE];
	Floor*		floor;
	bool		ownsFloor;

	Character();

	void	initializeInventory();

	void	clearInventory();

	void	copyInventory(Character const& that);

public:

	~Character();

	Character(Character const& that);

	Character& operator=(Character const& that);

	Character(std::string const& name);

	Character(std::string const& name, Floor* floor);

	std::string const&	getName() const;

	void	equip(AMateria* m);

	void	unequip(int idx);

	void	use(int idx, ICharacter& target);

	void	printInventory() const;

	Floor*	getFloor() const;

	bool	pickUp(int floorIdx);

	bool	pickUp(std::string const& typeOnFloor);

	bool	hasEmptySlot() const;

	int	getEmptySlot() const;
};

#endif
