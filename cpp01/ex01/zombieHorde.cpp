#include "Zombie.hpp"

Zombie*	zombieHorde(int n, std::string name)
{
	Zombie	*zombies;
	int		i;

	zombies = new Zombie[n];
	i = 0;
	while (i < n)
	{
		zombies[i].setName(name);
		zombies[i].setIndex(i + 1);
		i ++;
	}
	return (zombies);
}
