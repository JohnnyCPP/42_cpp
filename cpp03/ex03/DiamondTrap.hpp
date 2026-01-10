#ifndef DIAMOND_TRAP_HPP
# define DIAMOND_TRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class	DiamondTrap :	public ScavTrap, public FragTrap
{
private:

	std::string	name;

public:

	DiamondTrap();

	~DiamondTrap();

	DiamondTrap(const DiamondTrap& that);
	
	DiamondTrap&	operator=(const DiamondTrap& that);

	DiamondTrap(const std::string& name);

	void	attack(const std::string& target);
	void	whoAmI(void);

	std::string	getClapName(void) const;

	int	getDiamondHitPoints(void) const;

	int	getDiamondEnergyPoints(void) const;

	int	getDiamondAttackDamage(void) const;
};

#endif
