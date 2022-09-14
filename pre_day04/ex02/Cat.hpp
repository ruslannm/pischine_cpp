#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include <string>
#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
public:
	Cat(void);

	Cat(std::string const);

	Cat(Cat const &);

	Cat &operator=(Cat const &);

	virtual ~Cat(void);

	void makeSound(void) const;

	std::string getIdea(size_t) const;

	void setIdea(size_t, const std::string);

private:
	Brain *brain;
};

#endif

