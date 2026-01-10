#ifndef FRAG_TRAP_HPP
# define FRAG_TRAP_HPP

# include "ClapTrap.hpp"

// virtual inheritance is the key concept to solve the diamond problem
//
// it ensures that only one instance of a base class exists 
// in an inheritance hierarchy, even when that base class 
// is inherited through multiple paths
class	FragTrap :	virtual public ClapTrap
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
