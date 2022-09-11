#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal
{
public:
	WrongAnimal(void);

	WrongAnimal(std::string const);

	WrongAnimal(WrongAnimal const &);

	WrongAnimal &operator=(WrongAnimal const &);

	virtual ~WrongAnimal(void);

	void makeSound(void) const;

	std::string getType(void) const;

protected:
	std::string type;
};

#endif
