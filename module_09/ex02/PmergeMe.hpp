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
	PairContainer pairUp(Container & sequence) const;

	template <typename PairContainer>
	std::unordered_map<unsigned int, unsigned int> connectPairs
		(const PairContainer & paired) const;

	template <typename Container>
	std::unordered_map<unsigned int, unsigned int> connectReversePairs
		(Container & larger, Container & smaller) const;

	template <typename Container, typename PairContainer>
	Container makeLargerSequence(const PairContainer & paired) const;

	template <typename Container>
	Container makeSmallerSequence(const Container & sequence,
		std::unordered_map<unsigned int, unsigned int> & pairMap) const;

	template <typename Container>
	Container generateGroupSizes(unsigned int totalSize) const;

	template <typename Container>
	unsigned int calculateNextIndex(const Container & groupSizes,
		unsigned int totalElements, unsigned int currentIndex) const;

	template <typename Container, typename PairContainer>
	void sortSequence(Container & sequence) const;


	template <typename Container>
	void printSequence(const Container &sequence) const;

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
void PMergeMe::printSequence(const Container &sequence) const
{
	for (const unsigned int &element : sequence)
	{
		std::cout << element << " ";
	}
	std::cout << "\n";
}

template <typename Container>
Container PMergeMe::parseArgsToContainer(int ac, char** av) const
{
	Container sequence;
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
			sequence.push_back(value);
		}
		catch(const std::exception & e)
		{
			throw InvalidInputException();
		}
	}
	return sequence;
}

template <typename Container, typename PairContainer>
PairContainer PMergeMe::pairUp (Container & sequence) const
{
	PairContainer res;
	for (size_t i = 0; i < sequence.size(); i += 2)
	{
		res.emplace_back(std::minmax(sequence[i], sequence[i + 1]));
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
	Container sequence;
	for (const auto &element : paired)
	{
		sequence.emplace_back(element.second);
	}
	return sequence;
}

template <typename Container>
Container PMergeMe::makeSmallerSequence (const Container & sequence,
	std::unordered_map<unsigned int, unsigned int> & pairMap) const
{
	Container smaller;
	for (const unsigned int element : sequence)
	{
		smaller.emplace_back(pairMap[element]);
	}
	return smaller;
}

template <typename Container>
Container PMergeMe::generateGroupSizes(unsigned int totalSize) const
{
	Container sequence;

	unsigned int pow = 2;
	unsigned int sum = 0;
	for (unsigned int i = 2; i <= totalSize; i++)
	{
		sequence.emplace_back(pow);
		sum += pow;
		if (sum > totalSize)
			break;
		pow = std::pow(2, i) - pow;
	}
	return sequence;
}

template <typename Container>
unsigned int PMergeMe::calculateNextIndex(const Container & groupSizes,
	unsigned int totalSize, unsigned int currentIndex) const
{
	unsigned int groupSum = 0;
	for (const unsigned int groupSize : groupSizes)
	{
		if (currentIndex < groupSum + groupSize)
		{
			unsigned int ceiling = groupSum + groupSize;
			if (ceiling > totalSize)
				ceiling = totalSize;
			unsigned int reversedIndex = ceiling - 1 - (currentIndex - groupSum);
			return reversedIndex;
		}
		groupSum += groupSize;
	}
	return totalSize;
}

template <typename Container, typename PairContainer>
void PMergeMe::sortSequence(Container & sequence) const
{
	if (sequence.size() < 2)
	{
		return;
	}
	bool hasExtraElem = sequence.size() % 2 != 0;
	unsigned int lastElem;
	if (hasExtraElem)
	{
		lastElem = sequence.back();
		sequence.pop_back();
	}

	PairContainer paired = pairUp<Container, PairContainer>(sequence);
	std::unordered_map<unsigned int, unsigned int> pairMap
		= connectPairs(paired);
	sequence = makeLargerSequence<Container, PairContainer>(paired);

	sortSequence<Container, PairContainer>(sequence);

	Container smallerElems = makeSmallerSequence(sequence, pairMap);
	std::unordered_map<unsigned int, unsigned int> reversePairMap
		= connectReversePairs(sequence, smallerElems);

	sequence.insert(sequence.begin(), smallerElems.front());
	smallerElems.erase(smallerElems.begin());

	if (hasExtraElem)
	{
		smallerElems.emplace_back(lastElem);
	}

	if (smallerElems.size() == 0)
	{
		return;
	}
	if (smallerElems.size() == 1)
	{
		unsigned int elem = smallerElems.front();
		auto endIt = sequence.end();
		if (elem != lastElem)
			endIt--;
		sequence.insert(std::lower_bound(sequence.begin(), endIt, elem), elem);
	}
	else
	{
		unsigned int totalElements = smallerElems.size();
		Container groupSizes = generateGroupSizes<Container>(totalElements);
		for (unsigned int i = 0; i < totalElements; i++)
		{
			unsigned int nextIndex
				= calculateNextIndex(groupSizes, totalElements, i);
			unsigned int elem = smallerElems[nextIndex];
			auto sortedMatchIt = reversePairMap.find(elem);
			auto endIt = sequence.end();
			if (sortedMatchIt != reversePairMap.end())
			{
				endIt = std::lower_bound(sequence.begin(), sequence.end(), elem);
			}
			sequence.insert(std::lower_bound(sequence.begin(), endIt, elem), elem);
		}
	}
}

#endif
