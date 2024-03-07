#include "PmergeMe.hpp"

PMerge::PMerge() {}

bool PMerge::isAllDigits(const std::string& str) const
{
	return std::all_of(str.begin(), str.end(),
		[](unsigned char c)
		{
			return std::isdigit(c);
		}
	);
}

void PMerge::parseCommandLineArgs(int ac, char** av)
{
	for (unsigned int i = 1; i < ac; i++)
	{
		if (!isAllDigits(av[i]))
			throw InvalidInputException();
		try
		{
			_numbers.push_back(std::stoul(av[i]));
		}
		catch(const std::exception & e)
		{
			throw InvalidInputException();
		}
	}
}

void PMerge::displayError()
{
	std::cerr << RED << "Error" << RESET << std::endl;
}

void PMerge::displaySummary(double vectorTime)
{
	std::cout << "Before: " << std::endl;
	std::cout << "After: " << std::endl;
	std::cout << "Time to process " << _numbers.size() << "elements with std::vector : " << vectorTime << " us" << std::endl;
}

PMerge::PMerge(int ac, char ** av)
{

}

PMerge::PMerge(const PMerge & source) : _numbers(source._numbers) {}

PMerge::~PMerge() {}

PMerge & PMerge::operator=(const PMerge & source)
{
	_numbers = source._numbers;
	return *this;
}

double PMerge::sortOnVector()
{

}

void PMerge::timeSorts()
{
	try
	{
		double vectorTime = sortOnVector();
		displaySummary(vectorTime);
	}
	catch(const std::exception& e)
	{
		displayError();
	}
}


const char * PMerge::InvalidInputException::what() const throw()
{
	return "Invalid input";
}

const char * PMerge::SortErrorException::what() const throw()
{
	return "Error during sorting";
}
