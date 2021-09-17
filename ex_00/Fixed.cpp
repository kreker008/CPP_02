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
	if (this == &fix_o)
		return (*this);
	this->fix_point_value = fix_o.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called\n";
    return (this->fix_point_value);
}

void Fixed::setRawBits(int const raw)
{
	this->fix_point_value = (this->fix_point_value = raw);
}