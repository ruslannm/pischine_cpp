#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
class ICharacter;

# define MAX_SIZE 1024

class AMateria
{
protected:
	std::string type;
public:
	AMateria(std::string const &);

	AMateria();

	AMateria(const AMateria &);

	AMateria &operator=(AMateria const &);

	virtual ~AMateria();

	std::string const &getType() const;

	virtual AMateria *clone() const = 0;

	virtual void use(ICharacter &target);
};

#endif
