#include <iostream>
#include "iter.hpp"

template <typename T>
void print(T const& x)
{
	std::cout << x << std::endl;
}

template <typename T>
void increment(T& x)
{
	x = x + 1;
}

int main(void)
{
	int arr[] = {1, 2, 3, 4, 5};
	size_t length = 5;

	std::cout << "define arr = 1 2 3 4 5, define length = 5" << std::endl;
	std::cout << std::endl;

	::iter(arr, length, print<int>);
	::iter(arr, length, increment<int>);

	std::cout << "After increment:" << std::endl;
	std::cout << std::endl;

	::iter(arr, length, print<int>);

	std::string strArr[] = {"hello", "world", "42"};
	size_t strLen = 3;
	std::cout << "define strArr = hello world 42, define strLen = 3" << std::endl;
	std::cout << std::endl;

	::iter(strArr, strLen, print<std::string>);

	return 0;
}
