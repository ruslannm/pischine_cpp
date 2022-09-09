#include "DiamondTrap.hpp"

int main(void){
	DiamondTrap a("Fist");
	DiamondTrap b("Second");
	for(size_t i = 0; i != 12; ++i)
	{
		a.attack("Second");
		b.takeDamage(1);
	}
	b.beRepaired(2);
	b.attack("First");
	a.whoAmI();
	b.whoAmI();
	return 0;
}