#include "PmergeMe.hpp"

void PMerge::printVector(const std::vector<unsigned int> &vec)
{
	for (const int &element : vec)
	{
		std::cout << element << " ";
	}
	std::cout << "\n";
}

void PMerge::printVectors(const std::vector<std::vector<unsigned int>> &vec)
{
	for (const std::vector<unsigned int> &element : vec)
	{
		printVector(element);
	}
	std::cout << "\n";
}

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

std::vector<std::pair<unsigned int, unsigned int>> pairUp
	(std::vector<unsigned int> & vect)
{
	std::vector<std::pair<unsigned int, unsigned int>> res;
	for (size_t i = 0; i < vect.size(); i += 2)
	{
		res.emplace_back(std::minmax(vect[i], vect[i + 1]));
	}
	return res;
}

// Sorting

/* void sortVectorPairs(std::vector<std::pair<unsigned int, unsigned int> > &vect)
{
	if (vect.size() < 2)
		return;
	
} */
void sortVector(std::vector<unsigned int> &vect)
{
	if (vect.size() < 2)
		return;

	bool hasExtraElem = vect.size() % 2 != 0;
	int lastElem;
	if (hasExtraElem)
	{
		lastElem = vect.back();
		vect.pop_back();
	}

	std::vector<std::pair<unsigned int, unsigned int> > paired = pairUp(vect);
	std::map<unsigned int, unsigned int> largerToSmaller = connectPairs(paired);
	// make a vector of bigger elements
	std::vector<unsigned int> vect = makeLargerVect(paired);
	// sortVector(biggerElems)
	sortVector(vect);
	// make a vector of smaller elements in matching order
	std::vector<unsigned int> smallerElems = makeSmallerVect(vect, paired);
	// insert the elem paired with the smallest sorted into the beginning
	vect.insert(vect.begin(), smallerElems[0]);
	smallerElems.erase(smallerElems.begin());
	// CHANGE ORDER OF THIS AND PREVIOUS?
	// push the odd elem to the back if it exists
	if (hasExtraElem)
	{
		smallerElems.push_back(lastElem);
	}
	// if there's only one unsorted left, insert into the sorted with binary
	if (smallerElems.size() <= 1)
	{
		
	}
	// otherwise do the algo with partitions
}


std::chrono::nanoseconds PMerge::timeVector(int ac, char **av)
{
	std::chrono::high_resolution_clock::time_point startTime
		= std::chrono::high_resolution_clock::now();

	std::vector<unsigned int> vect = parseArgsToVector(ac, av);
	//std::vector<std::pair<unsigned int, unsigned int> > pairVect = pairUp(vect);
	sortVector(vect);


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
		// remember to check if has repeat elems
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
