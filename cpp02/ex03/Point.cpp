#include "Point.hpp"

::Point::Point() :	x(0), y(0)
{}

::Point::~Point()
{}

::Point::Point(const Point& that) :	x(that.x), y(that.y)
{}

// note: x and y are const qualified
//       but this operator is provided to complete OCF
Point&	::Point::operator=(const Point& that)
{
	(void) that;
	return (*this);
}

::Point::Point(const float x, const float y) :	x(x), y(y)
{}

Fixed	Point::getX() const
{
	return (this->x);
}

Fixed	Point::getY() const
{
	return (this->y);
}
