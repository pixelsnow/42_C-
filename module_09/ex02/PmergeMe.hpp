#ifndef PMERGEME_HPP
#define PMERGEME_HPP

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

class PMergeMe
{
private:

	bool isAllDigits(const std::string& str) const;

	std::chrono::nanoseconds timeVector(int ac, char **av) const;

	std::chrono::nanoseconds timeDeque(int ac, char **av) const;

	template <typename Container>
	Container parseArgsToContainer(int ac, char** av) const;

	template <typename Container, typename PairContainer>
	PairContainer pairUp(Container & vect) const;

	template <typename PairContainer>
	std::unordered_map<unsigned int, unsigned int> connectPairs
		(const PairContainer & paired) const;

	template <typename Container>
	std::unordered_map<unsigned int, unsigned int> connectReversePairs
		(Container & larger, Container & smaller) const;

	template <typename Container, typename PairContainer>
	Container makeLargerSequence(const PairContainer & paired) const;

	template <typename Container>
	Container makeSmallerSequence(const Container & vect,
		std::unordered_map<unsigned int, unsigned int> & pairMap) const;

	template <typename Container>
	Container generateGroupSizes(unsigned int vectSize) const;

	template <typename Container>
	unsigned int calculateNextIndex(const Container & groupSizes, unsigned int totalElements, unsigned int currentIndex) const;

	template <typename Container, typename PairContainer>
	void sortSequence(Container & vect) const;


	template <typename Container>
	void printSequence(const Container &vec) const;

	void displayError() const;

	void displaySummary(std::chrono::nanoseconds duration,
		std::string containerName, int numOfElements) const;
	
public:
	PMergeMe();
	PMergeMe(const PMergeMe & source);
	~PMergeMe();

	PMergeMe & operator=(const PMergeMe & source);

	void timeSorts(int ac, char** av) const;

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
void PMergeMe::printSequence(const Container &vec) const
{
	for (const unsigned int &element : vec)
	{
		std::cout << element << " ";
	}
	std::cout << "\n";
}

template <typename Container>
Container PMergeMe::parseArgsToContainer(int ac, char** av) const
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
			unsigned long longValue = std::stoul(av[i]);
			if (longValue > std::numeric_limits<unsigned int>::max())
			{
				throw InvalidInputException();
			}
			unsigned int value = longValue;
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
PairContainer PMergeMe::pairUp (Container & vect) const
{
	PairContainer res;
	for (size_t i = 0; i < vect.size(); i += 2)
	{
		res.emplace_back(std::minmax(vect[i], vect[i + 1]));
	}
	return res;
}

template <typename PairContainer>
std::unordered_map<unsigned int, unsigned int> PMergeMe::connectPairs
	(const PairContainer & paired) const
{
	std::unordered_map<unsigned int, unsigned int> pairMap;
	for (const auto &element : paired)
	{
		pairMap[element.second] = element.first;
	}
	return pairMap;
}

template <typename Container>
std::unordered_map<unsigned int, unsigned int> PMergeMe::connectReversePairs
	(Container & larger, Container & smaller) const
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
Container PMergeMe::makeLargerSequence(const PairContainer & paired) const
{
	Container vect;
	for (const auto &element : paired)
	{
		vect.emplace_back(element.second);
	}
	return vect;
}

template <typename Container>
Container PMergeMe::makeSmallerSequence (const Container & vect,
	std::unordered_map<unsigned int, unsigned int> & pairMap) const
{
	Container smaller;
	for (const unsigned int element : vect)
	{
		smaller.emplace_back(pairMap[element]);
	}
	return smaller;
}

template <typename Container>
Container PMergeMe::generateGroupSizes(unsigned int vectSize) const
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
unsigned int PMergeMe::calculateNextIndex(const Container & groupSizes,
	unsigned int totalElements, unsigned int currentIndex) const
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
void PMergeMe::sortSequence(Container & vect) const
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
	vect = makeLargerSequence<Container, PairContainer>(paired);
	// sort recursively
	sortSequence<Container, PairContainer>(vect);
	// make a vector of smaller elements in matching order
	Container smallerElems = makeSmallerSequence(vect, pairMap);
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
