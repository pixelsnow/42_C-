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
	std::unordered_set<unsigned int> seen;
	for (int i = 1; i < ac; i++)
	{
		if (!isAllDigits(av[i]))
			throw InvalidInputException();
		try
		{
			unsigned int value = std::stoul(av[i]);
			if (seen.find(value) != seen.end()) // O(1)
			{
				throw InvalidInputException();
			}
			seen.insert(value);
			vect.push_back(value);
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
	std::cout << "Time to process " << numOfElements << " elements with std::" << containerName << " : " << duration.count() << " us" << std::endl;
}

std::vector<std::pair<unsigned int, unsigned int>> PMerge::pairUp
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

std::unordered_map<unsigned int, unsigned int> PMerge::connectPairs
	(const std::vector<std::pair<unsigned int, unsigned int> > & paired)
{
	std::unordered_map<unsigned int, unsigned int> pairMap;
	for (const std::pair<unsigned int, unsigned int> &element : paired)
	{
		pairMap[element.second] = element.first;
	}
	return pairMap;
}

std::vector<unsigned int> PMerge::makeLargerVect
	(const std::vector<std::pair<unsigned int, unsigned int> > & paired)
{
	std::vector<unsigned int> vect;
	for (const std::pair<unsigned int, unsigned int> &element : paired)
	{
		vect.emplace_back(element.second);
	}
	return vect;
}

std::vector<unsigned int> PMerge::makeSmallerVect (const std::vector<unsigned int> & vect,
	std::unordered_map<unsigned int, unsigned int> & pairMap)
{
	std::vector<unsigned int> smaller;
	for (const unsigned int element : vect)
	{
		smaller.emplace_back(pairMap[element]);
	}
	return smaller;
}

std::vector<unsigned int> PMerge::generateGroupSizes(unsigned int vectSize)
{
	std::vector<unsigned int> sequence;

	unsigned int pow = 2;
	unsigned int sum = 0;
	for (unsigned int i = 2; i <= vectSize; i++)
	{
		sequence.emplace_back(pow);
		sum += pow;
		if (sum > vectSize)
			break;
		pow = std::pow(2, i) - pow;
	}
	return sequence;
}

unsigned int PMerge::calculateNextIndex(const std::vector<unsigned int>& groupSizes, unsigned int totalElements, unsigned int currentIndex)
{
	unsigned int groupsSorted = 0;
	for (const unsigned int groupSize : groupSizes) {
		if (currentIndex < groupsSorted + groupSize) {
			unsigned int indexWithinGroup = groupsSorted + groupSize - currentIndex;
			return groupsSorted + groupSize - indexWithinGroup;
		}
		groupsSorted += groupSize;
	}
	return totalElements;
}

void PMerge::sortVector(std::vector<unsigned int> & vect)
{
	std::cout << "RECURSION call:	";
	printVector(vect);
	if (vect.size() < 2)
	{
		std::cout << "RECURSION end case:	";
		printVector(vect);
		return;
	}

	bool hasExtraElem = vect.size() % 2 != 0;
	unsigned int lastElem;
	if (hasExtraElem)
	{
		lastElem = vect.back();
		vect.pop_back();
	}

	std::vector<std::pair<unsigned int, unsigned int> > paired = pairUp(vect);
	std::unordered_map<unsigned int, unsigned int> pairMap
		= connectPairs(paired);
	// make a vector of bigger elements
	vect = makeLargerVect(paired);
	std::cout << "Larger vector before sorting:	";
	printVector(vect);
	// sort recursively
	sortVector(vect);
	std::cout << "Larger vector after sorting:	";
	printVector(vect);
	// make a vector of smaller elements in matching order
	std::vector<unsigned int> smallerElems = makeSmallerVect(vect, pairMap);
	std::cout << "Smaller vector:	";
	printVector(smallerElems);
	// move the elem paired with the smallest sorted into the beginning
	vect.insert(vect.begin(), smallerElems.front());
	smallerElems.erase(smallerElems.begin());
	std::cout << "Larger vector after adding first elem:	";
	printVector(vect);
	std::cout << "Smaller vector after adding first elem:	";
	printVector(smallerElems);
	// push the odd elem to the back if it exists
	if (hasExtraElem)
	{
		smallerElems.emplace_back(lastElem);
	}
	std::cout << "Smaller vector after adding last elem:	";
	printVector(smallerElems);
	if (!smallerElems.size())
		return;
	// if there's only one unsorted left, insert into the sorted with binary
	if (smallerElems.size() <= 1)
	{
		unsigned int elem = smallerElems.front();
		std::vector<unsigned int>::iterator endIt = vect.end();
		if (elem != lastElem)
			endIt--;
		vect.insert(std::lower_bound(vect.begin(), endIt, elem), elem);
	}
	// otherwise do the algo with partitions
	else
	{
		unsigned int totalElements = smallerElems.size();
		std::vector<unsigned int> groupSizes = generateGroupSizes(totalElements);
		std::cout << "Group sizes:	";
		printVector(vect);
		std::cout << "Index matches:	" << std::endl;
		for (unsigned int i = 0; i < totalElements; i++)
		{
			std::cout << "[ ";
			unsigned int nextIndex = calculateNextIndex(groupSizes, totalElements, i);
			unsigned int elem = smallerElems[nextIndex];
			unsigned int matchingIndexFromEnd = totalElements - i;
			if (hasExtraElem)
			{
				if (elem == lastElem)
				{
					matchingIndexFromEnd = 0;
				}
				else
				{
					matchingIndexFromEnd--;
				}
			}
			std::cout << nextIndex << "(" << elem << ")" << " -> ";
			std::vector<unsigned int>::iterator endIt
				= vect.end() - matchingIndexFromEnd;
			std::cout << matchingIndexFromEnd << "(" << *endIt << ")";
			vect.insert(std::lower_bound(vect.begin(), endIt, elem), elem);
			std::cout << " ]" << std::endl;
		}
	}
	std::cout << "RECURSION return:	";
	printVector(vect);
}

std::chrono::nanoseconds PMerge::timeVector(int ac, char **av)
{
	std::chrono::high_resolution_clock::time_point startTime
		= std::chrono::high_resolution_clock::now();


	std::vector<unsigned int> vect = parseArgsToVector(ac, av);

	std::cout << "Before:	";
	printVector(vect);

	sortVector(vect);

	std::cout << "After:	";
	printVector(vect);

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
