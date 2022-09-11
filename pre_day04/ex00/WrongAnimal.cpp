#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("Unknown")
{
	std::cout << "Default constructor called for WrongAnimal " << this->type
			  << std::endl;
	return;
};


WrongAnimal::WrongAnimal(std::string const type) : type(type)
{
	std::cout << "Constructor called for WrongAnimal " << this->type << std::endl;
	return;
};

WrongAnimal::WrongAnimal(WrongAnimal const &src): type(src.getType())
{
	std::cout << "Copy constructor called for WrongAnimal " << this->type
			  << std::endl;
	return;
};

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &rhs)
{
	if (this != &rhs)
	{
		this->type = rhs.type;
	}
	std::cout << "Copy assignment called for WrongAnimal " << this->type
			  << std::endl;
	return *this;
};

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "Destructor called for WrongAnimal " << this->type << std::endl;
	return;
};

void WrongAnimal::makeSound(void) const
{
	std::cout << "WrongAnimal " << this->type << " makeSound" << std::endl;
};

std::string WrongAnimal::getType(void) const
{
	return type;
};
