#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "Usage: ./PmergeMe <numbers>" << std::endl;
		return (EXIT_FAILURE);
	}
	try
	{
		PmergeMe	pmergeMe(argv);

		pmergeMe.sort();
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
