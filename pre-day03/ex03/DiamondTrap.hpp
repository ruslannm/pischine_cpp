#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include <iostream>
#include <string>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
public:
	DiamondTrap(std::string const);

	DiamondTrap(DiamondTrap const &);

	DiamondTrap &operator=(DiamondTrap const &);

	~DiamondTrap(void);

	void attack(const std::string &target);

	void whoAmI();

private:
	std::string name;
};

#endif
