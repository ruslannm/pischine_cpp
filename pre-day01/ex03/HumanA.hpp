#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "iostream"
#include "Weapon.hpp"

class HumanA
{
public:
	void attack(void );

	HumanA(std::string, Weapon &);

private:
	std::string _name;
	Weapon *_weapon;
};

#endif
