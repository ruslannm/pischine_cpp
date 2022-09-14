#include "AAnimal.hpp"

AAnimal::AAnimal() : type("Unknown")
{
	std::cout << "Default constructor called for AAnimal " << this->type
			  << std::endl;
	return;
};


AAnimal::AAnimal(std::string const type) : type(type)
{
	std::cout << "Constructor called for AAnimal " << this->type << std::endl;
	return;
};

AAnimal::AAnimal(AAnimal const &src) : type(src.getType())
{
	std::cout << "Copy constructor called for AAnimal " << this->type
			  << std::endl;
	return;
};

AAnimal &AAnimal::operator=(AAnimal const &rhs)
{
	if (this != &rhs)
	{
		this->type = rhs.type;
	}
	std::cout << "Copy assignment called for AAnimal " << this->type
			  << std::endl;
	return *this;
};

AAnimal::~AAnimal(void)
{
	std::cout << "Destructor called for AAnimal " << this->type << std::endl;
	return;
};

std::string AAnimal::getType(void) const
{
	return type;
};
