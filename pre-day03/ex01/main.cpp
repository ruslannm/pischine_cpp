#include "ScavTrap.hpp"

int main(void){
	ScavTrap a("Fist");
	ScavTrap b("Second");

	for(size_t i = 0; i != 12; ++i)
	{
		a.attack("Second");
		b.takeDamage(1);
	}
	b.beRepaired(2);
	b.attack("First");
	b.guardGate();
	return 0;
}