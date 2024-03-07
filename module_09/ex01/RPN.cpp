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

void RPN::displayError() const
{
	std::cerr << "Error" << std::endl;
}

int RPN::addNumbers(int a, int b) const
{
	if (a > 0 && b > std::numeric_limits<int>::max() - a)
		throw OverflowException();
	if (a < 0 && b < std::numeric_limits<int>::min() - a)
		throw OverflowException();
	return (a + b);
}

int RPN::subtractNumbers(int a, int b) const
{
	// if it's actually addition and we're going over max
	if (b < 0 && a > std::numeric_limits<int>::max() + b)
		throw OverflowException();
	// if it's subtraction and we're going under min
	if (b > 0 && a < std::numeric_limits<int>::min() + b)
		throw OverflowException();
	return (a - b);
}

int RPN::multiplyNumbers(int a, int b) const
{
	// avoiding INT_MIN * (-1) situation
	if ((a == std::numeric_limits<int>::min() && b == -1)
		|| (b == std::numeric_limits<int>::min() && a == -1))
		throw OverflowException();
	if (a != 0 && b > std::numeric_limits<int>::max() / a)
		throw OverflowException();
	if (a != 0 && b < std::numeric_limits<int>::min() / a)
		throw OverflowException();
	return (a * b);
}

int RPN::divideNumbers(int a, int b) const
{
	// avoiding INT_MIN / (-1) situation
	if (a == std::numeric_limits<int>::min() && b == -1)
		throw OverflowException();
	// Division by 0 is undefined
	if (b == 0)
		throw UndefinedException();
	return (a / b);
}

int RPN::performOperation(char oper, int num1, int num2) const
{
	switch (oper)
	{
		case '+':
			return addNumbers(num1, num2);
		case '-':
			return subtractNumbers(num1, num2);
		case '*':
			return multiplyNumbers(num1, num2);
		default:
			return divideNumbers(num1, num2);
	}
}

void RPN::calculate(std::string const & expression) const
{
	std::istringstream iss(expression);
	std::string token;
	std::stack<int> st;

	while (std::getline(iss, token, ' '))
	{
		if (token.length() != 1)
		{
			return displayError();
		}
		if (std::isdigit(token[0]))
		{
			st.push(token[0] - '0');
		}
		else if (isOperator(token[0]))
		{
			if (st.size() < 2)
			{
				return displayError();
			}
			int num2 = st.top();
			st.pop();
			int num1 = st.top();
			st.pop();
			try
			{
				int res = performOperation(token[0], num1, num2);
				st.push(res);
			}
			catch(const std::exception & e)
			{
				return displayError();
			}
		}
	}
	if (st.size() != 1)
	{
		return displayError();
	}
	std::cout << st.top() << std::endl;
}

const char * RPN::OverflowException::what() const throw()
{
	return "overflow";
}

const char * RPN::UndefinedException::what() const throw()
{
	return "result of this operation is undefined";
}
