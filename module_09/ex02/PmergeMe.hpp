#ifndef PMERGEME_HPP
#define PMERGEME_HPP

// check if all imports are necessary
#include <chrono>
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <deque>
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
	// Sorting
	std::chrono::nanoseconds timeVector(int ac, char **av);
	std::chrono::nanoseconds timeDeque(int ac, char **av);

	template <typename Container>
	Container parseArgsToVector(int ac, char** av);

	template <typename Container, typename PairContainer>
	PairContainer pairUp(Container & vect);

	template <typename PairContainer>
	std::unordered_map<unsigned int, unsigned int> connectPairs
		(const PairContainer & paired);

	template <typename Container>
	std::unordered_map<unsigned int, unsigned int> connectReversePairs
		(Container & larger, Container & smaller);

	template <typename Container, typename PairContainer>
	Container makeLargerVect(const PairContainer & paired);

	template <typename Container>
	Container makeSmallerVect(const Container & vect,
		std::unordered_map<unsigned int, unsigned int> & pairMap);

	template <typename Container>
	Container generateGroupSizes(unsigned int vectSize);

	template <typename Container>
	unsigned int calculateNextIndex(const Container & groupSizes, unsigned int totalElements, unsigned int currentIndex);

	template <typename Container, typename PairContainer>
	void sortVector(Container & vect);


	template <typename Container>
	void printVector(const Container &vec);

	// Printing
	void displayError();
	void displaySummary(std::chrono::nanoseconds duration,
		std::string containerName, int numOfElements) const;
	
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


template <typename Container>
void PMerge::printVector(const Container &vec)
{
	for (const unsigned int &element : vec)
	{
		std::cout << element << " ";
	}
	std::cout << "\n";
}

template <typename Container>
Container PMerge::parseArgsToVector(int ac, char** av)
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

template <typename Container, typename PairContainer>
PairContainer PMerge::pairUp (Container & vect)
{
	PairContainer res;
	for (size_t i = 0; i < vect.size(); i += 2)
	{
		res.emplace_back(std::minmax(vect[i], vect[i + 1]));
	}
	return res;
}

// Sorting

template <typename PairContainer>
std::unordered_map<unsigned int, unsigned int> PMerge::connectPairs
	(const PairContainer & paired)
{
	std::unordered_map<unsigned int, unsigned int> pairMap;
	for (const auto &element : paired)
	{
		pairMap[element.second] = element.first;
	}
	return pairMap;
}

template <typename Container>
std::unordered_map<unsigned int, unsigned int> PMerge::connectReversePairs
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

template <typename Container, typename PairContainer>
Container PMerge::makeLargerVect(const PairContainer & paired)
{
	Container vect;
	for (const auto &element : paired)
	{
		vect.emplace_back(element.second);
	}
	return vect;
}

template <typename Container>
Container PMerge::makeSmallerVect (const Container & vect,
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
Container PMerge::generateGroupSizes(unsigned int vectSize)
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
unsigned int PMerge::calculateNextIndex(const Container & groupSizes, unsigned int totalElements, unsigned int currentIndex)
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

template <typename Container, typename PairContainer>
void PMerge::sortVector(Container & vect)
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

	PairContainer paired = pairUp<Container, PairContainer>(vect);
	std::unordered_map<unsigned int, unsigned int> pairMap
		= connectPairs(paired);
	// make a vector of bigger elements
	vect = makeLargerVect<Container, PairContainer>(paired);
	// sort recursively
	sortVector<Container, PairContainer>(vect);
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
		Container groupSizes = generateGroupSizes<Container>(totalElements);
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

#endif

/*
TODO:
- add consts where possible/needed
- test with out of range numbers
- check copy and assignment
- check that every function is a method
*/
