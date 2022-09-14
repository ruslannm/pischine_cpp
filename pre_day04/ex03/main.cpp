#include "MateriaSource.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"

int main(void)
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;

	std::cout << "OTHER TESTS" << std::endl;
	src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	me = new Character("me");
	bob = new Character("bob");
	tmp = src->createMateria("stone");
	me->equip(tmp);
	me->unequip(2);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cube");
	me->equip(tmp);
	std::cout << "Full inventory" << std::endl;
	for (int i=0; i!= INVENTORY_SIZE; ++i){
		me->use(i, *bob);
	}
	me->unequip(1);
	std::cout << "Not full inventory" << std::endl;
	for (int i=0; i!= INVENTORY_SIZE; ++i){
		me->use(i, *bob);
	}

	delete me;
	delete bob;
	delete src;

	return 0;
}
