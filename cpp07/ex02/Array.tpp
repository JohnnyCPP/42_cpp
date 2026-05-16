#ifndef ARRAY_TPP
# define ARRAY_TPP

# include "Array.hpp"

template <typename T>
Array<T>::Array() : elements(NULL), e_size(0)
{}

template <typename T>
Array<T>::Array(unsigned int n) : elements(new T[n]()), e_size(n)
{}

template <typename T>
Array<T>::Array(Array const& that) : elements(NULL), e_size(0)
{
	if (that.e_size > 0)
	{
		elements = new T[that.e_size]();
		e_size = that.e_size;
		size_t i = 0;
		while (i < e_size)
		{
			elements[i] = that.elements[i];
			i ++;
		}
	}
}

template <typename T>
Array<T>::~Array(void)
{
	if (elements)
		delete[] elements;
}

template <typename T>
Array<T>& Array<T>::operator=(Array const& that)
{
	if (this != &that)
	{
		if (elements)
			delete[] elements;
		elements = NULL;
		e_size = 0;
		if (that.e_size > 0)
		{
			elements = new T[that.e_size]();
			e_size = that.e_size;
			size_t i = 0;
			while (i < e_size)
			{
				elements[i] = that.elements[i];
				i ++;
			}
		}
	}
	return *this;
}

template <typename T>
T& Array<T>::operator[](size_t index)
{
	if (index >= e_size)
		throw std::exception();
	return elements[index];
}

template <typename T>
T const& Array<T>::operator[](size_t index) const
{
	if (index >= e_size)
		throw std::exception();
	return elements[index];
}

template <typename T>
size_t Array<T>::size(void) const
{
	return e_size;
}

#endif
