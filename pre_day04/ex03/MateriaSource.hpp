#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <iostream>
#include "IMateriaSource.hpp"

# define STOCK_SIZE 4

class MateriaSource : public IMateriaSource
{
public:
	MateriaSource(void);

	MateriaSource(const MateriaSource &);

	virtual ~MateriaSource(void);

	MateriaSource &operator=(const MateriaSource &);

	virtual void learnMateria(AMateria *);

	virtual AMateria *createMateria(std::string const &);

private:
	AMateria *stock[STOCK_SIZE];
};

#endif
