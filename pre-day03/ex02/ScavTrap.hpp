#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
	ScavTrap(std::string const);

	ScavTrap(ScavTrap const &);

	ScavTrap &operator=(ScavTrap const &);

	~ScavTrap(void);

	void attack(const std::string &target);

	void guardGate();
};

#endif
