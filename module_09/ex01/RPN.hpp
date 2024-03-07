#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <limits>

class RPN
{
private:
	bool isOperator(char c) const;
	void displayError() const;
	int addNumbers(int a, int b) const;
	int subtractNumbers(int a, int b) const;
	int multiplyNumbers(int a, int b) const;
	int divideNumbers(int a, int b) const;
	int performOperation(char oper, int num1, int num2) const;
public:
	RPN();
	RPN(const RPN & source);
	~RPN();

	RPN & operator=(RPN const & source);

	void calculate(std::string const & expression) const;

	class OverflowException : std::exception
	{
	public:
		virtual const char * what() const throw();
	};
};

#endif
