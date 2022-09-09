#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string const name) : name(name), hitPoints(10),
											 energyPoints(10),
											 attackDamage(0)
{
	std::cout << "Constructor called for " << this->name
			  << " hitPoints: " << hitPoints
			  << ", energyPoint: " << energyPoints
			  << ", attackDamage: " << attackDamage << std::endl;
	return;
};

ClapTrap::ClapTrap(ClapTrap const &src) : name(src.name),
										  hitPoints(src.hitPoints),
										  energyPoints(src.energyPoints),
										  attackDamage(src.attackDamage)
{
	std::cout << "Copy constructor called for " << name
			  << " hitPoints: " << hitPoints
			  << ", energyPoint: " << energyPoints
			  << ", attackDamage: " << attackDamage << std::endl;
	return;
};

ClapTrap &ClapTrap::operator=(ClapTrap const &rhs)
{
	if (this != &rhs)
	{
		this->name = rhs.name;
		this->hitPoints = rhs.hitPoints;
		this->energyPoints = rhs.energyPoints;
		this->attackDamage = rhs.attackDamage;
	}
	std::cout << "Assignment operator called for " << name
			  << " hitPoints: " << hitPoints
			  << ", energyPoint: " << energyPoints
			  << ", attackDamage: " << attackDamage << std::endl;
	return *this;
};

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor called for " << name
			  << " hitPoints: " << hitPoints
			  << ", energyPoint: " << energyPoints
			  << ", attackDamage: " << attackDamage << std::endl;
	return;
}

void ClapTrap::attack(const std::string &target)
{
	if (energyPoints)
	{
		--energyPoints;
        ++attackDamage;
		std::cout << "ClapTrap " << name << " attacks " << target
				  << ", causing "
				  << attackDamage << " points of damage!" << std::endl;
	} else {
		std::cout << "ClapTrap " << name << " can not attack." << std::endl;
	}
	return;
};

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoints >= amount)
	{
		hitPoints -= amount;
	}
	else
	{
		hitPoints = 0;
	}
	std::cout << "ClapTrap " << name << " has " << hitPoints
			  << " hit points after taking damage  causing." << std::endl;
	return;
};

void ClapTrap::beRepaired(unsigned int amount)
{
	if (energyPoints)
	{
		hitPoints += amount;
		--energyPoints;
		std::cout << "ClapTrap " << name << " repared and has "
				  << hitPoints << " hit points!" << std::endl;
	} else {
		std::cout << "ClapTrap " << name << " can not repared" << std::endl;
	}
	return;
};
