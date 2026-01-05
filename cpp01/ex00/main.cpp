#include "Zombie.hpp"
#include <cstdlib>

int	main()
{
	const std::string	name = "steve";
	::Zombie			*zombie;

	std::cout
		<< "Defining zombie on the stack with randomChump()..."
		<< std::endl;
	::randomChump(name);
	std::cout
		<< "Defining zombie on the heap with newZombie()..."
		<< std::endl;
	zombie = new Zombie(name);
	zombie->announce();
	delete zombie;
	return (EXIT_SUCCESS);
}
