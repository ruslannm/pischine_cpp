#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	this->brain = new Brain();
	std::cout << "Default constructor called for Dog " << this->type
			  << std::endl;
	return;
};


Dog::Dog(std::string const type) : Animal(type)
{
	this->brain = new Brain();
	std::cout << "Constructor called for Dog " << this->type << std::endl;
	return;
};

Dog::Dog(Dog const &src)
{
	this->type = src.type;
	this->brain = new Brain();
	std::cout << "Copy constructor called for Dog " << this->type << std::endl;
	return;
};

Dog &Dog::operator=(Dog const &rhs)
{
	if (this != &rhs)
	{
		this->type = rhs.type;
		this->brain = rhs.brain;
	}
	std::cout << "Copy assignment called for Dog " << this->type
			  << std::endl;
	return *this;
};

Dog::~Dog(void)
{
	delete this->brain;
	std::cout << "Destructor called for Dog " << this->type << std::endl;
	return;
};

void Dog::makeSound(void) const
{
	std::cout << "Gav!" << std::endl;
};

std::string Dog::getIdea(size_t index) const
{
	return brain->getIdea(index);
};

void Dog::setIdea(size_t index, const std::string idea)
{
	brain->setIdea(index, idea);
	return;
};
