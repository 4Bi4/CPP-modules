#include <iostream>
#include <sstream>
#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &other) : _stack(other._stack) {}

RPN &RPN::operator=(const RPN &other)
{
	if (this == &other)
		return (*this);
	_stack = other._stack;
	return (*this);
}

RPN::~RPN() {}

bool RPN::evaluate(const std::string &expr, int &result) const
{
	std::stack<int> stack;
	std::istringstream iss(expr);
	std::string token;

	while (iss >> token)
	{
		if (token.size() == 1 && token[0] >= '0' && token[0] <= '9')
			stack.push(token[0] - '0');
		else if (token == "+" || token == "-" || token == "*" || token == "/")
		{
			if (stack.size() < 2)
			{
				std::cerr << "Error" << std::endl;
				return (false);
			}
			int b = stack.top();
			stack.pop();
			int a = stack.top();
			stack.pop();

			if (token == "+" )
				stack.push(a + b);
			else if (token == "-")
				stack.push(a - b);
			else if (token == "*")
				stack.push(a * b);
			else
			{
				if (b == 0)
				{
					std::cerr << "Error" << std::endl;
					return (false);
				}
				stack.push(a / b);
			}
		}
		else
		{
			std::cerr << "Error" << std::endl;
			return (false);
		}
	}

	if (stack.size() != 1)
	{
		std::cerr << "Error" << std::endl;
		return (false);
	}
	result = stack.top();
	return (true);
}
