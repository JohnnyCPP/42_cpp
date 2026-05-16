#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>
# include <cstddef>

template <typename T>
class Array
{
	private:

		T* elements;
		size_t e_size;

	public:

		Array();
		Array(unsigned int n);
		Array(Array const& that);
		~Array();

		Array& operator=(Array const& that);
		T& operator[](size_t index);
		T const& operator[](size_t index) const;

		size_t size(void) const;
};

# include "Array.tpp"

#endif
