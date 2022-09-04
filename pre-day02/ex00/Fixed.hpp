#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
public:
	Fixed(void);

	Fixed(Fixed const &);

	Fixed &operator=(Fixed const &);

	~Fixed(void);

	int getRawBits(void) const;

	void setRawBits(int const);

private:
	int _value;
	static const int _fractional;
};

#endif
