#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP

# include <string>
# include <iostream>

class	ClapTrap
{
protected:

	std::string	name;
	int			hitPoints;
	int			energyPoints;
	int			attackDamage;

public:

	ClapTrap();

	virtual	~ClapTrap();

	ClapTrap(const ClapTrap& that);

	ClapTrap&	operator=(const ClapTrap& that);

	ClapTrap(const std::string& name);

	ClapTrap(const std::string& name, int hitPoints, int energyPoints, int attackDamage);

	void		setName(const std::string& name);
	std::string	getName() const;

	void	setHitPoints(const int hitPoints);
	int		getHitPoints() const;

	void	setEnergyPoints(const int energyPoints);
	int		getEnergyPoints() const;

	void	setAttackDamage(const int attackDamage);
	int		getAttackDamage() const;

	virtual void	attack(const std::string& target);

	void	takeDamage(unsigned int amount);

	void	beRepaired(unsigned int amount);
};

#endif
