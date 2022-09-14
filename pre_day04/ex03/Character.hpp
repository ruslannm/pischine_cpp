#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include "ICharacter.hpp"
#include "Node.hpp"

# define INVENTORY_SIZE 4


class Character : public ICharacter
{
public:
	Character(void);

	Character(const std::string);

	Character(const Character &);

	virtual ~Character(void);

	Character &operator=(const Character &);

	virtual std::string const &getName() const;

	virtual void equip(AMateria *m);

	virtual void unequip(int idx);

	virtual void use(int idx, ICharacter &target);

private:
	std::string name;
	AMateria *inventory[INVENTORY_SIZE];
	Node *floor;
};

#endif
