#include "RPN.hpp"
#include <iostream>

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Wrong number of arguments" << std::endl;
		return 1;
	}

	RPN rpn;
	rpn.calculate(av[1]);
	return 0;
}
