#include <iostream>
#include <random>
#include <set>

#define MIN 1
#define MAX 100000

int main(int ac, char ** av)
{
	if (ac != 2)
	{
		std::cerr << "Usage: " << av[0] << " <N>" << std::endl;
		return 1;
	}

	int N = std::stoi(av[1]);
	if (N <= 0)
	{
		std::cerr << "N must be a positive integer." << std::endl;
		return 1;
	}

	// provides a source of random numbers
	std::random_device rd;
	// Mersenne Twister pseudo-random number generator
	std::mt19937 gen(rd());
	// generated random ints within a range
	std::uniform_int_distribution<> dis(MIN, MAX);

	std::set<int> unique_numbers;
	while (unique_numbers.size() < N)
	{
		unique_numbers.insert(dis(gen));
	}

	std::copy(unique_numbers.begin(), unique_numbers.end(),
		std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

	return 0;
}
