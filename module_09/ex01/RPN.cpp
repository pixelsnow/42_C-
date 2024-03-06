#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN & source)
{
	(void)source;
}

RPN::~RPN() {}

RPN & RPN::operator=(RPN const & source)
{
	(void)source;
	return *this;
}

bool RPN::isOperator(char c) const
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return true;
	return false;
}

void RPN::calculate(std::string const & expression) const
{
	std::istringstream iss(expression);
	std::string token;

	while (std::getline(iss, token, ' '))
	{
		if (token.length() != 1)
		{
			std::cout << "Error" << std::endl;
			return;
		}
		if (this->isOperator(token[0]))
			std::cout << "operator: ";
		std::cout << token << std::endl;
	}
}
