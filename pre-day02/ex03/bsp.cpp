#include "bsp.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed sign1 = (a.getX() - point.getX()) * (b.getY() - a.getY()) -
				  (b.getX() - a.getX()) * (a.getY() - point.getY());
	Fixed sign2 = (b.getX() - point.getX()) * (c.getY() - b.getY()) -
				  (c.getX() - b.getX()) * (b.getY() - point.getY());
	Fixed sign3 = (c.getX() - point.getX()) * (a.getY() - c.getY()) -
				  (a.getX() - c.getX()) * (c.getY() - point.getY());

	return ((sign1.getRawBits() > 0 && sign2.getRawBits() > 0 &&
		 sign3.getRawBits() > 0) ||
		(sign1.getRawBits() < 0 && sign2.getRawBits() < 0 &&
		 sign3.getRawBits() < 0));
};
