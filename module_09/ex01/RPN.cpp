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

void RPN::calculate(std::string const & expression) const
{
	std::istringstream iss(expression);
	std::string token;

	while (std::getline(iss, token, ' '))
	{
		std::cout << token << std::endl;
	}
}
