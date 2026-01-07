#include "Point.hpp"
#include <iostream>
#include <cstdlib>

void	test(Point a, Point b, Point c, Point p, bool expected, std::string desc)
{
	bool	result = bsp(a, b, c, p);

	std::cout	<< desc << ": "
				<< (result == expected ? "OK" : "KO")
				<< " (expected " << expected
				<< ", got " << result
				<< ")"
				<< std::endl;
}

void	testBasicTriangle()
{
	Point	a(0.0f, 0.0f), b(10.0f, 0.0f), c(0.0f, 10.0f);

	std::cout	<< "==== basic triangle test ===="
				<< std::endl;
	::test(a, b, c, Point(3.0f, 3.0f), true, "Point inside triangle");
	::test(a, b, c, Point(10.0f, 10.0f), false, "Point outside triangle");
	::test(a, b, c, Point(5.0f, 0.0f), false, "Point on edge AB");
	::test(a, b, c, Point(0.0f, 5.0f), false, "Point on edge AC");
	::test(a, b, c, Point(5.0f, 5.0f), false, "Point outside triangle");
	::test(a, b, c, Point(0.0f, 0.0f), false, "Point on vertex A");
	::test(a, b, c, Point(0.1f, 0.1f), true, "Point near vertex (inside)");
}

void	testDifferentOrientation()
{
	Point	a(0.0f, 0.0f), b(0.0f, 10.0f), c(10.0f, 0.0f);

	std::cout	<< "==== different triangle orientation test ===="
				<< std::endl;

	::test(a, b, c, Point(3.0f, 3.0f), true, "Different vertex order");
}

void	testSmallTriangle()
{
	Point	a(0.5f, 0.5f), b(0.5f, 1.5f), c(1.5f, 0.5f);

	std::cout	<< "==== small triangle test ===="
				<< std::endl;
	::test(a, b, c, Point(0.75f, 0.75f), true, "Point inside small triangle");
	::test(a, b, c, Point(0.5f, 0.5f), false, "Point in vertex of small triangle");
}

int	main(void)
{
	testBasicTriangle();
	testDifferentOrientation();
	testSmallTriangle();
	return (EXIT_SUCCESS);
}
