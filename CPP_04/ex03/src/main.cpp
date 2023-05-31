#include "../inc/AMateria.hpp"
#include "../inc/IMateriaSource.hpp"
#include "../inc/MateriaSource.hpp"
#include "../inc/Ice.hpp"
#include "../inc/Cure.hpp"
#include "../inc/Character.hpp"

int	main() {
	std::cout << std::endl;

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	std::cout << std::endl;

	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	std::cout << "Testing assignment operator" << std::endl;

	ICharacter* bob = new Character("bob");
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		std::cout << std::endl;
		Character billy("billy");
		Character jonny("jonny");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		billy.equip(tmp);
		tmp = src->createMateria("cure");
		billy.equip(tmp);
		tmp = src->createMateria("ice");
		billy.equip(tmp);
		tmp = src->createMateria("cure");
		billy.equip(tmp);

		jonny = billy;
		jonny.unequip(3);
		std::cout << "First Billy..." << std::endl;
		billy.use(3, *bob);
		std::cout << "Now Jonny..." << std::endl;
		jonny.use(3, *bob);
		delete src;
	}

	std::cout << std::endl;
	
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	me->use(-4, *bob);


	me->unequip(0);
	me->unequip(1);
	me->unequip(2);
	me->unequip(3);
	me->unequip(4);
	me->use(0, *bob);

	std::cout << std::endl;

	delete bob;
	delete me;
	delete src;
	return 0;
}