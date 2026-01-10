#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP

# include "ClapTrap.hpp"

class	ScavTrap :	virtual public ClapTrap
{
public:

	ScavTrap();
	
	~ScavTrap();

	ScavTrap(const ScavTrap& that);

	ScavTrap&	operator=(const ScavTrap& that);

	ScavTrap(const std::string& name);

	void	attack(const std::string& target);
	void	guardGate();
};

#endif
