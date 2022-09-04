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
	for (size_t i = 0; i != 4; ++i)
	{
		Point p(coord[i][0], coord[i][1]);
		std::cout << result[i] << " = " << bsp(a, b, c, p) << std::endl;

	}
	return 0;
}
