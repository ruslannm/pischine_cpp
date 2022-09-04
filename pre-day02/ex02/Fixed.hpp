#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
public:
	Fixed(void);

	Fixed(int const);

	Fixed(float const);

	Fixed(Fixed const &);

	Fixed &operator=(Fixed const &);

	~Fixed(void);

	int getRawBits(void) const;

	void setRawBits(int const);

	float toFloat(void) const;

	int toInt(void) const;

	bool operator>(Fixed const &) const;

	bool operator<(Fixed const &) const;

	bool operator>=(Fixed const &) const;

	bool operator<=(Fixed const &) const;

	bool operator==(Fixed const &) const;

	bool operator!=(Fixed const &) const;

	Fixed operator+(Fixed const &) const;

	Fixed operator-(Fixed const &) const;

	Fixed operator*(Fixed const &) const;

	Fixed operator/(Fixed const &) const;

	Fixed &operator++(void);

	Fixed operator++(int);

	Fixed &operator--(void);

	Fixed operator--(int);

	static Fixed &min(Fixed &, Fixed &);

	static const Fixed &min(Fixed const &, Fixed const &);

	static Fixed &max(Fixed &, Fixed &);

	static const Fixed &max(Fixed const &, Fixed const &);

private:
	int _value;
	static const int _fractional;
};

std::ostream &operator<<(std::ostream &, Fixed const &);

#endif
