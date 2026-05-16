#include <iostream>
#include "Array.hpp"

int main(void)
{
	Array<int> empty;
	std::cout << "Empty size: " << empty.size() << std::endl;

	Array<int> arr(5);
	std::cout << "Array size: " << arr.size() << std::endl;

	size_t i = 0;
	while (i < arr.size())
	{
		arr[i] = i * 10;
		i ++;
	}

	i = 0;
	while (i < arr.size())
	{
		std::cout << "arr[" << i << "] = " << arr[i] << std::endl;
		i ++;
	}

	Array<int> copy(arr);
	copy[0] = 999;
	std::cout << "Original[0]: " << arr[0] << std::endl;
	std::cout << "Copy[0]: " << copy[0] << std::endl;

	try
	{
		arr[10] = 42;
	}
	catch (std::exception& e)
	{
		std::cout << "Out of bounds caught" << std::endl;
	}

	Array<std::string> strings(3);
	strings[0] = "Hello";
	strings[1] = "World";
	strings[2] = "!";
	i = 0;
	while (i < strings.size())
	{
		std::cout << strings[i] << " ";
		i ++;
	}
	std::cout << std::endl;

	return 0;
}
