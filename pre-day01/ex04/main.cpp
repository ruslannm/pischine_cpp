#include <iostream>
#include "FtSed.hpp"

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Usage: ft_sed filename string_from string_to"
				  << std::endl;
		return 0;
	}
	FtSed *ftSed = new FtSed(argv[1]);
	ftSed->replace(argv[2], argv[3]);
	delete ftSed;
	return (0);
}