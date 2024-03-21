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

template <typename Container>
class PMerge
{
private:
	// Parsing
	bool isAllDigits(const std::string& str) const;
	Container parseArgsToVector(int ac, char** av);
	// Sorting
	Container pairUp(Container & vect);
	std::unordered_map<unsigned int, unsigned int> connectPairs
	(const Container & paired);
	std::unordered_map<unsigned int, unsigned int> connectReversePairs
	(Container & larger, Container & smaller);
	Container makeLargerVect(const Container & paired);
	Container makeSmallerVect(const Container & vect,
	std::unordered_map<unsigned int, unsigned int> & pairMap);
	Container generateGroupSizes(unsigned int vectSize);
	unsigned int calculateNextIndex(const Container & groupSizes, unsigned int totalElements, unsigned int currentIndex);
	void sortVector(Container & vect);
	std::chrono::nanoseconds timeVector(int ac, char **av);
	// Printing
	void displayError();
	void displaySummary(std::chrono::nanoseconds duration,
		std::string containerName, int numOfElements) const;
	// Extras
	void printVector(const Container &vec);
	void printVectors(const std::vector<Container> &vec);
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
