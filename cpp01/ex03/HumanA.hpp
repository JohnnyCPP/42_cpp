#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP

# include "Weapon.hpp"
# include <iostream>

class	HumanA
{
private:

	Weapon&		weapon;
	std::string	name;

	HumanA();

public:

	HumanA(Weapon& weapon);

	HumanA(const std::string& name, Weapon& weapon);

	~HumanA();

	HumanA(const HumanA& that);

	HumanA&	operator=(const HumanA& that);

	void	attack() const;

	void			setWeapon(const Weapon& weapon);
	const Weapon&	getWeapon() const;

	void				setName(const std::string& name);
	const std::string&	getName() const;
};

#endif
