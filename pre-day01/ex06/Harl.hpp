#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

class Harl
{
public:
	void complain(std::string);

	void filter(std::string);

	Harl(void);

private:
	void debug(void);

	void info(void);

	void warning(void);

	void error(void);


	std::string _levels[4];

	size_t _getLevelNumber(std::string);
};

#endif
