#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define CYAN "\033[37m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

int main(int ac, char **av)
{
	std::fstream db;
	std::fstream input;

	if (ac != 2)
	{
		std::cerr << "Wrong number of arguments\n";
		return 1;
	}

	db.open("data.csv", std::ios::in);
	if (!db)
	{
		std::cerr << "Unable to open database file\n";
		return 1;
	}

	input.open(av[1], std::ios::in);
	if (!input)
	{
		std::cerr << "Unable to open input file\n";
		return 1;
	}

	BitcoinExchange btc(db);
	btc.displayConversions(input);

	db.close();
	input.close();
	return (0);
}
