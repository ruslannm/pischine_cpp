#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
public:
	Point(void);

	Point(float const, float const);

	Point(Point const &);

	~Point(void);

	Point &operator=(Point const &);

	Fixed getX(void) const;

	Fixed getY(void) const;

private:
	Fixed const x;
	Fixed const y;
};

#endif
