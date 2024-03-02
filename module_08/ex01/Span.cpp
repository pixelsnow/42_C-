/* int min=a[0],ans=0;
for (int i=1;i<n;i++)
	if (a[i]<min) min=a[i];
	else ans=max(ans,a[i]-min);
return ans; */

#include "Span.hpp"

Span::Span() : N(0) {}

Span::Span(unsigned int newN) : N(newN) {}

Span::Span(const Span & source) : N(source.N)
{
	this->span = source.span;
}

Span::~Span() {}

Span & Span::operator=(const Span & source)
{
	this->span = source.span;
	this->N = source.N;
}

void Span::addNumber(int newNum)
{
	if (this->span.size() + 1 >= this->N)
		throw OverCapacityException();
	this->span.insert(newNum);
}

template<typename Container>
void addNumber(typename Container::const_iterator & range)
{
	if ((range.end() - range.begin()) + this->N > N)
		throw OverCapacityException();
	this->span.insert_range(range);
}

unsigned int Span::shortestSpan()
{
	if (N < 2)
		throw NotEnoughElementsException();

	unsigned int minDiff = *next(this->span.begin()) - *this->span.begin();

	std::multiset<int, std::greater<int>>::iterator itr;
	for (itr = this->span.begin(); itr != prev(this->span.end()); ++itr)
	{
		unsigned int newDiff = (*next(itr) - *itr);
		if (newDiff < minDiff)
			minDiff = newDiff;
	}
	return minDiff;
}

unsigned int Span::longestSpan()
{
	if (N < 2)
		throw NotEnoughElementsException();
	return (*this->span.end() - *this->span.begin());
}

const char * Span::OverCapacityException::what() const throw()
{
	return "ERROR: The Span is full, can't add more numbers.";
}

const char * Span::NotEnoughElementsException::what() const throw()
{
	return "ERROR: Not enough elements in the Span to calculate shortest/longest span.";
}
