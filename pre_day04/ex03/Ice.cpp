#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice") {}

Ice::Ice(const Ice &src) : AMateria(src.getType()) {};

Ice &Ice::operator=(const Ice &) { return *this; };

Ice::~Ice(void) {};

AMateria *Ice::clone(void) const { return (new Ice(*this)); };

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *"
			  << std::endl;
	return;
}
