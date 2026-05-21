#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Usage: ./PmergeMe <numbers>" << std::endl;
		return (EXIT_FAILURE);
	}
	PmergeMe pmergeMe(argv);
	pmergeMe.sort();
	return (EXIT_SUCCESS);
}
