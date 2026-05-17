#include "Span.hpp"
#include <algorithm>
#include <climits>

Span::Span() : maxN(0)
{}

Span::Span(unsigned int n) : maxN(n)
{}

Span::Span(Span const& that) : maxN(that.maxN), numbers(that.numbers)
{}

Span::~Span()
{}

Span&	Span::operator=(Span const& that)
{
	if (this != &that)
	{
		maxN = that.maxN;
		numbers = that.numbers;
	}
	return (*this);
}

void	Span::addNumber(int n)
{
	if (numbers.size() >= maxN)
		throw std::runtime_error("Span is full");
	numbers.push_back(n);
}

void	Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	std::vector<int>::iterator	it;
	unsigned int				count;
	
	it = begin;
	count = 0;
	while (it != end)
	{
		count ++;
		it ++;
	}
	if (numbers.size() + count > maxN)
		throw std::runtime_error("Not enough space");
	it = begin;
	while (it != end)
	{
		numbers.push_back(*it);
		it ++;
	}
}

int	Span::shortestSpan(void) const
{
	std::vector<int>::const_iterator	it;
	std::vector<int>::const_iterator	next;
	std::vector<int>					sorted;
	int									minSpan;
	int									span;

	if (numbers.size() < 2)
		throw std::runtime_error("Not enough numbers");
	sorted = numbers;
	std::sort(sorted.begin(), sorted.end());
	minSpan = INT_MAX;
	it = sorted.begin();
	next = it;
	next ++;
	while (next != sorted.end())
	{
		span = *next - *it;
		if (span < minSpan)
			minSpan = span;
		it ++;
		next ++;
	}
	return (minSpan);
}

int	Span::longestSpan(void) const
{
	std::vector<int>::const_iterator	it;
	int									minVal;
	int									maxVal;

	if (numbers.size() < 2)
		throw std::runtime_error("Not enough numbers");
	minVal = *numbers.begin();
	maxVal = *numbers.begin();
	it = numbers.begin();
	while (it != numbers.end())
	{
		if (*it < minVal)
			minVal = *it;
		if (*it > maxVal)
			maxVal = *it;
		it ++;
	}
	return (maxVal - minVal);
}
