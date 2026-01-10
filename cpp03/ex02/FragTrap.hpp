#ifndef FRAG_TRAP_HPP
# define FRAG_TRAP_HPP

# include "ClapTrap.hpp"

class	FragTrap :	public ClapTrap
{
public:

	FragTrap();

	~FragTrap();

	FragTrap(const FragTrap& that);

	FragTrap&	operator=(const FragTrap& that);

	FragTrap(const std::string& name);

	void	attack(const std::string& target);
	void	highFivesGuys(void);
};

#endif
