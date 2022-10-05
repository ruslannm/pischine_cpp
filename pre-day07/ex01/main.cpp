#include <iostream>
#include <string>
#include "iter.hpp"

int main(void)
{
	std::cout << "Test int: " << std::endl;
	int arrInt[3] = {1, 2, 3};
	iter(arrInt, 3, &printElement);

	std::cout << "Test string: " << std::endl;
	std::string arrString[3] = {"One", "Two", "Three"};
	iter(arrString, 3, &printElement);

	return 0;
}
