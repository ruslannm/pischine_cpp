#include "ClapTrap.hpp"

int main(void){
	ClapTrap a("Fist");
	ClapTrap b("Second");

	for(size_t i = 0; i != 12; ++i)
	{
		a.attack("Second");
		b.takeDamage(1);
	}
	b.beRepaired(2);
	b.attack("First");
	return 0;
}