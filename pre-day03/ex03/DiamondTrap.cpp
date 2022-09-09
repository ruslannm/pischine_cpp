#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string const name) : ClapTrap(
		name + "_clap_name"), FragTrap(name), ScavTrap(name)
{
	this->name = name;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 30;
	std::cout << "Constructor called for DiamondTrap " << this->name
			  << " hitPoints: " << this->hitPoints
			  << ", energyPoint: " << this->energyPoints
			  << ", attackDamage: " << this->attackDamage << std::endl;
	return;
};

DiamondTrap::DiamondTrap(DiamondTrap const &src) : ClapTrap(
		src.name + +"_clap_name"), FragTrap(src.name), ScavTrap(src.name)
{
	this->name = src.name;
	this->hitPoints = src.hitPoints;
	this->energyPoints = src.energyPoints;
	this->attackDamage = src.attackDamage;
	std::cout << "Copy constructor called for DiamondTrap" << this->name
			  << " hitPoints: " << this->hitPoints
			  << ", energyPoint: " << this->energyPoints
			  << ", attackDamage: " << this->attackDamage << std::endl;
	return;
};

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &rhs)
{
	if (this != &rhs)
	{
		this->name = rhs.name;
		this->hitPoints = rhs.hitPoints;
		this->energyPoints = rhs.energyPoints;
		this->attackDamage = rhs.attackDamage;
	}
	std::cout << "Assignment operator called for DiamondTrap " << this->name
			  << " hitPoints: " << this->hitPoints
			  << ", energyPoint: " << this->energyPoints
			  << ", attackDamage: " << this->attackDamage << std::endl;
	return *this;
};

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "Destructor called for DiamondTrap " << name
			  << " hitPoints: " << hitPoints
			  << ", energyPoint: " << energyPoints
			  << ", attackDamage: " << attackDamage << std::endl;
	return;
};

void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
	return;
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name " << name
			  << ", ClapTrap name = " << ClapTrap::name << std::endl;
	return;
};