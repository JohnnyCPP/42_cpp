#include "Fixed.hpp"
#include "Point.hpp"

// @return the Signed Area of a parallelogram constructed from 
//         two vectors (AB and AC), which happen to be 
//         two sides of the triangle
static Fixed	crossProduct(Point const a, Point const b, Point const c)
{
	Fixed	aX = a.getX(), aY = a.getY();
	Fixed	bX = b.getX(), bY = b.getY();
	Fixed	cX = c.getX(), cY = c.getY();
	Fixed	ABx = bX - aX;
	Fixed	ABy = bY - aY;
	Fixed	ACx = cX - aX;
	Fixed	ACy = cY - aY;

	return (ABx * ACy - ABy * ACx);
}

// is point P on same side of line AB as C?
// if point is on edge or vertex, cross product will be 0
// @return true if P is on same side of line AB as C
//         false if cross product of ABP is 0, or 
//               if P is on the opposite side of line AB as C
bool	isSameSideAsC(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	crossABC = ::crossProduct(a, b, c);
	Fixed	crossABP = ::crossProduct(a, b, point);
	bool	isSameSign = (crossABC * crossABP) >= 0;
	
	if (crossABP == 0)
		return (false);
	return (isSameSign);
}

// is point P on same side of line CA as B?
bool	isSameSideAsB(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	crossCAB = ::crossProduct(c, a, b);
	Fixed	crossCAP = ::crossProduct(c, a, point);
	bool	isSameSign = (crossCAB * crossCAP) >= 0;
	
	if (crossCAP == 0)
		return (false);
	return (isSameSign);
}

// is point P on same side of line BC as A?
bool	isSameSideAsA(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	crossBCA = ::crossProduct(b, c, a);
	Fixed	crossBCP = ::crossProduct(b, c, point);
	bool	isSameSign = (crossBCA * crossBCP) >= 0;
	
	if (crossBCP == 0)
		return (false);
	return (isSameSign);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	bool	sameAsC = ::isSameSideAsC(a, b, c, point);
	bool	sameAsB = ::isSameSideAsB(a, b, c, point);
	bool	sameAsA = ::isSameSideAsA(a, b, c, point);

	return (sameAsC && sameAsB && sameAsA);
}
