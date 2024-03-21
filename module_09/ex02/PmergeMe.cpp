#include "PmergeMe.hpp"

PMerge::PMerge() {}

PMerge::PMerge(const PMerge & source)
{
	(void)source;
}

PMerge::~PMerge() {}

PMerge & PMerge::operator=(const PMerge & source)
{
	(void)source;
	return *this;
}

// METHODS

void PMerge::displayError()
{
	std::cerr << RED << "Error" << RESET << std::endl;
}

void PMerge::displaySummary(std::chrono::nanoseconds duration,
	std::string containerName, int numOfElements) const
{
	std::cout << "Time to process " << numOfElements << " elements with std::" << containerName << " : " << duration.count() << " us" << std::endl;
}

bool PMerge::isAllDigits(const std::string& str) const
{
	return std::all_of(str.begin(), str.end(), ::isdigit);
}

std::chrono::nanoseconds PMerge::timeVector(int ac, char **av)
{
	std::chrono::high_resolution_clock::time_point startTime
		= std::chrono::high_resolution_clock::now();

	std::vector<unsigned int> vect = parseArgsToVector<std::vector<unsigned int>>(ac, av);

	std::cout << "Before:	";
	printVector<std::vector<unsigned int>>(vect);

	sortVector<std::vector<unsigned int>, std::vector<std::pair<unsigned int, unsigned int> > >(vect);

	std::cout << "After:	";
	printVector<std::vector<unsigned int>>(vect);

	std::chrono::high_resolution_clock::time_point endTime
		= std::chrono::high_resolution_clock::now();
	std::chrono::nanoseconds duration
		= std::chrono::duration_cast<std::chrono::nanoseconds>
			(endTime - startTime);
	return duration;
}


std::chrono::nanoseconds PMerge::timeDeque(int ac, char **av)
{
	std::chrono::high_resolution_clock::time_point startTime
		= std::chrono::high_resolution_clock::now();

	std::deque<unsigned int> vect = parseArgsToVector<std::deque<unsigned int>>(ac, av);

	sortVector<std::deque<unsigned int>, std::deque<std::pair<unsigned int, unsigned int> > >(vect);

	std::chrono::high_resolution_clock::time_point endTime
		= std::chrono::high_resolution_clock::now();
	std::chrono::nanoseconds duration
		= std::chrono::duration_cast<std::chrono::nanoseconds>
			(endTime - startTime);
	return duration;
}

void PMerge::timeSorts(int ac, char** av)
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

const char * PMerge::InvalidInputException::what() const throw()
{
	return "Invalid input";
}

const char * PMerge::SortErrorException::what() const throw()
{
	return "Error during sorting";
}