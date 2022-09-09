#include "Zombie.hpp"

int main(void)
{
	Zombie *zombies;
	int n = 5;
	zombies = Zombie::zombieHorde(n, "Parasite");
	for (int i = 0; i != n; ++i)
	{
		zombies[i].announce();
	}
	delete[] zombies;
	return (0);
}
