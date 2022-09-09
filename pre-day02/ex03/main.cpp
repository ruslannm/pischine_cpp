#include <iostream>
#include "bsp.hpp"

int main(void)
{
	Point a(0, 0);
	Point b(0, 1);
	Point c(1, 0);
	float coord[4][2] = {{0,   1},
						 {0.1, 0.1},
						 {0,   0.5},
						 {2,   3}};
	char result[4][6] = {"False", "True", "False", "False"};
	std::cout << "TEST bsp " << std::endl;
	std::cout << "Vertices coord : [" << a.getX() << ", " << c.getY() << "], ["
			  << b.getX() << ", " << b.getY() << "], ["
			  << c.getX() << ", " << c.getY() << "]" << std::endl;


	for (size_t i = 0; i != 4; ++i)
	{
		Point p(coord[i][0], coord[i][1]);
		std::cout << "Point coord : [" << coord[i][0] << ", " << coord[i][i]
				  << "], ";
		std::cout << "expected: " << result[i] << ", actual: "
				  << (bsp(a, b, c, p) ? "True" : "False") << std::endl;

	}
	std::cout << "TEST operator= " << std::endl;
	std::cout << "Source coord :" << c.getX() << " " << c.getY() << std::endl;
	Point d(5, 5);
	std::cout << "Target coord before:" << d.getX() << " " << d.getY() << std::endl;
	d = c;
	std::cout << "Target coord after:" << d.getX() << " " << d.getY() << std::endl;
	return 0;
}
