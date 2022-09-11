#include "Animal.hpp"

Animal::Animal() : type("Unknown")
{
	std::cout << "Default constructor called for Animal " << this->type
			  << std::endl;
	return;
};


Animal::Animal(std::string const type) : type(type)
{
	std::cout << "Constructor called for Animal " << this->type << std::endl;
	return;
};

Animal::Animal(Animal const &src): type(src.getType())
{
	std::cout << "Copy constructor called for Animal " << this->type
			  << std::endl;
	return;
};

Animal &Animal::operator=(Animal const &rhs)
{
	if (this != &rhs)
	{
		this->type = rhs.type;
	}
	std::cout << "Copy assignment called for Animal " << this->type
			  << std::endl;
	return *this;
};

Animal::~Animal(void)
{
	std::cout << "Destructor called for Animal " << this->type << std::endl;
	return;
};

void Animal::makeSound(void) const
{
	std::cout << "Animal " << this->type << " makeSound" << std::endl;
};

std::string Animal::getType(void) const
{
	return type;
};
