#include <iostream>
#include "Span.hpp"
#include <limits>
#include <vector>

int main(void)
{
	try
	{
		Span sp = Span(10);
		sp.addNumber(6);
		std::cout << sp << std::endl;
		sp.addNumber(3);
		std::cout << sp << std::endl;
		sp.addNumber(17);
		std::cout << sp << std::endl;
		sp.addNumber(9);
		std::cout << sp << std::endl;
		sp.addNumber(11);
		std::cout << sp << std::endl;
		sp.addNumber(0);
		std::cout << sp << std::endl;
		sp.addNumber(0);
		std::cout << sp << std::endl;
		sp.addNumber(std::numeric_limits<int>::max());
		std::cout << sp << std::endl;
		sp.addNumber(std::numeric_limits<int>::min());
		std::cout << sp << std::endl;
		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

		std::vector<int> range = {1, 2, 3};
		sp.addNumber<std::vector<int> >(range.begin(), range.end());
		std::cout << sp << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
