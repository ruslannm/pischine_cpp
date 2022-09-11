#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include <string>
#include "Animal.hpp"

class Dog: public Animal
{
public:
	Dog(void);

	Dog(std::string const);

	Dog(Dog const &);

	Dog &operator=(Dog const &);

	virtual ~Dog(void);

	void makeSound(void) const;

};

#endif
