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
	return *this;
}

void Span::addNumber(int newNum)
{
	if (this->span.size() >= this->N)
		throw OverCapacityException();
	this->span.insert(newNum);
}

unsigned int Span::shortestSpan()
{
	if (this->span.size() < 2)
		throw NotEnoughElementsException();

	unsigned int minDiff = *next(this->span.begin()) - *this->span.begin();

	std::multiset<int, std::less<int> >::iterator itr;
	for (itr = this->span.begin(); itr != prev(this->span.end()); ++itr)
	{
		unsigned int newDiff = (*next(itr) - *itr);
		if (newDiff < minDiff)
			minDiff = newDiff;
		if (minDiff == 0)
			break;
	}
	return minDiff;
}

unsigned int Span::longestSpan()
{
	if (this->span.size() < 2)
		throw NotEnoughElementsException();
	return (*this->span.rbegin() - *this->span.begin());
}

std::multiset<int, std::less<int> >::const_iterator Span::getBegin() const
{
	return this->span.begin();
}

std::multiset<int, std::less<int> >::const_iterator Span::getEnd() const
{
	return this->span.end();
}

const char * Span::OverCapacityException::what() const throw()
{
	return "ERROR: The Span is full, can't add more numbers.";
}

const char * Span::NotEnoughElementsException::what() const throw()
{
	return "ERROR: Not enough elements in the Span to calculate shortest/longest span.";
}

std::ostream &operator<<(std::ostream &out, Span const &span)
{
	std::multiset<int, std::less<int> >::iterator itr;
	bool first = true;
	for (itr = span.getBegin(); itr != span.getEnd(); ++itr)
	{
		if (first)
			first = false;
		else
			out << ' ';
		out << *itr;
	}
	return out;
}
