#include "Span.hpp"

#include <iostream>
#include <limits>
#include <vector>
#include <list>
#include <set>

#define RED "\033[31m"
#define BLUE_BOLD "\033[1;34m"
#define RESET "\033[0m"

#define LARGE_NUMBER 1000000

int main(void)
{
	try
	{
		Span sp = Span(14);
		
		// adding from set
		std::cout << BLUE_BOLD << "Adding from set:" << RESET << std::endl;
		std::set<int> mySet{ -22, -22 };
		sp.addNumbers<std::set<int> >(mySet.begin(), mySet.end());
		std::cout << sp << std::endl;
		// span check: should throw error (uncomment)
		/* std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl; */
		// adding from array
		std::cout << BLUE_BOLD << "Adding from array:" << RESET << std::endl;
		std::set<int> myArr{ 6, 3, 17, 9, 11 };
		sp.addNumbers<std::set<int> >(myArr.begin(), myArr.end());
		std::cout << sp << std::endl;
		// adding from list
		std::cout << BLUE_BOLD << "Adding from list:" << RESET << std::endl;
		std::list<int> lst{ 17, 9, 11 };
		sp.addNumbers<std::list<int> >(lst.begin(), lst.end());
		std::cout << sp << std::endl;
		// adding from vector
		std::cout << BLUE_BOLD << "Adding from vector:" << RESET << std::endl;
		std::vector<int> vect{ 0, 0, 0 };
		sp.addNumbers<std::vector<int> >(vect.begin(), vect.end());
		std::cout << sp << std::endl;

		// adding INT_MAX and INT_MIN
		std::cout << BLUE_BOLD << "Adding INT_MAX and INT_MIN:" << RESET << std::endl;
		sp.addNumber(std::numeric_limits<int>::max());
		sp.addNumber(std::numeric_limits<int>::min());
		std::cout << sp << std::endl;

		// testing shortest/longest span
		std::cout << BLUE_BOLD << "Testing shortest/longest span:" << RESET << std::endl;
		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

		// OverCapacityException check
		std::cout << BLUE_BOLD << "Adding over capacity:" << RESET << std::endl;
		sp.addNumber(42);
	}
	catch(const std::exception& e) 
	{
		std::cerr << RED << e.what() << RESET << '\n';
	}
	try
	{
		Span sp = Span(LARGE_NUMBER);
		
		std::cout << BLUE_BOLD << "Adding " << LARGE_NUMBER<< " numbers:" << RESET << std::endl;
		for (unsigned int i = 0; i < LARGE_NUMBER; i++)
		{
			sp.addNumber(i);
		}
		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e) 
	{
		std::cerr << RED << e.what() << RESET << '\n';
	}
	return 0;
}
