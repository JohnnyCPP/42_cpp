#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>
#include <cstdlib>

void	printhead(const std::string& str)
{
	std::cout << "==== " << str << " ====" << std::endl;
	std::cout << std::endl;
}

void	testBasic()
{
	printhead("Test 1: Basic");
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();

	std::cout << j->getType() << std::endl;
	std::cout << i->getType() << std::endl;
	j->makeSound();
	i->makeSound();
	delete j;
	delete i;
}

void	testArray()
{
	printhead("Test 2: Array");
	const int arraySize = 6;
	AAnimal* animals[arraySize];

	for (int i = 0; i < arraySize; i++)
	{
		if (i < arraySize / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	std::cout << "\nMaking sounds:\n";
	for (int i = 0; i < arraySize; i++)
	{
		std::cout << animals[i]->getType() << ": ";
		animals[i]->makeSound();
	}
	std::cout << "\nDeleting animals:\n";
	for (int i = 0; i < arraySize; i++)
		delete animals[i];
}

void	testCopyDog()
{
	printhead("Test 3: Copy Dog");
	Dog originalDog;

	originalDog.setIdea(0, "I want a bone");
	originalDog.setIdea(1, "I love my human");
	Dog copiedDog(originalDog);
	std::cout << "Original idea 0: " << originalDog.getIdea(0) << std::endl;
	std::cout << "Copied idea 0: " << copiedDog.getIdea(0) << std::endl;
	copiedDog.setIdea(0, "I want a different bone");
	std::cout << "After modification:" << std::endl;
	std::cout << "Original idea 0: " << originalDog.getIdea(0) << std::endl;
	std::cout << "Copied idea 0: " << copiedDog.getIdea(0) << std::endl;
	std::cout << "\nIdea 1 should still be the same:" << std::endl;
	std::cout << "Original idea 1: " << originalDog.getIdea(1) << std::endl;
	std::cout << "Copied idea 1: " << copiedDog.getIdea(1) << std::endl;
}

void	testCopyCat()
{
	printhead("Test 4: Copy Cat");
	Cat originalCat;

	originalCat.setIdea(0, "I want fish");
	originalCat.setIdea(1, "Time for a nap");
	Cat copiedCat = originalCat;
	std::cout << "Original idea 0: " << originalCat.getIdea(0) << std::endl;
	std::cout << "Copied idea 0: " << copiedCat.getIdea(0) << std::endl;
	copiedCat.setIdea(0, "I want chicken instead");
	std::cout << "After modification:" << std::endl;
	std::cout << "Original idea 0: " << originalCat.getIdea(0) << std::endl;
	std::cout << "Copied idea 0: " << copiedCat.getIdea(0) << std::endl;
}

void	testAssignment()
{
	printhead("Test 5: Assignment");
	Dog dog1;

	dog1.setIdea(0, "Dog1's first idea");
	Dog dog2;
	dog2.setIdea(0, "Dog2's different idea");
	std::cout << "Before assignment:" << std::endl;
	std::cout << "Dog1 idea 0: " << dog1.getIdea(0) << std::endl;
	std::cout << "Dog2 idea 0: " << dog2.getIdea(0) << std::endl;
	dog2 = dog1;
	std::cout << "After assignment:" << std::endl;
	std::cout << "Dog1 idea 0: " << dog1.getIdea(0) << std::endl;
	std::cout << "Dog2 idea 0: " << dog2.getIdea(0) << std::endl;
	dog2.setIdea(0, "Modified after assignment");
	std::cout << "After modifying dog2:" << std::endl;
	std::cout << "Dog1 idea 0: " << dog1.getIdea(0) << std::endl;
	std::cout << "Dog2 idea 0: " << dog2.getIdea(0) << std::endl;
}

void	testSelfAssignment()
{
	printhead("Test 6: Self Assignment");
	Cat cat;

	cat.setIdea(0, "Self assignment test");
	cat = cat;
	std::cout << "Cat idea 0 after self assignment: " << cat.getIdea(0) << std::endl;
}

void	testMemory()
{
	printhead("Test 7: Memory");
	const int count = 10;
	AAnimal* animals[count];

	for (int i = 0; i < count; i++)
	{
		if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	for (int i = 0; i < count; i++)
		delete animals[i];
}

int	main()
{
	testBasic();
	testArray();
	testCopyDog();
	testCopyCat();
	testAssignment();
	testSelfAssignment();
	testMemory();
	return (EXIT_SUCCESS);
}
