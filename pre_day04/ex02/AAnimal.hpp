#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>
#include <string>

class AAnimal
{
public:
	AAnimal(void);

	AAnimal(std::string const);

	AAnimal(AAnimal const &);

	AAnimal &operator=(AAnimal const &);

	virtual ~AAnimal(void);

	virtual void makeSound(void) const = 0;

	std::string getType(void) const;

	virtual std::string getIdea(size_t) const = 0;

	virtual void setIdea(size_t, const std::string) = 0;

protected:
	std::string type;
};

#endif
