#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void){
	ClapTrap a("Fist");
	ScavTrap b("Second");
	FragTrap c("Third");
	for(size_t i = 0; i != 12; ++i)
	{
		b.attack("Third");
		c.takeDamage(1);
	}
	c.beRepaired(2);
	c.attack("First");
	a.takeDamage(1);
	b.guardGate();
	c.highFivesGuys();
	return 0;
}