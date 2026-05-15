#include <iostream>
#include <cstdlib>
#include <ctime>
#include <typeinfo>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

// source of documentation: cppreference[.]com
// -------------------------------------------

// Returns a pseudo-random integral value from the range [0, RAND_MAX].
//
// std::srand() seeds the pseudo-random number generator used by rand(). 
//
// If rand() is used before any calls to std::srand(), 
// rand() behaves as if it was seeded with std::srand(1).
//
// Each time rand() is seeded with std::srand(), it must produce 
// the same sequence of values on successive calls.
//
// int rand();

Base* generate(void)
{
	int random = std::rand() % 3;
	
	if (random == 0)
	{
		std::cout << "Generated: A" << std::endl;
		return new A();
	}
	else if (random == 1)
	{
		std::cout << "Generated: B" << std::endl;
		return new B();
	}
	else
	{
		std::cout << "Generated: C" << std::endl;
		return new C();
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown type" << std::endl;
}

void identify(Base& p)
{
	try
	{
		A& a = dynamic_cast<A&>(p);
		(void) a;
		std::cout << "A" << std::endl;
	}
	catch (std::bad_cast& e)
	{
		try
		{
			B& b = dynamic_cast<B&>(p);
			(void) b;
			std::cout << "B" << std::endl;
		}
		catch (std::bad_cast& e)
		{
			try
			{
				C& c = dynamic_cast<C&>(p);
				(void) c;
				std::cout << "C" << std::endl;
			}
			catch (std::bad_cast& e)
			{
				std::cout << "Unknown type" << std::endl;
			}
		}
	}
}

void runSingleTest(Base* ptr)
{
	std::cout << "identify(Base* p):   ";
	identify(ptr);
	std::cout << "identify(Base& p):   ";
	identify(*ptr);
	std::cout << std::endl;
}

// Arithmetic type capable of representing times.
//
// Although not defined, this is almost always an integral value 
// holding the number of seconds (not counting leap seconds) since 
// 00:00, Jan 1 1970 UTC, corresponding to POSIX time.
//
// typedef /* unspecified */ time_t;

// Returns the current calendar time encoded as a std::time_t object, 
// and also stores it in the object pointed to by arg, 
// unless arg is a null pointer.
//
// std::time_t time( std::time_t* arg );

// Seeds the pseudo-random number generator used by std::rand() 
// with the value seed.
//
// If std::rand() is used before any calls to srand(), std::rand() 
// behaves as if it was seeded with srand(1).
//
// Each time std::rand() is seeded with the same seed, it must 
// produce the same sequence of values.
//
// void srand( unsigned seed );

// A pseudorandom number generator is not truly random, 
// it's a deterministic algorithm that produces a sequence of numbers 
// that appear random. 
//
// The algorithm is essentially a mathematical function that takes a number 
// (the current "state") and transforms it into the next number in the sequence.
//
// The seed is the initial starting point (initial state) of this sequence.

int main(void)
{
	int numTests = 10;
	int i = 0;

	std::cout << "========== TESTING RANDOM GENERATION ==========" << std::endl;
	std::cout << "\nGenerating " << numTests << " random objects:" << std::endl;
	std::cout << "----------------------------------------" << std::endl;

	std::srand(static_cast<unsigned int>(std::time(NULL)));
	while (i < numTests)
	{
		Base* obj = generate();
		std::cout << "Type identified: ";
		identify(obj);
		std::cout << std::endl;
		delete obj;
		i ++;
	}
	std::cout << "\n========== TESTING WITH KNOWN OBJECTS ==========" << std::endl;
	std::cout << "\nTesting A object:" << std::endl;

	A aObj;
	Base* basePtr = &aObj;
	runSingleTest(basePtr);

	std::cout << "Testing B object:" << std::endl;

	B bObj;
	basePtr = &bObj;
	runSingleTest(basePtr);

	std::cout << "Testing C object:" << std::endl;

	C cObj;
	basePtr = &cObj;
	runSingleTest(basePtr);

	std::cout << "\n========== TESTING CONSISTENCY ==========" << std::endl;
	std::cout << "\nGenerating 5 objects and verifying both identification methods:" << std::endl;
	std::cout << "--------------------------------------------------------------" << std::endl;

	i = 0;
	while (i < 5)
	{
		Base* obj = generate();
		std::cout << "Pointer identification:   ";
		identify(obj);
		std::cout << "Reference identification: ";
		identify(*obj);
		delete obj;
		std::cout << std::endl;
		i ++;
	}

	std::cout << "\n========== TESTING MEMORY MANAGEMENT ==========" << std::endl << std::endl;

	Base* dynamicObj = generate();
	std::cout << "Created dynamic object of type: ";
	identify(dynamicObj);
	delete dynamicObj;
	std::cout << "Object deleted successfully" << std::endl;

	std::cout << "\n========== ALL TESTS COMPLETED ==========" << std::endl;
	return 0;
}
