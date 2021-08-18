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
	Fixed(Fixed const &fix_o);
	Fixed(int const i);
	Fixed(float const f);

	/*
	 *  Operator overload
	 */
	Fixed &	operator=(Fixed const &fix_o);
	bool	operator<(Fixed const &fix_o) const;
	bool 	operator>(Fixed const &fix_o) const;
	bool 	operator>=(Fixed const &fix_o) const;
	bool 	operator<=(Fixed const &fix_o) const;
	bool 	operator==(Fixed const &fix_o) const;
	bool 	operator!=(Fixed const &fix_o) const;
	float 	operator*(Fixed const &fix_o) const;
	float 	operator/(Fixed const &fix_o) const;
	float 	operator+(Fixed const &fix_o) const;
	float 	operator-(Fixed const &fix_o) const;
	float 	operator++(int);
	float 	operator++();
	float 	operator--(int);
	float 	operator--();

	/*
	 *  Func-member
	 */
	int 					getRawBits(void) const;
	void 					setRawBits(int const raw);
	float 					toFloat(void) const;
	int						toInt(void) const;
	static Fixed const&		max(Fixed const &, Fixed const &);
	static Fixed const&		min(Fixed const &, Fixed const &);
	static Fixed&			max(Fixed&, Fixed&);
	static Fixed&			min(Fixed&, Fixed&);

	~Fixed();

private:
	/*
	 *  Variable
	 */
	int					fix_point_value;
	const static int	bits = 8;
};

std::ostream &operator<<(std::ostream &, Fixed const &);


#endif
