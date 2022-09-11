#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "Default constructor called for WrongCat " << this->type
			  << std::endl;
	return;
};


WrongCat::WrongCat(std::string const type) : WrongAnimal(type)
{
	std::cout << "Constructor called for WrongCat " << this->type << std::endl;
	return;
};

WrongCat::WrongCat(WrongCat const &src)
{
	this->type = src.type;
	std::cout << "Copy constructor called for WrongCat " << this->type << std::endl;
	return;
};

WrongCat &WrongCat::operator=(WrongCat const &rhs)
{
	if (this != &rhs)
	{
		this->type = rhs.type;
	}
	std::cout << "Copy assignment called for WrongCat " << this->type
			  << std::endl;
	return *this;
};

WrongCat::~WrongCat(void)
{
	std::cout << "Destructor called for WrongCat " << this->type << std::endl;
	return;
};

void WrongCat::makeSound(void) const
{
	std::cout << "Meow!" << std::endl;
};
