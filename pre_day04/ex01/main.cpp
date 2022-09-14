#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

# define ANIMALS_SIZE 4

int main(void)
{
	Animal *animals[ANIMALS_SIZE];
	for (size_t i = 0; i != ANIMALS_SIZE; ++i)
	{
		if (i % 2)
		{
			animals[i] = new Dog();
		}
		else
		{
			animals[i] = new Cat();
		}
	}
	std::cout << std::endl << "Check types of Animals:" << std::endl;
	for (size_t i = 0; i != ANIMALS_SIZE; ++i)
	{
		std::cout << "Index: " << i << ", Animal type:" << animals[i]->getType()
				  << std::endl;
	}
	std::cout << std::endl;

	for (size_t i = 0; i != ANIMALS_SIZE; ++i)
	{
		delete animals[i];
	}

	std::cout << std::endl << "Test deep copy" << std::endl;
	Animal *cat = new Cat();
	((Cat *) cat)->setIdea(0, "meow");
	((Cat *) cat)->setIdea(1, "hiss");
	Animal *catCopy = new Cat(*((Cat *) cat));
	std::cout << std::endl << "After coping" << std::endl;
	std::cout << "Cat ideas: " << ((Cat *) cat)->getIdea(0) << ", "
			  << ((Cat *) cat)->getIdea(1) << std::endl;
	std::cout << "CatCopy ideas: " << ((Cat *) catCopy)->getIdea(0) << ", "
			  << ((Cat *) catCopy)->getIdea(1) << std::endl;
	((Cat *) catCopy)->setIdea(0, "growl");
	((Cat *) catCopy)->setIdea(1, "purr");
	std::cout << std::endl << "After changing catCopy" << std::endl;
	std::cout << "Cat ideas: " << ((Cat *) cat)->getIdea(0) << ", "
			  << ((Cat *) cat)->getIdea(1) << std::endl;
	std::cout << "CatCopy ideas: " << ((Cat *) catCopy)->getIdea(0) << ", "
			  << ((Cat *) catCopy)->getIdea(1) << std::endl;
	std::cout << std::endl;
	delete cat;
	delete catCopy;
	return 0;
}
