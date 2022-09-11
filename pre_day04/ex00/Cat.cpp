#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Default constructor called for Cat " << this->type
			  << std::endl;
	return;
};


Cat::Cat(std::string const type) : Animal(type)
{
	std::cout << "Constructor called for Cat " << this->type << std::endl;
	return;
};

Cat::Cat(Cat const &src)
{
	this->type = src.type;
	std::cout << "Copy constructor called for Cat " << this->type << std::endl;
	return;
};

Cat &Cat::operator=(Cat const &rhs)
{
	if (this != &rhs)
	{
		this->type = rhs.type;
	}
	std::cout << "Copy assignment called for Cat " << this->type
			  << std::endl;
	return *this;
};

Cat::~Cat(void)
{
	std::cout << "Destructor called for Cat " << this->type << std::endl;
	return;
};

void Cat::makeSound(void) const
{
	std::cout << "Meow!" << std::endl;
};
