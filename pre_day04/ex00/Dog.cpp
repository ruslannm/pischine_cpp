#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Default constructor called for Dog " << this->type
			  << std::endl;
	return;
};


Dog::Dog(std::string const type) : Animal(type)
{
	std::cout << "Constructor called for Dog " << this->type << std::endl;
	return;
};

Dog::Dog(Dog const &src)
{
	this->type = src.type;
	std::cout << "Copy constructor called for Dog " << this->type << std::endl;
	return;
};

Dog &Dog::operator=(Dog const &rhs)
{
	if (this != &rhs)
	{
		this->type = rhs.type;
	}
	std::cout << "Copy assignment called for Dog " << this->type
			  << std::endl;
	return *this;
};

Dog::~Dog(void)
{
	std::cout << "Destructor called for Dog " << this->type << std::endl;
	return;
};

void Dog::makeSound(void) const
{
	std::cout << "Gav!" << std::endl;
};
