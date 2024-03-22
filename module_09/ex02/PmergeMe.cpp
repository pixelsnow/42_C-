#include "PmergeMe.hpp"

PMergeMe::PMergeMe() {}

PMergeMe::PMergeMe(const PMergeMe & source)
{
	(void)source;
}

PMergeMe::~PMergeMe() {}

PMergeMe & PMergeMe::operator=(const PMergeMe & source)
{
	(void)source;
	return *this;
}

// METHODS

void PMergeMe::displayError() const
{
	std::cerr << RED << "Error" << RESET << std::endl;
}

void PMergeMe::displaySummary(std::chrono::nanoseconds duration,
	std::string containerName, int numOfElements) const
{
	std::cout << "Time to process " << numOfElements << " elements with std::"
		<< containerName << " : " << duration.count() << " us" << std::endl;
}

bool PMergeMe::isAllDigits(const std::string& str) const
{
	return std::all_of(str.begin(), str.end(), ::isdigit);
}

std::chrono::nanoseconds PMergeMe::timeVector(int ac, char **av) const
{
	std::chrono::high_resolution_clock::time_point startTime
		= std::chrono::high_resolution_clock::now();

	std::vector<unsigned int> vect = parseArgsToContainer<std::vector<unsigned int>>(ac, av);

	std::cout << "Before:	";
	printSequence<std::vector<unsigned int>>(vect);

	sortSequence<std::vector<unsigned int>, std::vector<std::pair<unsigned int, unsigned int> > >(vect);

	std::cout << "After:	";
	printSequence<std::vector<unsigned int>>(vect);

	std::chrono::high_resolution_clock::time_point endTime
		= std::chrono::high_resolution_clock::now();
	std::chrono::nanoseconds duration
		= std::chrono::duration_cast<std::chrono::nanoseconds>
			(endTime - startTime);
	return duration;
}

std::chrono::nanoseconds PMergeMe::timeDeque(int ac, char **av) const
{
	std::chrono::high_resolution_clock::time_point startTime
		= std::chrono::high_resolution_clock::now();

	std::deque<unsigned int> vect = parseArgsToContainer<std::deque<unsigned int>>(ac, av);

	sortSequence<std::deque<unsigned int>, std::deque<std::pair<unsigned int, unsigned int> > >(vect);

	std::chrono::high_resolution_clock::time_point endTime
		= std::chrono::high_resolution_clock::now();
	std::chrono::nanoseconds duration
		= std::chrono::duration_cast<std::chrono::nanoseconds>
			(endTime - startTime);
	return duration;
}

void PMergeMe::timeSorts(int ac, char** av) const
{
	try
	{
		std::chrono::nanoseconds vectorTime = timeVector(ac, av);
		std::chrono::nanoseconds degueTime = timeDeque(ac, av);
		displaySummary(vectorTime, "vector", ac - 1);
		displaySummary(degueTime, "deque", ac - 1);
	}
	catch(const std::exception& e)
	{
		displayError();
	}
}

// EXCEPTIONS

const char * PMergeMe::InvalidInputException::what() const throw()
{
	return "Invalid input";
}

const char * PMergeMe::SortErrorException::what() const throw()
{
	return "Error during sorting";
}
