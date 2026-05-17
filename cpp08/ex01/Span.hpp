#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <stdexcept>

class Span
{
	private:

		unsigned int maxN;
		std::vector<int> numbers;
		
	public:

		Span();
		Span(unsigned int n);
		Span(Span const& that);
		~Span();
		
		Span& operator=(Span const& that);
		
		void addNumber(int n);
		void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		int shortestSpan(void) const;
		int longestSpan(void) const;
};

#endif
