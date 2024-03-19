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

std::unordered_map<unsigned int, unsigned int> connectPairs
	(const std::vector<std::pair<unsigned int, unsigned int> > & paired)
{
	std::unordered_map<unsigned int, unsigned int> pairMap;
	for (const std::pair<unsigned int, unsigned int> &element : paired)
	{
		pairMap[element.second] = element.first;
	}
	return pairMap;
}

std::vector<unsigned int> makeLargerVect
	(const std::vector<std::pair<unsigned int, unsigned int> > & paired)
{
	std::vector<unsigned int> vect;
	for (const std::pair<unsigned int, unsigned int> &element : paired)
	{
		vect.emplace_back(element.second);
	}
	return vect;
}

std::vector<unsigned int> makeSmallerVect (const std::vector<unsigned int> & vect,
	std::unordered_map<unsigned int, unsigned int> & pairMap)
{
	std::vector<unsigned int> smaller;
	for (const unsigned int element : vect)
	{
		smaller.emplace_back(pairMap[element]);
	}
	return smaller;
}

std::vector<unsigned int> generatePowerSequence(unsigned int vectSize)
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

void sortVector(std::vector<unsigned int> & vect)
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
	std::unordered_map<unsigned int, unsigned int> pairMap
		= connectPairs(paired);
	// make a vector of bigger elements
	std::vector<unsigned int> vect = makeLargerVect(paired);
	// sortVector(biggerElems)
	sortVector(vect);
	// make a vector of smaller elements in matching order
	std::vector<unsigned int> smallerElems = makeSmallerVect(vect, pairMap);
	// insert the elem paired with the smallest sorted into the beginning
	vect.insert(vect.begin(), smallerElems.front());
	smallerElems.erase(smallerElems.begin());
	// CHANGE ORDER OF THIS AND PREVIOUS PART?
	// push the odd elem to the back if it exists
	if (hasExtraElem)
	{
		smallerElems.emplace_back(lastElem);
	}

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
		std::vector<unsigned int> groupSizes = generatePowerSequence(smallerElems.size());
		unsigned int groupsSorted = 0;
		//unsigned int numsSorted = 0;
		for (const unsigned int groupSize : groupSizes)
		{
			unsigned int numsSorted = 0;
			for (unsigned int i = 0; i < groupSize; i++)
			{
				unsigned int elemIndex = groupsSorted + groupSize - i;
				unsigned int elem = smallerElems[elemIndex];
				// TODO: name sure case with extra elem is handled
				std::vector<unsigned int>::iterator endIt
					= vect.end()
						- (smallerElems.size() - elemIndex - 1 - hasExtraElem);
				vect.insert(std::lower_bound(vect.begin(), endIt, elem), elem);
				//smallerElems[groupsSorted + groupSize - i];
			}
			groupsSorted += groupSize;
		}
	}
	
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
