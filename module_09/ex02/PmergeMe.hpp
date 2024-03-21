#ifndef PMERGEME_HPP
#define PMERGEME_HPP

// check if all imports are necessary
#include <chrono>
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <list>
#include <unordered_map>
#include <unordered_set>

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
	std::vector<std::pair<unsigned int, unsigned int>> pairUp
	(std::vector<unsigned int> & vect);
	std::unordered_map<unsigned int, unsigned int> connectPairs
	(const std::vector<std::pair<unsigned int, unsigned int> > & paired);
	std::vector<unsigned int> makeLargerVect
	(const std::vector<std::pair<unsigned int, unsigned int> > & paired);
	std::vector<unsigned int> makeSmallerVect (const std::vector<unsigned int> & vect,
	std::unordered_map<unsigned int, unsigned int> & pairMap);
	std::vector<unsigned int> generateGroupSizes(unsigned int vectSize);
	unsigned int calculateNextIndex(const std::vector<unsigned int>& groupSizes, unsigned int totalElements, unsigned int currentIndex);
	void sortVector(std::vector<unsigned int> & vect);
	std::chrono::nanoseconds timeVector(int ac, char **av);
	// Printing
	void displayError();
	void displaySummary(std::chrono::nanoseconds duration,
		std::string containerName, int numOfElements) const;
	// Extras
	void printVector(const std::vector<unsigned int> &vec);
	void printVectors(const std::vector<std::vector<unsigned int> > &vec);
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
- add consts where possible/needed
- test with out of range numbers
- check copy and assignment
- check that every function is a method
*/
