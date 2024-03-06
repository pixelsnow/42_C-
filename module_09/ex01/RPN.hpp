#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>

class RPN
{
private:
public:
	RPN();
	RPN(const RPN & source);
	~RPN();

	RPN & operator=(RPN const & source);

	void calculate(std::string const & expression) const;
};

#endif
