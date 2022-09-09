#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "iostream"
#include "Weapon.hpp"

class HumanB
{
public:
	void attack(void);

	HumanB(std::string);

	void setWeapon(Weapon &);

private:
	std::string _name;
	Weapon *_weapon;
};

#endif