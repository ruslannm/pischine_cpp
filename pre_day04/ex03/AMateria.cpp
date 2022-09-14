#include "AMateria.hpp"

AMateria::AMateria(void) : type("Undefined"){};

AMateria::AMateria(std::string const &type) : type(type) {};

AMateria::AMateria(const AMateria &src) : type(src.getType()) {};

AMateria &
AMateria::operator=(const AMateria &rhs)
{
	if (this != &rhs)
	{
		this->type = rhs.type;
	}
	return *this;
}

AMateria::~AMateria(void) {}

std::string const &AMateria::getType(void) const
{
	return type;
};

void AMateria::use(ICharacter &) {};
