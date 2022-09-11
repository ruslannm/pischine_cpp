#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
public:
	Animal(void);

	Animal(std::string const);

	Animal(Animal const &);

	Animal &operator=(Animal const &);

	virtual ~Animal(void);

	virtual void makeSound(void) const;

	std::string getType(void) const;

	virtual std::string getIdea(size_t) const = 0;

	virtual void setIdea(size_t, const std::string) = 0;

protected:
	std::string type;
};

#endif
