#include "Fixed.hpp"

Fixed::Fixed(void) : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
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
	std::cout << "getRawBits member function called" << std::endl;
	return this->_value;
};

void Fixed::setRawBits(int const raw)
{
	this->_value = raw;
	return;
};

const int Fixed::_fractional = 8;
