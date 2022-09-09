#include "Weapon.hpp"

const std::string &Weapon::getType()
{
	std::string &ref = type;
	return ref;
}

void Weapon::setType(std::string type)
{
	this->type = type;
	return;
}

Weapon::Weapon(std::string type) : type(type) {};

