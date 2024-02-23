#include "iter.hpp"
#include <iostream>

template <typename T>
void printArg(T const &arg)
{
	std::cout << arg << " ";
}

template <typename T>
void doubleNum(T &num)
{
	num *= 2;
}

int main(void)
{
	int arr[] = {1,2,3,4,5};
	iter(arr, 5, &printArg<int>);
	std::cout << std::endl;
	iter(arr, 5, &doubleNum<int>);
	iter(arr, 5, &printArg<int>);
	std::cout << std::endl;

	double arrD[] = {0.1,0.2,0.3,0.4,0.5};
	iter(arrD, 5, &printArg<double>);
	std::cout << std::endl;
	iter(arrD, 5, &doubleNum<double>);
	iter(arrD, 5, &printArg<double>);
	std::cout << std::endl;
	return 0;
}
