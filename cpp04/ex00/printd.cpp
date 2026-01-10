#include <iostream>
#include <string>
#include "printd.hpp"

void	printd(const std::string& msg)
{
	std::cout << "DEBUG: " + msg << std::endl;
}
