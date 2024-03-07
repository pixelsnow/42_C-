#include "PmergeMe.hpp"

// CONSTRUCTORS

PMerge::PMerge() {}

PMerge::PMerge(const PMerge & source)
{
	(void)source;
}

// DESTRUCTOR

PMerge::~PMerge() {}

// OPERATORS

PMerge & PMerge::operator=(const PMerge & source)
{
	(void)source;
	return *this;
}

// METHODS

// Parsing

bool PMerge::isAllDigits(const std::string& str) const
{
	return std::all_of(str.begin(), str.end(), ::isdigit);
}

std::vector<unsigned int> PMerge::parseArgsToVector(int ac, char** av)
{
	std::vector<unsigned int> vect;
	for (unsigned int i = 1; i < ac; i++)
	{
		if (!isAllDigits(av[i]))
			throw InvalidInputException();
		try
		{
			vect.push_back(std::stoul(av[i]));
		}
		catch(const std::exception & e)
		{
			throw InvalidInputException();
		}
	}
	return vect;
}

// Printing

void PMerge::displayError()
{
	std::cerr << RED << "Error" << RESET << std::endl;
}

void PMerge::displaySummary(std::chrono::nanoseconds duration,
	std::string containerName, int numOfElements) const
{
	std::cout << "Before: " << std::endl;
	std::cout << "After: " << std::endl;
	std::cout << "Time to process " << numOfElements << "elements with std::" << containerName << " : " << duration.count() << " us" << std::endl;
}

// Sorting

std::chrono::nanoseconds PMerge::timeVector(int ac, char **av)
{
	std::chrono::high_resolution_clock::time_point startTime
		= std::chrono::high_resolution_clock::now();
	std::vector<unsigned int> vect = parseArgsToVector(ac, av);


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
		displaySummary(vectorTime, "vector", ac - 1);
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
