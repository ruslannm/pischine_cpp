#include <iostream>
#include "Base.hpp"

int main(void)
{
	for (size_t i = 0; i != 10; ++i)
	{
		std::cout << i << std::endl;
		Base *base = generate();
		std::cout << "identify by pointer: ";
		identify(base);
		std::cout << "identify by reference: ";
		identify(*base);
		delete base;
		std::cout << std::endl;
	}
	return 0;
}
