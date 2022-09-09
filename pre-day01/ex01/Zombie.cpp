#include "Zombie.hpp"

void Zombie::announce(void){
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return;
};

Zombie::~Zombie(void ){
	std::cout << name << ": destroyed" << std::endl;
	return;
};