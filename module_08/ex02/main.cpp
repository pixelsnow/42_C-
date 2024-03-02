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

	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "Top: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "Top: " << mstack.top() << std::endl;
	std::cout << "Size: " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	std::cout << GREEN << "::iterator:" << RESET << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << GREEN << "::const_iterator:" << RESET << std::endl;
	MutantStack<int>::const_iterator cit = mstack.cbegin();
	MutantStack<int>::const_iterator cite = mstack.cend();
	++cit;
	--cit;
	while (cit != cite)
	{
		std::cout << *cit << std::endl;
		++cit;
	}
	std::cout << GREEN << "::reverse_iterator:" << RESET << std::endl;
	MutantStack<int>::reverse_iterator rit = mstack.rbegin();
	MutantStack<int>::reverse_iterator rite = mstack.rend();
	++rit;
	--rit;
	while (rit != rite)
	{
		std::cout << *rit << std::endl;
		++rit;
	}
	std::cout << GREEN << "::const_reverse_iterator:" << RESET << std::endl;
	MutantStack<int>::const_reverse_iterator crit = mstack.rbegin();
	MutantStack<int>::const_reverse_iterator crite = mstack.rend();
	++crit;
	--crit;
	while (crit != crite)
	{
		std::cout << *crit << std::endl;
		++crit;
	}

	std::stack<int> s(mstack);

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
