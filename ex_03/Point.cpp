#include "Point.hpp"


/*
 *  Constructor
 */
Point::Point() :  x(0), y(0)
{}

Point::Point(const Point& p) : x(p.x), y(p.y)
{}

Point::Point(const float f1, const float f2) : x(f1), y(f2)
{}

/*
 *  Operator overlord
 */
Point& Point::operator=(const Point&)
{ return (*this);}

/*
 *  Func-member
 */

float Point::getX() const
{
	return (float)(x.toFloat());
}

float Point::getY() const
{
	return (float)(y.toFloat());
}

Point::~Point()
{}