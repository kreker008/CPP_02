#include "Fixed.hpp"

/*
 *  Constructor
 */
Fixed::Fixed() : fix_point_value(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(int const i)
{
	std::cout << "Int constructor called\n";
	this->setRawBits(i << bits);
}

Fixed::Fixed(float const f)
{
	std::cout << "Float constructor called\n";
	this->fix_point_value = ((int)roundf((f * (1 << bits))));
}

Fixed::Fixed(Fixed const& fix_o) :	fix_point_value(fix_o.fix_point_value)
{
	std::cout << "Copy constructor called\n";
}

/*
 *  Operator overlord
 */
Fixed& Fixed::operator=(Fixed const& fix_o)
{
	std::cout << "Assignation operator called\n";
	this->fix_point_value = fix_o.getRawBits();
	return (*this);
}


/*
 *  Func-member
 */
int Fixed::getRawBits() const
{
    return (this->fix_point_value);
}

void Fixed::setRawBits(int const raw)
{
	this->fix_point_value = raw;
}

float Fixed::toFloat() const
{
    return (this->fix_point_value / (float)(1 << bits));
}

int  Fixed::toInt() const
{
    return (this->fix_point_value >> bits);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called\n";
}

/*
 * No class func
 */
std::ostream& operator<<(std::ostream& os, Fixed const& fix)
{
    os << fix.toFloat();
    return (os);
}
