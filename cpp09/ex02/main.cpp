#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	PmergeMe	sorter;

	if (argc < 2)
	{
		std::cerr << "Error: need at least one positive integer" << std::endl;
		return (1);
	}
	sorter.sortAndDisplay(argc, argv);
	return (0);
}
