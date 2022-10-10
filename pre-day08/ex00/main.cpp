#include <vector>
#include <iostream>
#include "easyfind.hpp"

int main(void)
{
	std::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	int a[3] = {1, 3, 10};

	for (int i = 0; i != 3; ++i)
	{
		try
		{
			std::vector<int>::const_iterator iter = easyfind(v, a[i]);
			std::cout << "The value " << *iter << " has been found"
					  << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	return 0;
}
