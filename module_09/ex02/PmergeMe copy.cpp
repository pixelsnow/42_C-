#include "PmergeMe.hpp"

template <typename Container>
void PMerge<Container>::printVector(const Container &vec)
{
	for (const unsigned int &element : vec)
	{
		std::cout << element << " ";
	}
	std::cout << "\n";
}

template <typename Container>
void PMerge<Container>::printVectors(const std::vector<Container> &vec)
{
	for (const Container &element : vec)
	{
		printVector(element);
	}
	std::cout << "\n";
}

// CONSTRUCTORS

template <typename Container>
PMerge<Container>::PMerge() {}

template <typename Container>
PMerge<Container>::PMerge(const PMerge<Container> & source)
{
	(void)source;
}

// DESTRUCTOR

template <typename Container>
PMerge<Container>::~PMerge() {}

// OPERATORS

template <typename Container>
PMerge<Container> & PMerge<Container>::operator=(const PMerge<Container> & source)
{
	(void)source;
	return *this;
}

// METHODS

// Parsing

template <typename Container>
bool PMerge<Container>::isAllDigits(const std::string& str) const
{
	return std::all_of(str.begin(), str.end(), ::isdigit);
}

template <typename Container>
Container PMerge<Container>::parseArgsToVector(int ac, char** av)
{
	Container vect;
	std::unordered_set<unsigned int> seen;
	if (ac < 2)
		throw InvalidInputException();
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

template <typename Container>
void PMerge<Container>::displayError()
{
	std::cerr << RED << "Error" << RESET << std::endl;
}

template <typename Container>
void PMerge<Container>::displaySummary(std::chrono::nanoseconds duration,
	std::string containerName, int numOfElements) const
{
	std::cout << "Time to process " << numOfElements << " elements with std::" << containerName << " : " << duration.count() << " us" << std::endl;
}

template <typename Container>
Container PMerge<Container>::pairUp
	(Container & vect)
{
	Container res;
	for (size_t i = 0; i < vect.size(); i += 2)
	{
		res.emplace_back(std::minmax(vect[i], vect[i + 1]));
	}
	return res;
}

// Sorting

template <typename Container>
std::unordered_map<unsigned int, unsigned int> PMerge<Container>::connectPairs
	(const Container & paired)
{
	std::unordered_map<unsigned int, unsigned int> pairMap;
	for (const auto &element : paired)
	{
		pairMap[element.second] = element.first;
	}
	return pairMap;
}

template <typename Container>
std::unordered_map<unsigned int, unsigned int> PMerge<Container>::connectReversePairs
	(Container & larger, Container & smaller)
{
	std::unordered_map<unsigned int, unsigned int> reversePairMap;
	auto itSmall = smaller.begin();
	auto itLarge = larger.begin();
	while (itSmall != smaller.end() && itLarge != larger.end())
	{
		reversePairMap[*itSmall] = *itLarge;
		++itSmall;
		++itLarge;
	}
	return reversePairMap;
}
template <typename Container>
Container PMerge<Container>::makeLargerVect
	(const Container & paired)
{
	Container vect;
	for (const auto &element : paired)
	{
		vect.emplace_back(element.second);
	}
	return vect;
}

template <typename Container>
Container PMerge<Container>::makeSmallerVect (const Container & vect,
	std::unordered_map<unsigned int, unsigned int> & pairMap)
{
	Container smaller;
	for (const unsigned int element : vect)
	{
		smaller.emplace_back(pairMap[element]);
	}
	return smaller;
}

template <typename Container>
Container PMerge<Container>::generateGroupSizes(unsigned int vectSize)
{
	Container sequence;

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

template <typename Container>
unsigned int PMerge<Container>::calculateNextIndex(const Container & groupSizes, unsigned int totalElements, unsigned int currentIndex)
{
	unsigned int groupSum = 0;
	for (const unsigned int groupSize : groupSizes)
	{
		if (currentIndex < groupSum + groupSize)
		{
			unsigned int ceiling = groupSum + groupSize;
			if (ceiling > totalElements)
				ceiling = totalElements;
			unsigned int reversedIndex = ceiling - 1 - (currentIndex - groupSum);
			return reversedIndex;
		}
		groupSum += groupSize;
	}
	return totalElements;
}

template <typename Container>
void PMerge<Container>::sortVector(Container & vect)
{
	if (vect.size() < 2)
	{
		return;
	}

	bool hasExtraElem = vect.size() % 2 != 0;
	unsigned int lastElem;
	if (hasExtraElem)
	{
		lastElem = vect.back();
		vect.pop_back();
	}

	Container paired = pairUp(vect);
	std::unordered_map<unsigned int, unsigned int> pairMap
		= connectPairs(paired);
	// make a vector of bigger elements
	vect = makeLargerVect(paired);
	// sort recursively
	sortVector(vect);
	// make a vector of smaller elements in matching order
	Container smallerElems = makeSmallerVect(vect, pairMap);
	std::unordered_map<unsigned int, unsigned int> reversePairMap
		= connectReversePairs(vect, smallerElems);
	// move the elem paired with the smallest sorted into the beginning
	vect.insert(vect.begin(), smallerElems.front());
	smallerElems.erase(smallerElems.begin());
	// push the odd elem to the back if it exists
	if (hasExtraElem)
	{
		smallerElems.emplace_back(lastElem);
	}
	if (!smallerElems.size())
		return;
	// if there's only one unsorted left, insert into the sorted with binary
	if (smallerElems.size() <= 1)
	{
		unsigned int elem = smallerElems.front();
		auto endIt = vect.end();
		if (elem != lastElem)
			endIt--;
		vect.insert(std::lower_bound(vect.begin(), endIt, elem), elem);
	}
	// otherwise do the algo with partitions
	else
	{
		unsigned int totalElements = smallerElems.size();
		Container groupSizes = generateGroupSizes(totalElements);
		for (unsigned int i = 0; i < totalElements; i++)
		{
			unsigned int nextIndex = calculateNextIndex(groupSizes, totalElements, i);
			unsigned int elem = smallerElems[nextIndex];
			auto sortedMatchIt = reversePairMap.find(elem);
			auto endIt = vect.end();
			if (sortedMatchIt != reversePairMap.end())
			{
				endIt = std::lower_bound(vect.begin(), vect.end(), elem);
			}
			vect.insert(std::lower_bound(vect.begin(), endIt, elem), elem);
		}
	}
}

template <typename Container>
std::chrono::nanoseconds PMerge<Container>::timeVector(int ac, char **av)
{
	std::chrono::high_resolution_clock::time_point startTime
		= std::chrono::high_resolution_clock::now();

	Container vect = parseArgsToVector<std::vector<unsigned int, unsigned int> >(ac, av);

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

template <typename Container>
void PMerge<Container>::timeSorts(int ac, char** av)
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

template <typename Container>
const char * PMerge<Container>::InvalidInputException::what() const throw()
{
	return "Invalid input";
}

template <typename Container>
const char * PMerge<Container>::SortErrorException::what() const throw()
{
	return "Error during sorting";
}