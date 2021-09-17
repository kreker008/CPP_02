#include "Fixed.hpp"
#include "Point.hpp"
#include "iostream"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main( void )
{
	Point p1(1, 3); // Nop
	Point p2(0, 1); // Yep
	Point p3(4.6,-1.02); // Nop
	bool b = \
	bsp(Point(4.6,-1.02), Point(-6.3, 4.38), Point(-12.14, -2.58), p1);

	if (b)
		std::cout << "The point is in a triangle." << std::cout;
	else
		std::cout << "The point is not in a triangle." << std::cout;
}