#ifndef BRAIN_HPP
#define BRAIN_HPP

#define IDEAS_SIZE 100

#include <iostream>
#include <string>

class Brain
{
public:
	Brain(void);

	Brain(Brain const &);

	Brain &operator=(Brain const &);

	~Brain(void);

	std::string getIdea(size_t) const;

	void setIdea(size_t, const std::string);

private:
	std::string ideas[IDEAS_SIZE];
};

#endif
