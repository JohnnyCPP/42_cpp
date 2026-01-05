#include "Zombie.hpp"
#include <cstdlib>

int	main()
{
	const std::string	name = "steve";
	const int			n = 20;
	Zombie				*zombies;
	int					i;

	zombies = zombieHorde(n, name);
	i = 0;
	std::cout << "Announcing horde..." << std::endl;
	while (i < n)
	{
		std::cout << "Announcing zombie #" << i + 1 << " ";
		zombies[i].announce();
		i ++;
	}
	delete[] zombies;
	return (EXIT_SUCCESS);
}
