#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <limits>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

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

	class OverflowException : public std::exception
	{
	public:
		virtual const char * what() const throw();
	};

	class UndefinedException : public std::exception
	{
	public:
		virtual const char * what() const throw();
	};
};

#endif
