#include "FragTrap.hpp"

FragTrap::FragTrap(std::string const name) : ClapTrap(name)
{
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "Constructor called for FragTrap " << this->name
			  << " hitPoints: " << hitPoints
			  << ", energyPoint: " << energyPoints
			  << ", attackDamage: " << attackDamage << std::endl;
};

FragTrap::FragTrap(FragTrap const &src) : ClapTrap(src.name)
{
	this->hitPoints = src.hitPoints;
	this->energyPoints = src.energyPoints;
	this->attackDamage = src.attackDamage;


	std::cout << "Copy constructor called for FragTrap" << name
			  << " hitPoints: " << hitPoints
			  << ", energyPoint: " << energyPoints
			  << ", attackDamage: " << attackDamage << std::endl;
};

FragTrap &FragTrap::operator=(FragTrap const &rhs)
{
	if (this != &rhs)
	{
		this->name = rhs.name;
		this->hitPoints = rhs.hitPoints;
		this->energyPoints = rhs.energyPoints;
		this->attackDamage = rhs.attackDamage;
	}
	std::cout << "Assignment operator called for FragTrap " << name
			  << " hitPoints: " << hitPoints
			  << ", energyPoint: " << energyPoints
			  << ", attackDamage: " << attackDamage << std::endl;
	return *this;
};

FragTrap::~FragTrap(void)
{
	std::cout << "Destructor called for FragTrap " << this->name
			  << " hitPoints: " << hitPoints
			  << ", energyPoint: " << energyPoints
			  << ", attackDamage: " << attackDamage << std::endl;
	return;
};

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << name
			  << " request a positive high fives." << std::endl;
};
