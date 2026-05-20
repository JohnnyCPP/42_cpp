# include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(RPN const& that)
{
	*this = that;
}

RPN::~RPN()
{
}

RPN& RPN::operator=(RPN const& that)
{
	if (this != &that)
	{
		this->stack = that.stack;
	}
	return (*this);
}

bool	RPN::isOperator(char c) const
{
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

double	RPN::applyOperator(char op, double a, double b) const
{
	if (op == '+')
		return (a + b);
	if (op == '-')
		return (a - b);
	if (op == '*')
		return (a * b);
	if (op == '/')
	{
		if (b == 0)
		{
			std::cerr << "Error: division by zero" << std::endl;
			return (0);
		}
		return (a / b);
	}
	return (0);
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
		if (this->isOperator(expression[i]))
		{
			if (this->stack.size() < 2)
			{
				std::cerr << "Error: insufficient operands" << std::endl;
				return (0);
			}
			b = this->stack.top();
			this->stack.pop();
			a = this->stack.top();
			this->stack.pop();
			this->stack.push(this->applyOperator(expression[i], a, b));
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
			std::stringstream	ss(token);
			ss >> num;
			this->stack.push(num);
		}
		else
		{
			std::cerr << "Error: invalid token" << std::endl;
			return (0);
		}
	}
	if (this->stack.size() != 1)
	{
		std::cerr << "Error: invalid expression" << std::endl;
		return (0);
	}
	return (this->stack.top());
}
