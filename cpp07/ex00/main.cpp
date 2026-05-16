#include <iostream>
#include "whatever.hpp"

int main(void)
{
	int a = 2;
	int b = 3;

	std::cout << "define a = 2, define b = 3" << std::endl << std::endl;

	::swap(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
	std::cout << "max(a, b) = " << ::max(a, b) << std::endl << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	std::cout << "define c = chaine1, define d = chaine2" << std::endl << std::endl;

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
	std::cout << "max(c, d) = " << ::max(c, d) << std::endl;
	return 0;
}
