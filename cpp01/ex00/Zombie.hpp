#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>

class Zombie
{
private:

	std::string	name;

public:

	static const std::string	ANNOUNCEMENT;

	Zombie(const std::string name);

	Zombie();

	~Zombie();

	Zombie(const Zombie& that);

	Zombie&	operator=(const Zombie& that);

	void	setName(const std::string& name);

	std::string&	getName();

	void	announce(void) const;
};

Zombie*	newZombie(std::string name);

void	randomChump(std::string name);

#endif
