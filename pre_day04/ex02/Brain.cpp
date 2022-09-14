#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Default constructor called for Brain " << std::endl;
	return;
};

Brain::Brain(Brain const &src)
{
	for (size_t i = 0; i != IDEAS_SIZE; ++i)
	{
		this->ideas[i] = src.ideas[i];
	}
	std::cout << "Copy constructor called for Brain " << std::endl;
	return;
};

Brain &Brain::operator=(Brain const &rhs)
{
	if (this != &rhs)
	{
		for (size_t i = 0; i != IDEAS_SIZE; ++i)
		{
			this->ideas[i] = rhs.ideas[i];
		}
	}
	std::cout << "Copy assignment called for Brain " << std::endl;
	return *this;
};

Brain::~Brain(void)
{
	std::cout << "Destructor called for Brain " << std::endl;
	return;
};

std::string Brain::getIdea(size_t index) const
{
	if (0 <= index && index < IDEAS_SIZE)
	{
		return ideas[index];
	}
	else
	{
		return "Index out of bound";
	}
};

void Brain::setIdea(size_t index, const std::string idea)
{
	if (0 <= index && index < IDEAS_SIZE)
	{
		ideas[index] = idea;
	}
	return;
};

