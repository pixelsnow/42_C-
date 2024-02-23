#include <iostream>
#include "Array.hpp"

#define MAX_VAL 5

int main(int, char**)
{
	/* Array<int> numbers(MAX_VAL);
	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = i;
	}
	for (int i = 0; i < MAX_VAL; i++)
	{
		std::cout << numbers[i] << " ";
	}
	std::cout << std::endl;

	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	} */
	Array<int> numbers(MAX_VAL);
	std::cout << "numbers: " <<  &numbers << std::endl;
	int* mirror = new int[MAX_VAL];
	std::cout << "mirror: " << &mirror << std::endl;
	srand(time(NULL));
	for (unsigned int i = 0; i < numbers.size(); i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	//SCOPE
	
	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
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
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	{
		Array<int> tmp = numbers;
		Array<int> test(numbers);
	}
	delete[] mirror;
	return 0;
}
