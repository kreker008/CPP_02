#include "Fixed.hpp"

Fixed::Fixed() : fix_point_value(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(Fixed const& fix_o) :	fix_point_value(fix_o.fix_point_value)
{
	std::cout << "Copy constructor called\n";
	this->fix_point_value = fix_o.getRawBits();
}

Fixed& Fixed::operator=(Fixed const& fix_o)
{
	std::cout << "Assignation operator called\n";
	this->fix_point_value = fix_o.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

int Fixed::getRawBits() const
{
	bool minus = false;

	std::cout << "getRawBits member function called\n";
	if ((fix_point_value & 0b10000000) == 0b10000000)
		minus = true;
	if (minus)
		return ((fix_point_value<<1)>>5) * -1;
	else
		return ((fix_point_value<<1)>>5);
}

void Fixed::setRawBits(int const raw)
{
	if (raw < 0)
		fix_point_value |= 0b10000000;
	this->fix_point_value = ((raw<<5)>>1); ;
}