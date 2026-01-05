#include "Harl.hpp"
#include <cstdlib>

int	main(int argc, char **argv)
{
	Harl		harl;
	std::string	level;
	int			value;

	if (argc != 2)
	{
		std::cout	<< "Usage: ./harlFilter <level>"
					<< std::endl;
		std::cout	<< "Levels: DEBUG, INFO, WARNING, ERROR"
					<< std::endl;
		return (EXIT_FAILURE);
	}
	level = argv[1];
	value = -1;
	if (level == "DEBUG")
		value = 0;
	else if (level == "INFO")
		value = 1;
	else if (level == "WARNING")
		value = 2;
	else if (level == "ERROR")
		value = 3;
	switch(value)
	{
		case 0:
			harl.complain("DEBUG");
			std::cout	<< std::endl;
			// fall through
		case 1:
			harl.complain("INFO");
			std::cout	<< std::endl;
			// fall through
		case 2:
			harl.complain("WARNING");
			std::cout	<< std::endl;
			// fall through
		case 3:
			harl.complain("ERROR");
			break;
		default:
			std::cout	<< "[ Probably complaining about insignificant problems ]"
						<< std::endl;
			break;
	}
	return (EXIT_SUCCESS);
}
