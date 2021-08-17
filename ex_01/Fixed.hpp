#ifndef FIXED_HPP
#define FIXED_HPP

#include "iostream"
#include "cmath"

class Fixed
{
public:
    /*
     * Constructor
     */
	Fixed();
	Fixed(Fixed const& fix_o);
	Fixed(int const i);
	Fixed(float const f);
	/*
	 *  Operator overload
	 */
	Fixed& operator=(Fixed const& fix_o);

    /*
     *  Func-member
     */
    int		getRawBits(void) const;
    void	setRawBits(int const raw);
    float   toFloat( void ) const;
    int     toInt( void ) const;

    ~Fixed();
private:
    /*
     *  Variable
     */
	int						fix_point_value;
	const static int		bits = 8;
};

std::ostream& operator<<(std::ostream&, Fixed const&);

#endif
