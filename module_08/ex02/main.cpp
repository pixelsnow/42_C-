#include "MutantStack.hpp"

#include <iostream>
#include <list>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE_BOLD "\033[1;34m"
#define RESET "\033[0m"

int main()
{
	std::cout << BLUE_BOLD << "\nMUTANT STACK TEST\n" << RESET << std::endl;

	MutantStack<int> myStack;
	myStack.push(5);
	myStack.push(17);
	std::cout << "Top: " << myStack.top() << std::endl;
	myStack.pop();
	std::cout << "Top: " << myStack.top() << std::endl;
	std::cout << "Size: " << myStack.size() << std::endl;
	myStack.push(3);
	myStack.push(5);
	myStack.push(737);
	myStack.push(0);

	std::cout << RED << "copyStack created using copy constructor:" << RESET << std::endl;
	MutantStack<int> copyStack(myStack);
	MutantStack<int>::iterator copyIt = copyStack.begin();
	MutantStack<int>::iterator copyIte = copyStack.end();
	while (copyIt != copyIte)
	{
		std::cout << *copyIt << std::endl;
		++copyIt;
	}

	std::cout << RED << "assignStack copied using = :" << RESET << std::endl;
	MutantStack<int> assignStack;
	assignStack = myStack;
	MutantStack<int>::iterator assignIt = copyStack.begin();
	MutantStack<int>::iterator assignIte = copyStack.end();
	while (assignIt != assignIte)
	{
		std::cout << *assignIt << std::endl;
		++assignIt;
	}

	std::cout << GREEN << "::iterator:" << RESET << std::endl;
	MutantStack<int>::iterator it = myStack.begin();
	MutantStack<int>::iterator ite = myStack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << GREEN << "::const_iterator:" << RESET << std::endl;
	MutantStack<int>::const_iterator cit = myStack.cbegin();
	MutantStack<int>::const_iterator cite = myStack.cend();
	++cit;
	--cit;
	while (cit != cite)
	{
		std::cout << *cit << std::endl;
		++cit;
	}
	std::cout << GREEN << "::reverse_iterator:" << RESET << std::endl;
	MutantStack<int>::reverse_iterator rit = myStack.rbegin();
	MutantStack<int>::reverse_iterator rite = myStack.rend();
	++rit;
	--rit;
	while (rit != rite)
	{
		std::cout << *rit << std::endl;
		++rit;
	}
	std::cout << GREEN << "::const_reverse_iterator:" << RESET << std::endl;
	MutantStack<int>::const_reverse_iterator crit = myStack.rbegin();
	MutantStack<int>::const_reverse_iterator crite = myStack.rend();
	++crit;
	--crit;
	while (crit != crite)
	{
		std::cout << *crit << std::endl;
		++crit;
	}

	std::stack<int> s(myStack);

	std::cout << BLUE_BOLD << "\nLIST TEST\n" << RESET << std::endl;

	std::list<int> myList;
	myList.push_back(5);
	myList.push_back(17);
	std::cout << "Top: " << myList.back() << std::endl;
	myList.pop_back();
	std::cout << "Top: " << myList.back() << std::endl;
	std::cout << "Size: " << myList.size() << std::endl;
	myList.push_back(3);
	myList.push_back(5);
	myList.push_back(737);
	myList.push_back(0);

	std::cout << GREEN << "::iterator:" << RESET << std::endl;
	std::list<int>::iterator itL = myList.begin();
	std::list<int>::iterator iteL = myList.end();
	++itL;
	--itL;
	while (itL != iteL)
	{
		std::cout << *itL << std::endl;
		++itL;
	}
	std::cout << GREEN << "::const_iterator:" << RESET << std::endl;
	std::list<int>::const_iterator citL = myList.cbegin();
	std::list<int>::const_iterator citeL = myList.cend();
	++citL;
	--citL;
	while (citL != citeL)
	{
		std::cout << *citL << std::endl;
		++citL;
	}
	std::cout << GREEN << "::reverse_iterator:" << RESET << std::endl;
	std::list<int>::reverse_iterator ritL = myList.rbegin();
	std::list<int>::reverse_iterator riteL = myList.rend();
	++ritL;
	--ritL;
	while (ritL != riteL)
	{
		std::cout << *ritL << std::endl;
		++ritL;
	}
	std::cout << GREEN << "::const_reverse_iterator:" << RESET << std::endl;
	std::list<int>::const_reverse_iterator critL = myList.rbegin();
	std::list<int>::const_reverse_iterator criteL = myList.rend();
	++critL;
	--critL;
	while (critL != criteL)
	{
		std::cout << *critL << std::endl;
		++critL;
	}

	return 0;
}
