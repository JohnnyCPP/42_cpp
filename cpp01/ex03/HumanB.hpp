#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP

# include "Weapon.hpp"
# include <iostream>

class	HumanB
{
private:

	Weapon*		weapon;
	std::string	name;

public:

	HumanB(const std::string& name);

	~HumanB();

	HumanB(const HumanB& that);

	HumanB&	operator=(const HumanB& that);

	void	attack() const;

	void	setWeapon(Weapon& weapon);
	Weapon	*getWeapon() const;

	void				setName(const std::string& name);
	const std::string&	getName() const;
};

#endif
