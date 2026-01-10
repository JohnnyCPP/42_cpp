#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>
#include <cstdlib>

void	printhead(const std::string& str)
{
	std::cout << "==== " << str << " ====" << std::endl;
	std::cout << std::endl;
}

void	testBasicPoly() 
{
	printhead("Test 1: Basic Polymorphism");
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete j;
	delete i;
}

void	testWrongPoly()
{
	printhead("Test 2: Wrong Polymorphism");
	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();

	std::cout << wrongMeta->getType() << " " << std::endl;
	std::cout << wrongCat->getType() << " " << std::endl;
	wrongMeta->makeSound();
	wrongCat->makeSound();
	delete wrongMeta;
	delete wrongCat;
}

void	testArray()
{
	printhead("Test 3: Array");
	const Animal* animals[4];
	animals[0] = new Dog();
	animals[1] = new Cat();
	animals[2] = new Dog();
	animals[3] = new Cat();

	for (int i = 0; i < 4; i++)
	{
		std::cout << animals[i]->getType() << ": ";
		animals[i]->makeSound();
	}
	for (int i = 0; i < 4; i++)
		delete animals[i];
}

void	testCopyAndAssign()
{
	printhead("Test 4: Copy And Assign");
	Dog originalDog;
	Dog copiedDog(originalDog);
	Cat originalCat;
	Cat assignedCat = originalCat;

	originalDog.makeSound();
	copiedDog.makeSound();
	originalCat.makeSound();
	assignedCat.makeSound();
}

void	testRegularStack()
{
	printhead("Test 5: Regular Stack");
	Animal animal;
	Dog dog;
	Cat cat;

	std::cout << animal.getType() << ": ";
	animal.makeSound();
	std::cout << dog.getType() << ": ";
	dog.makeSound();
	std::cout << cat.getType() << ": ";
	cat.makeSound();
}

// when creating a Direct Object, the compiler 
// knows the exact type at compile time
//
// in this case, it knows it's WrongCat, 
// and it calls WrongCat::makeSound()
void	testWrongStack()
{
	printhead("Test 6: Wrong Stack");
	WrongAnimal wrongAnimal;
	WrongCat wrongCat;

	std::cout << wrongAnimal.getType() << ": ";
	wrongAnimal.makeSound();
	std::cout << wrongCat.getType() << ": ";
	wrongCat.makeSound();
}

void	testMemory()
{
	printhead("Test 7: Memory");
	Animal* animals[10];

	for (int i = 0; i < 10; i++)
	{
		if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	for (int i = 0; i < 10; i++)
		animals[i]->makeSound();
	for (int i = 0; i < 10; i++)
		delete animals[i];
}

int	main()
{
	testBasicPoly();
	testWrongPoly();
	testArray();
	testCopyAndAssign();
	testRegularStack();
	testWrongStack();
	testMemory();
	return (EXIT_SUCCESS);
}
