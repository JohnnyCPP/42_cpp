#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int	main()
{
	int					amount = 10000;
	int					i;
	std::vector<int>	vector;
	Span				span = Span(5);
	Span				bigSpan(amount);

	std::cout << "testing span of size 5..." << std::endl << std::endl;
	span.addNumber(6);
	span.addNumber(3);
	span.addNumber(17);
	span.addNumber(9);
	span.addNumber(11);
	std::cout << "Shortest: " << span.shortestSpan() << std::endl;
	std::cout << "Longest: " << span.longestSpan() << std::endl << std::endl;
	std::cout << "testing span of size " << amount << "..." << std::endl << std::endl;
	std::srand(std::time(0));
	i = 0;
	while (i < amount)
	{
		vector.push_back(std::rand() % 100000);
		i ++;
	}
	bigSpan.addNumber(vector.begin(), vector.end());
	std::cout << amount << " numbers - Shortest: " << bigSpan.shortestSpan() << std::endl;
	std::cout << amount << " numbers - Longest: " << bigSpan.longestSpan() << std::endl;
	return (0);
}
