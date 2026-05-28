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
			throw RPNOperationException("Error: addition would overflow.");
		result = a + b;
	}
	else if (op == '-')
	{
		if (wouldOverflowSubtraction(a, b))
			throw RPNOperationException("Error: subtraction would overflow.");
		result = a - b;
	}
	else if (op == '*')
	{
		if (wouldOverflowMultiplication(a, b))
			throw RPNOperationException("Error: multiplication would overflow.");
		result = a * b;
	}
	else
	{
		if (b == 0.0)
			throw RPNOperationException("Error: division by zero.");
		if (wouldOverflowDivision(a, b))
			throw RPNOperationException("Error: division would overflow.");
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
			throw RPNOperationException("Error: negative numbers are not allowed.");
		if (isOperator(expression[i]))
		{
			if (stack.size() < 2)
				throw RPNOperationException("Error: insufficient operands.");
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
			throw RPNOperationException("Error: invalid token.");
	}
	if (stack.size() != 1)
		throw RPNOperationException("Error: invalid expression.");
	return (stack.top());
}
