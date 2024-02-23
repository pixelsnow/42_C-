#include <iostream>
#include "Array.hpp"

#define SIZE 5

int main(void)
{
	Array<int> numbers(SIZE);
	std::cout << "numbers: " <<  &numbers << std::endl;
	int* mirror = new int[SIZE];
	std::cout << "mirror: " << &mirror << std::endl;
	srand(time(NULL));
	for (unsigned int i = 0; i < SIZE; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	for (unsigned int i = 0; i < SIZE; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}

	for (unsigned int i = 0; i < numbers.size(); i++)
	{
		std::cout << numbers[i] << " ";
	}
	std::cout << std::endl;

	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[SIZE] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < SIZE; i++)
	{
		numbers[i] = rand();
	}
	{
		std::cout << "before" << std::endl;
		Array<int> tmp = numbers;
		std::cout << "between" << std::endl;
		Array<int> test(numbers);
	}
	delete[] mirror;
	return 0;
}
