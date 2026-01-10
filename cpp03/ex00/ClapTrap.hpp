#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP

# include <string>
# include <iostream>

class	ClapTrap
{
private:

	std::string	name;
	int			hitPoints;
	int			energyPoints;
	int			attackDamage;

public:

	ClapTrap();

	~ClapTrap();

	ClapTrap(const ClapTrap& that);

	ClapTrap&	operator=(const ClapTrap& that);

	ClapTrap(const std::string& name);

	void	attack(const std::string& target);

	void	takeDamage(unsigned int amount);

	void	beRepaired(unsigned int amount);
};

#endif
