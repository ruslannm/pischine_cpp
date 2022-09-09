#include "Zombie.hpp"

int main(void)
{
	Zombie *zombie;
	zombie = Zombie::newZombie("Parasite");
	zombie->announce();
	delete zombie;

	zombie = Zombie::newZombie("Tickler");
	zombie->announce();
	delete zombie;

	Zombie::randomChump("Wailer");
	Zombie::randomChump("Primer");
	return (0);
}
