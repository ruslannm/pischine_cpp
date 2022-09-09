#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
public:
	void announce(void);

	~Zombie(void );

	static Zombie *zombieHorde(int N, std::string name);

private:
	std::string name;
};

#endif
