#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <chrono>
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <list>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define CYAN "\033[37m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

class PMerge
{
private:
	// Parsing
	bool isAllDigits(const std::string& str) const;
	std::vector<unsigned int> parseArgsToVector(int ac, char** av);
	// Sorting
	void sort(std::vector<unsigned int> set);
	std::chrono::nanoseconds timeVector(int ac, char **av);
	void recursiveSort(std::vector<std::pair<unsigned int, unsigned int> > set);
	// Printing
	void displayError();
	void displaySummary(std::chrono::nanoseconds duration,
		std::string containerName, int numOfElements) const;
public:
	PMerge();
	PMerge(const PMerge & source);
	~PMerge();

	PMerge & operator=(const PMerge & source);

	void timeSorts(int ac, char** av);

	class InvalidInputException : public std::exception
	{
	public:
		virtual const char * what() const throw();
	};

	class SortErrorException : public std::exception
	{
	public:
		virtual const char * what() const throw();
	};
};

#endif

/*
TODO:
- add consts where needed
- test with out of range numbers
- check copy and assignment
- check that every function is a method
*/
