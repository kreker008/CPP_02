#ifndef FIXED_HPP
#define FIXED_HPP

#include "iostream"

class Fixed
{
public:
	Fixed();
	Fixed(Fixed const& fix_o);
	Fixed& operator=(Fixed const& fix_o);
	~Fixed();
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
private:
	int						fix_point_value;
	const static int		constant = 8;
};



#endif
