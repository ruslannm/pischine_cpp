#include <iostream>
#include "Harl.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: harlFilter level"
				  << std::endl;
		return 0;
	}
	Harl harl;
	harl.filter(argv[1]);
	return (0);
}