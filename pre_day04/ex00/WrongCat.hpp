#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include <iostream>
#include <string>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
	WrongCat(void);

	WrongCat(std::string const);

	WrongCat(WrongCat const &);

	WrongCat &operator=(WrongCat const &);

	virtual ~WrongCat(void);

	void makeSound(void) const;

};

#endif

