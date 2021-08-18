#include "Fixed.hpp"

/*
 *  Constructor
 */
Fixed::Fixed() : fix_point_value(0)
{
}

Fixed::Fixed(int const i)
{
	this->setRawBits(i << bits);
}

Fixed::Fixed(float const f)
{
	this->fix_point_value = ((int) roundf((f * (1 << bits))));
}

Fixed::Fixed(Fixed const& fix_o) : fix_point_value(fix_o.fix_point_value)
{
}

/*
 *  Operator overlord
 */
Fixed& Fixed::operator=(Fixed const& fix_o)
{
	this->fix_point_value = fix_o.getRawBits();
	return (*this);
}

bool Fixed::operator==(Fixed const& fix_o) const
{
	if (this->fix_point_value == fix_o.fix_point_value)
		return (true);
	else
		return (false);
}

bool Fixed::operator<(Fixed const& fix_o) const
{
	if (this->fix_point_value < fix_o.fix_point_value)
		return (true);
	else
		return (false);
}

bool Fixed::operator>(Fixed const& fix_o) const
{
	if (this->fix_point_value == fix_o.fix_point_value)
		return (true);
	else
		return (false);
}

bool Fixed::operator>=(Fixed const& fix_o) const
{
	if ((*this) > fix_o && (*this) == fix_o)
		return (true);
	else
		return (false);
}

bool Fixed::operator<=(Fixed const& fix_o) const
{
	if ((*this) < fix_o && (*this) == fix_o)
		return (true);
	else
		return (false);
}

bool Fixed::operator!=(Fixed const& fix_o) const
{
	return (!((*this) == fix_o));
}

float Fixed::operator*(Fixed const& fix_o) const
{
	return ((float) ((double) fix_o.toFloat() * this->toFloat()));
}

float Fixed::operator/(Fixed const& fix_o) const
{
	return ((float) ((double) fix_o.toFloat() / this->toFloat()));
}

float Fixed::operator+(Fixed const& fix_o) const
{
	Fixed temp;

	temp.setRawBits(this->getRawBits() + fix_o.getRawBits());
	return (temp.toFloat());
}

float Fixed::operator-(Fixed const& fix_o) const
{
	Fixed temp;

	temp.setRawBits(this->getRawBits() - fix_o.getRawBits());
	return (temp.toFloat());
}

float Fixed::operator++(int)
{
	Fixed temp = *this;

	this->fix_point_value += 1;
	return (temp.toFloat());
}

float Fixed::operator++()
{
	this->fix_point_value += 1;
	return (toFloat());
}

float Fixed::operator--(int)
{
	Fixed temp = *this;

	this->fix_point_value -= 1;
	return (temp.toFloat());
}

float Fixed::operator--()
{
	this->fix_point_value -= 1;
	return (toFloat());
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
	return (this->fix_point_value / (float) (1 << bits));
}

int Fixed::toInt() const
{
	return (this->fix_point_value >> bits);
}

Fixed const& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

Fixed const& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

Fixed::~Fixed()
{
}

/*
 * No class func
 */

std::ostream& operator<<(std::ostream& os, Fixed const& fix)
{
	os << fix.toFloat();
	return (os);
}