#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria
{
public:
	Cure(void);

	Cure(const Cure &);

	Cure &operator=(const Cure &);

	~Cure(void);

	virtual AMateria *clone() const;

	virtual void use(ICharacter &target);
};

#endif
