# include "RPN.hpp"

RPN::RPN() : stack()
{
}

RPN::RPN(RPN const& that) : stack(that.stack)
{
}

RPN::~RPN()
{
}

RPN& RPN::operator=(RPN const& that)
{
	if (this != &that)
		stack = that.stack;
	return (*this);
}

bool	RPN::isOperator(char c) const
{
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

bool	RPN::wouldOverflowAddition(double a, double b) const
{
	if (b > 0 && a > std::numeric_limits<double>::max() - b)
		return (true);
	if (b < 0 && a < -std::numeric_limits<double>::max() - b)
		return (true);
	return (false);
}

bool	RPN::wouldOverflowSubtraction(double a, double b) const
{
	if (b < 0 && a > std::numeric_limits<double>::max() + b)
		return (true);
	if (b > 0 && a < -std::numeric_limits<double>::max() + b)
		return (true);
	return (false);
}

bool	RPN::wouldOverflowMultiplication(double a, double b) const
{
	if (a == 0.0 || b == 0.0)
		return (false);
	if (a > 0.0 && b > 0.0)
	{
		if (a > std::numeric_limits<double>::max() / b)
			return (true);
	}
	else if (a < 0.0 && b < 0.0)
	{
		if (a < -std::numeric_limits<double>::max() / b)
			return (true);
	}
	else
	{
		if (a > 0.0 && b < 0.0)
		{
			if (b < -std::numeric_limits<double>::max() / a)
				return (true);
		}
		else if (a < 0.0 && b > 0.0)
		{
			if (a < -std::numeric_limits<double>::max() / b)
				return (true);
		}
	}
	return (false);
}

bool	RPN::wouldOverflowDivision(double a, double b) const
{
	if (b == 0.0)
		return (false);
	if (a == std::numeric_limits<double>::max() && b < 1.0 && b > 0.0)
		return (true);
	if (a == -std::numeric_limits<double>::max() && b > -1.0 && b < 0.0)
		return (true);
	return (false);
}

double	RPN::applyOperator(char op, double a, double b) const
{
	double	result;

	if (op == '+')
	{
		if (wouldOverflowAddition(a, b))
		{
			std::cerr << "Error: addition would overflow" << std::endl;
			return (0);
		}
		result = a + b;
	}
	else if (op == '-')
	{
		if (wouldOverflowSubtraction(a, b))
		{
			std::cerr << "Error: subtraction would overflow" << std::endl;
			return (0);
		}
		result = a - b;
	}
	else if (op == '*')
	{
		if (wouldOverflowMultiplication(a, b))
		{
			std::cerr << "Error: multiplication would overflow" << std::endl;
			return (0);
		}
		result = a * b;
	}
	else
	{
		if (b == 0.0)
		{
			std::cerr << "Error: division by zero" << std::endl;
			return (0);
		}
		if (wouldOverflowDivision(a, b))
		{
			std::cerr << "Error: division would overflow" << std::endl;
			return (0);
		}
		result = a / b;
	}
	return (result);
}

double	RPN::evaluate(std::string const& expression)
{
	std::string::size_type	i;
	std::string				token;
	double					num;
	double					a;
	double					b;
	
	i = 0;
	while (i < expression.size())
	{
		if (expression[i] == ' ')
		{
			i ++;
			continue ;
		}
		if (expression[i] == '-' && i + 1 < expression.size() && isdigit(expression[i + 1]))
		{
			std::cerr << "Error: negative numbers are not allowed" << std::endl;
			return (0);
		}
		if (isOperator(expression[i]))
		{
			if (stack.size() < 2)
			{
				std::cerr << "Error: insufficient operands" << std::endl;
				return (0);
			}
			b = stack.top();
			stack.pop();
			a = stack.top();
			stack.pop();
			stack.push(applyOperator(expression[i], a, b));
			i ++;
		}
		else if (isdigit(expression[i]) || (expression[i] == '-' && i + 1 < expression.size() && isdigit(expression[i + 1])))
		{
			token.clear();
			while (i < expression.size() && expression[i] != ' ')
			{
				token += expression[i];
				i ++;
			}
			std::stringstream	stream(token);
			stream >> num;
			stack.push(num);
		}
		else
		{
			std::cerr << "Error: invalid token" << std::endl;
			return (0);
		}
	}
	if (stack.size() != 1)
	{
		std::cerr << "Error: invalid expression" << std::endl;
		return (0);
	}
	return (stack.top());
}
