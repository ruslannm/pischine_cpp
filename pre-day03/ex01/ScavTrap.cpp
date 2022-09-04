#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string const name) : ClapTrap(name)
{
//	this->name = name;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "Constructor called for ScavTrap " << name
			  << " hitPoints: " << hitPoints
			  << ", energyPoint: " << energyPoints
			  << ", attackDamage: " << attackDamage << std::endl;
};

ScavTrap::ScavTrap(ScavTrap const &src) : ClapTrap(src.name)
{
	this->hitPoints = src.hitPoints;
	this->energyPoints = src.energyPoints;
	this->attackDamage = src.attackDamage;


	std::cout << "Copy constructor called for ClapTrap" << name
			  << " hitPoints: " << hitPoints
			  << ", energyPoint: " << energyPoints
			  << ", attackDamage: " << attackDamage << std::endl;
};

ScavTrap &ScavTrap::operator=(ScavTrap const &rhs)
{
	if (this != &rhs)
	{
		this->name = rhs.name;
		this->hitPoints = rhs.hitPoints;
		this->energyPoints = rhs.energyPoints;
		this->attackDamage = rhs.attackDamage;
	}
	std::cout << "Assignment operator called for ScavTrap " << name
			  << " hitPoints: " << hitPoints
			  << ", energyPoint: " << energyPoints
			  << ", attackDamage: " << attackDamage << std::endl;
	return *this;
};

ScavTrap::~ScavTrap(void)
{
	std::cout << "Destructor called for ScavTrap " << name
			  << " hitPoints: " << hitPoints
			  << ", energyPoint: " << energyPoints
			  << ", attackDamage: " << attackDamage << std::endl;
};

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << name
			  << " is now in Gate keeper mode." << std::endl;
};