#include "Fixed.hpp"

Fixed::Fixed() : fix_point_value(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(int const i)
{
	int temp;

	std::cout << "Int constructor called\n";
	temp = (i<<16)>>1;
	if (i < 0)
		temp |= 0b10000000000000000000000000000000;
	this->setRawBits(temp);
}

Fixed::Fixed(float const f)
{
	std::cout << "Float constructor called\n";
	this->setRawBits((int)f);
	this->fix_point_value f - roundf(f);
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
	std::cout << "getRawBits member function called\n";

}

void Fixed::setRawBits(int const raw)
{
	this->fix_point_value = raw;
}