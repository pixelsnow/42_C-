#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>

class RPN
{
private:
public:
	RPN();
	RPN(const RPN & source);
	~RPN();

	RPN & operator=(RPN const & source);

	void calculate(const std::string &expression) const;
};

#endif
