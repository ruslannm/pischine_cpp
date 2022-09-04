#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
public:
	ClapTrap(std::string const);

	ClapTrap(ClapTrap const &);

	ClapTrap &operator=(ClapTrap const &);

	~ClapTrap(void);

	void attack(const std::string &target);

	void takeDamage(unsigned int amount);

	void beRepaired(unsigned int amount);

private:
	std::string name;
	unsigned int hitPoints;
	unsigned int energyPoints;
	unsigned attackDamage;
};


#endif
