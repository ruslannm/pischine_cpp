#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include <string>
#include "Animal.hpp"

class Cat : public Animal
{
public:
	Cat(void);

	Cat(std::string const);

	Cat(Cat const &);

	Cat &operator=(Cat const &);

	virtual ~Cat(void);

	void makeSound(void) const;

};

#endif

