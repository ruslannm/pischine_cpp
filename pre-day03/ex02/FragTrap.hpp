#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
	FragTrap(std::string const);

	FragTrap(FragTrap const &);

	FragTrap &operator=(FragTrap const &);

	~FragTrap(void);

	void highFivesGuys(void);
};

#endif
