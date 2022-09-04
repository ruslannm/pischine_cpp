#include "Fixed.hpp"

Fixed::Fixed(void) : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
	return;
};

Fixed::Fixed(int const value) : _value(value)
{
	std::cout << "Int constructor called" << std::endl;
	this->_value = value * (1 << this->_fractional);
	return;
};

Fixed::Fixed(float const value)
{
	std::cout << "Float constructor called" << std::endl;
	this->_value = std::roundf(value * (1 << this->_fractional));
	return;
};

Fixed::Fixed(Fixed const &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return;
};

Fixed &Fixed::operator=(Fixed const &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->_value = rhs.getRawBits();
	}
	return *this;
};

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
};

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

const int Fixed::_fractional = 8;

std::ostream &operator<<(std::ostream & o, Fixed const & src)
{
	o << src.toFloat();
	return o;
};
