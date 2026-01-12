#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Floor.hpp"
#include "constants.hpp"
#include "print.hpp"
#include <iostream>
#include <cstdlib>

void	testSubjectExample()
{
	println("==== TEST 1: SUBJECT EXAMPLE ====");
	println("=================================");
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
}

void	testDeepCopyCharacter()
{
	println("==== TEST 2: DEEP COPY CHARACTER ====");
	println("======================================");
	Character*	original = new Character("Alice");
	Character*	copy = new Character(*original);
	Character*	assigned = new Character("Temp");

	*assigned = *original;
	AMateria* ice = new Ice();
	AMateria* cure = new Cure();
	original->equip(ice);
	original->equip(cure);
	original->printInventory();
	copy->printInventory();
	assigned->printInventory();
	delete original;
	delete copy;
	delete assigned;
}

void	testFloor()
{
	println("==== TEST 3: FLOOR ====");
	println("=======================");
	Character*	hero = new Character("Hero");
	Character*	enemy = new Character("Enemy");
	AMateria*	ice1 = new Ice();
	AMateria*	cure1 = new Cure();
	AMateria*	ice2 = new Ice();

	hero->equip(ice1);
	hero->equip(cure1);
	hero->equip(ice2);
	hero->unequip(1);
	hero->printInventory();
	hero->getFloor()->printFloor();
	hero->pickUp(0);
	hero->printInventory();
	delete hero;
	delete enemy;
}

void	testMateriaSource()
{
	println("==== TEST 4: MATERIA SOURCE ====");
	println("================================");
	MateriaSource*	src = new MateriaSource();
	AMateria*		ice1 = new Ice();
	AMateria*		cure1 = new Cure();

	src->learnMateria(ice1);
	src->learnMateria(cure1);
	AMateria* ice2 = src->createMateria("ice");
	AMateria* cure2 = src->createMateria("cure");
	AMateria* unknown = src->createMateria("fire");
	Character* bob = new Character("Bob");
	if (ice2) bob->equip(ice2);
	if (cure2) bob->equip(cure2);
	if (!unknown) println("Unknown type correctly returns NULL");
	bob->printInventory();
	delete bob;
	delete src;
}

void	testFullInventory()
{
	println("==== TEST 5: FULL INVENTORY ====");
	println("================================");
	Character*	packrat = new Character("Packrat");
	AMateria*	m1 = new Ice();
	AMateria*	m2 = new Cure();
	AMateria*	m3 = new Ice();
	AMateria*	m4 = new Cure();
	AMateria*	m5 = new Ice();

	packrat->equip(m1);
	packrat->equip(m2);
	packrat->equip(m3);
	packrat->equip(m4);
	packrat->equip(m5);
	packrat->printInventory();
	delete packrat;
	delete m5;
}

void	testSharedFloor()
{
	println("==== TEST 6: SHARED FLOOR ====");
	println("==============================");
	Floor*		sharedFloor = new Floor();
	Character*	alice = new Character("Alice", sharedFloor);
	Character*	bob = new Character("Bob", sharedFloor);
	AMateria*	ice = new Ice();
	AMateria*	cure = new Cure();

	alice->equip(ice);
	bob->equip(cure);
	alice->unequip(0);
	bob->unequip(0);
	sharedFloor->printFloor();
	alice->pickUp(1);
	bob->pickUp(0);
	alice->printInventory();
	bob->printInventory();
	sharedFloor->printFloor();
	delete alice;
	delete bob;
	delete sharedFloor;
}

void	testInvalidOps()
{
	println("==== TEST 7: INVALID OPERATIONS ====");
	println("====================================");
	Character*	test = new Character("Test");

	test->equip(NULL);
	test->use(5, *test);
	test->unequip(10);
	test->pickUp(100);
	test->pickUp("fire");
	test->unequip(0);
	delete test;
}

int	main()
{
	testSubjectExample();
	testDeepCopyCharacter();
	testFloor();
	testMateriaSource();
	testFullInventory();
	testSharedFloor();
	testInvalidOps();
	return (EXIT_SUCCESS);
}
