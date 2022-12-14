#include "HumanB.hpp"

void HumanB::attack()
{
	std::cout << _name << " attacks with their " << _weapon->getType()
			  << std::endl;
	return;
}

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {};

void HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
	return;
};
