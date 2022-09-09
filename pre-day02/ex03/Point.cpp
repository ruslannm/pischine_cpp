#include "Point.hpp"

Point::Point(void) : x(0), y(0) {};

Point::Point(float const x, float const y) : x(x), y(y) {};

Point::Point(Point const &src) : x(src.getX().toFloat()),
								 y(src.getY().toFloat()) {};

Point::~Point(void) {};

Point &Point::operator=(Point const &rhs)
{
	if (this != &rhs)
	{
		Fixed * _x = (Fixed *) &(this->x);
		_x->setRawBits(rhs.x.getRawBits());
		Fixed * _y = (Fixed *) &(this->y);
		_y->setRawBits(rhs.y.getRawBits());
	}
	return *this;
};

Fixed Point::getX(void) const
{
	return this->x;
};

Fixed Point::getY(void) const
{
	return this->y;
};
