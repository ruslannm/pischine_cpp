#ifndef FTSED_HPP
#define FTSED_HPP

#include <iostream>
#include <fstream>
#include <string>

class FtSed
{
public:
	FtSed(std::string);

	~FtSed();
	bool replace(std::string, std::string);

private:
	std::ifstream _ifs;
	std::ofstream _ofs;
	bool _available;
};

#endif
