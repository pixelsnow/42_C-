#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>

int main(int ac, char **av)
{
	std::fstream db;

	db.open("data.csv", std::ios::in);
	if (!db) {
		std::cerr << "Unable to open file";
		return 1;
	}

	db.close();
	return (0);
}
