#include "MutantStack.hpp"
#include <iostream>
#include <list>

int	main()
{
	MutantStack<int>			mstack;
	MutantStack<int>::iterator	it;
	MutantStack<int>::iterator	ite;
	std::list<int>				lst;
	std::list<int>::iterator	lit;
	std::list<int>::iterator	lite;

	std::cout << "define mutant stack mstack..." << std::endl << std::endl;
	mstack.push(5);
	mstack.push(17);
	mstack.pop();
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	std::cout << "top: " << mstack.top() << std::endl;
	std::cout << "size: " << mstack.size() << std::endl;
	it = mstack.begin();
	ite = mstack.end();
	++ it;
	-- it;
	std::cout << "contents of mutant stack: ";
	while (it != ite)
	{
		std::cout << *it << " ";
		++ it;
	}
	std::cout << std::endl << std::endl;
	std::stack<int> s(mstack);
	std::cout << "comparing mutant stack with std::list..." << std::endl << std::endl;
	lst.push_back(5);
	lst.push_back(17);
	lst.pop_back();
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);
	lit = lst.begin();
	lite = lst.end();
	++ lit;
	-- lit;
	std::cout << "contents of std::list: ";
	while (lit != lite)
	{
		std::cout << *lit << " ";
		++ lit;
	}
	std::cout << std::endl;
	return (0);
}
