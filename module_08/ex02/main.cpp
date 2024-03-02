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
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
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
	std::list<int>::iterator itL = myList.begin();
	std::list<int>::iterator iteL = myList.end();
	++itL;
	--itL;
	while (itL != iteL)
	{
		std::cout << *itL << std::endl;
		++itL;
	}

	return 0;
}
