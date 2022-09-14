#include "Cat.hpp"

Cat::Cat() : AAnimal("Cat")
{
	this->brain = new Brain();
	std::cout << "Default constructor called for Cat " << this->type
			  << std::endl;
	return;
};


Cat::Cat(std::string const type) : AAnimal(type)
{
	this->brain = new Brain();
	std::cout << "Constructor called for Cat " << this->type << std::endl;
	return;
};

Cat::Cat(Cat const &src)
{
	this->type = src.type;
	this->brain = new Brain(*(src.brain));
	std::cout << "Copy constructor called for Cat " << this->type << std::endl;
	return;
};

Cat &Cat::operator=(Cat const &rhs)
{
	if (this != &rhs)
	{
		this->type = rhs.type;
		this->brain = rhs.brain;
	}
	std::cout << "Copy assignment called for Cat " << this->type
			  << std::endl;
	return *this;
};

Cat::~Cat(void)
{
	delete this->brain;
	std::cout << "Destructor called for Cat " << this->type << std::endl;
	return;
};

void Cat::makeSound(void) const
{
	std::cout << "Meow!" << std::endl;
	return;
};

std::string Cat::getIdea(size_t index) const
{
		return brain->getIdea(index);
};

void Cat::setIdea(size_t index, const std::string idea)
{
	brain->setIdea(index, idea);
	return;
};
