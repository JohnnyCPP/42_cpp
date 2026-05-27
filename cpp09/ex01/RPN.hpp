#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <string>
# include <iostream>
# include <sstream>
# include <cstdlib>
# include <limits>
# include <cmath>

class RPN
{
	private:

		std::stack<double>	stack;
		bool	isOperator(char c) const;
		double	applyOperator(char op, double a, double b) const;


		bool	wouldOverflowAddition(double a, double b) const;
		bool	wouldOverflowSubtraction(double a, double b) const;
		bool	wouldOverflowMultiplication(double a, double b) const;
		bool	wouldOverflowDivision(double a, double b) const;

	public:

		RPN();
		RPN(RPN const& that);
		~RPN();
		RPN & operator=(RPN const& that);

		double	evaluate(std::string const& expression);
};

#endif
