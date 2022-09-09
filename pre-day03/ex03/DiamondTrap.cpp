#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string const name) : ClapTrap(
		name + "_clap_name"), FragTrap(name), ScavTrap(name)
{
	this->name = name;
	this->hitPoints = FragTrap::hitPoints;
	this->energyPoints = ScavTrap::energyPoints;
	this->attackDamage = FragTrap::attackDamage;
	std::cout << "Constructor called for DiamondTrap " << name
			  << " hitPoints: " << hitPoints
			  << ", energyPoint: " << energyPoints
			  << ", attackDamage: " << attackDamage << std::endl;
};

DiamondTrap::DiamondTrap(DiamondTrap const &src) : ClapTrap(
		src.name + +"_clap_name"), FragTrap(src.name), ScavTrap(src.name)
{
	this->name = src.name;
	this->hitPoints = src.hitPoints;
	this->energyPoints = src.energyPoints;
	this->attackDamage = src.attackDamage;


	std::cout << "Copy constructor called for DiamondTrap" << name
			  << " hitPoints: " << hitPoints
			  << ", energyPoint: " << energyPoints
			  << ", attackDamage: " << attackDamage << std::endl;
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
	std::cout << "Assignment operator called for DiamondTrap " << name
			  << " hitPoints: " << hitPoints
			  << ", energyPoint: " << energyPoints
			  << ", attackDamage: " << attackDamage << std::endl;
	return *this;
};

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "Destructor called for DiamondTrap " << name
			  << " hitPoints: " << hitPoints
			  << ", energyPoint: " << energyPoints
			  << ", attackDamage: " << attackDamage << std::endl;
};

void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name " << name
			  << ", ClapTrap name = " << ClapTrap::name << std::endl;
};