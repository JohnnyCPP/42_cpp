#include "easyfind.hpp"
#include <vector>
#include <iostream>

int	main()
{
	std::vector<int>			vec;
	std::vector<int>::iterator	it;

	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);
	try
	{
		it = easyfind(vec, 30);
		std::cout << "Found: " << *it << std::endl;
		it = easyfind(vec, 100);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	return (0);
}
