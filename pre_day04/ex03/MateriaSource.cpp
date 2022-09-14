#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	for (size_t i = 0; i != STOCK_SIZE; ++i)
	{
		this->stock[i] = NULL;
	}
	return;
};

MateriaSource::MateriaSource(const MateriaSource &src)
{
	for (size_t i = 0; i != STOCK_SIZE; ++i)
	{
		this->stock[i] = src.stock[i]->clone();
	}
	return;
};

MateriaSource &MateriaSource::operator=(const MateriaSource &rhs)
{
	if (this != &rhs)
	{
		for (size_t i = 0; i != STOCK_SIZE; ++i)
		{
			this->stock[i] = rhs.stock[i]->clone();
		}
	}
	return *this;
};

MateriaSource::~MateriaSource(void)
{
	for (size_t i = 0; i != STOCK_SIZE; ++i)
	{
		if (this->stock[i] != NULL)
		{
			delete this->stock[i];
			this->stock[i] = NULL;
		}
	}
	return;
};

void MateriaSource::learnMateria(AMateria *materia)
{
	for (size_t i = 0; i != STOCK_SIZE; ++i)
	{
		if (this->stock[i] == NULL)
		{
			this->stock[i] = materia;
			break;
		}
	}
};

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (size_t i = 0; i != STOCK_SIZE; ++i)
	{
		if (stock[i] && (stock[i]->getType() == type))
			return stock[i]->clone();
	}
	return 0;
};
