#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
public:
	/*
	 *  Constructor
	 */
	Point();
	Point(const Point&);
	Point(const float, const float);



	/*
	 *  Func-member
	 */
	float getX() const;
	float getY() const;

	~Point();
private:
	/*
 	 *  Operator overlord
	 */
	Point& operator=(const Point&);

	Fixed const x;
	Fixed const y;
};

#endif