#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class	Point
{
private:

	const Fixed	x;
	const Fixed	y;

public:

	Point();

	~Point();

	Point(const Point& that);

	Point&	operator=(const Point& that);

	Point(const float x, const float y);

	Fixed	getX() const;

	Fixed	getY() const;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif
