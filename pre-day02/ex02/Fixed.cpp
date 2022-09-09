#include "Fixed.hpp"

Fixed::Fixed(void) : _value(0) {};

Fixed::Fixed(int const value) : _value(value)
{
	this->_value = value * (1 << this->_fractional);
	return;
}

Fixed::Fixed(float const value)
{
	this->_value = std::roundf(value * (1 << this->_fractional));
	return;
};

Fixed::Fixed(Fixed const &src)
{
	*this = src;
	return;
};

Fixed &Fixed::operator=(Fixed const &rhs)
{
	if (this != &rhs)
	{
		this->_value = rhs.getRawBits();
	}
	return *this;
};

Fixed::~Fixed(void) {};

int Fixed::getRawBits(void) const
{
	return this->_value;
};

void Fixed::setRawBits(int const raw)
{
	this->_value = raw;
	return;
};

float Fixed::toFloat(void) const
{
	return (float) this->_value / (1 << this->_fractional);
};

int Fixed::toInt(void) const
{
	return this->_value / (1 << this->_fractional);
};

bool Fixed::operator>(Fixed const &other) const
{
	return this->_value > other.getRawBits();
};

bool Fixed::operator<(Fixed const &other) const
{
	return this->_value < other.getRawBits();
};

bool Fixed::operator>=(Fixed const &other) const
{
	return this->_value >= other.getRawBits();
};

bool Fixed::operator<=(Fixed const &other) const
{
	return this->_value <= other.getRawBits();
};

bool Fixed::operator==(Fixed const &other) const
{
	return this->_value == other.getRawBits();
};

bool Fixed::operator!=(Fixed const &other) const
{
	return this->_value != other.getRawBits();
};

Fixed Fixed::operator+(Fixed const &other) const
{
	Fixed result;
	result.setRawBits(this->_value + other.getRawBits());
	return result;
};

Fixed Fixed::operator-(Fixed const &other) const
{
	Fixed result;
	result.setRawBits(this->_value - other.getRawBits());
	return result;
};

Fixed Fixed::operator*(Fixed const &other) const
{
	Fixed result;
	result.setRawBits(
			this->_value * other.getRawBits() / (1 << this->_fractional));
	return result;
};

Fixed Fixed::operator/(Fixed const &other) const
{
	Fixed result;
	if (other.getRawBits())
	{
		result.setRawBits(
				this->_value * (1 << this->_fractional) / other.getRawBits());
	}
	else
	{
		result.setRawBits(0);
	}
	return result;
};

Fixed &Fixed::operator++(void)
{
	this->_value++;
	return *this;
};

Fixed Fixed::operator++(int)
{
	Fixed tmp;
	tmp.setRawBits(this->_value);
	++this->_value;
	return tmp;
};

Fixed &Fixed::operator--(void)
{
	this->_value--;
	return *this;
};

Fixed Fixed::operator--(int)
{
	Fixed tmp;
	tmp.setRawBits(this->_value);
	--this->_value;
	return tmp;
};

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b) ? a : b;
};

const Fixed &Fixed::min(Fixed const &a, Fixed const &b)
{
	return (a < b) ? a : b;
};

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b) ? a : b;
};

const Fixed &Fixed::max(Fixed const &a, Fixed const &b)
{
	return (a > b) ? a : b;
};

const int Fixed::_fractional = 8;

std::ostream &operator<<(std::ostream &o, Fixed const &src)
{
	o << src.toFloat();
	return o;
};
