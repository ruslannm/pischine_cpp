#include "Character.hpp"
#include "AMateria.hpp"

Character::Character(void) : name("Undefined")
{
	for (size_t i = 0; i != INVENTORY_SIZE; ++i)
	{
		this->inventory[i] = NULL;
	}
	floor = NULL;
	return;
}

Character::Character(std::string name) : name(name)
{
	for (size_t i = 0; i != INVENTORY_SIZE; ++i)
	{
		this->inventory[i] = NULL;
	}
	floor = NULL;
	return;
}

Character::Character(const Character &src) : name(src.getName())
{
	for (size_t i = 0; i != INVENTORY_SIZE; ++i)
	{
		this->inventory[i] = src.inventory[i]->clone();
	}
	floor = NULL;
	return;
}

Character &Character::operator=(const Character &rhs)
{
	if (this != &rhs)
	{
		this->name = rhs.name;
		for (size_t i = 0; i != INVENTORY_SIZE; ++i)
		{
			this->inventory[i] = rhs.inventory[i]->clone();
		}
	}
	floor = NULL;
	return *this;
}

Character::~Character(void)
{
	for (size_t i = 0; i != INVENTORY_SIZE; ++i)
	{
		if (this->inventory[i] != NULL)
		{
			delete this->inventory[i];
			this->inventory[i] = NULL;
		}
	}
	if (floor)
	{
		Node *tail = floor;
		while (tail)
		{
			Node *tmp = tail;
			tail = tail->getNext();
			delete tmp->getMateria();
			delete tmp;
		}
		floor = NULL;
	}
	return;
}

std::string const &Character::getName() const
{
	return name;
};

void Character::equip(AMateria *materia)
{
	for (size_t i = 0; i != INVENTORY_SIZE; ++i)
	{
		if (this->inventory[i] == NULL)
		{
			this->inventory[i] = materia;
			break;
		}
	}
};

void Character::unequip(int idx)
{
	if (0 <= idx && idx < INVENTORY_SIZE)
	{
		Node *tmp = new Node(this->inventory[idx]);
		if (floor == NULL)
		{
			floor = tmp;
		}
		else
		{
			Node *tail = floor;
			while (tail->getNext())
			{
				tail = tail->getNext();
			}
			tail->setNext(tmp);
		}
		this->inventory[idx] = NULL;
	}
	return;
};

void Character::use(int idx, ICharacter &target)
{
	if (0 <= idx && idx < INVENTORY_SIZE && this->inventory[idx])
	{
		this->inventory[idx]->use(target);
	}
};
