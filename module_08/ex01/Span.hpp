#ifndef SPAN_HPP
#define SPAN_HPP

#include <set>
#include <iostream>

class Span
{
	private:
		unsigned int N;
		std::multiset<int, std::less<int> > span;
	public:
		Span();
		Span(unsigned int newN);
		Span(const Span & source);
		~Span();

		Span &operator=(const Span & source);

		void addNumber(int newNum);

		template<typename Container>
		void addNumbers(typename Container::const_iterator rangeStart,
			typename Container::const_iterator rangeEnd);

		unsigned int shortestSpan();
		unsigned int longestSpan();
		std::multiset<int, std::less<int> >::const_iterator getBegin() const;
		std::multiset<int, std::less<int> >::const_iterator getEnd() const;

		class OverCapacityException : public std::exception
		{
			public:
				virtual const char * what() const throw();
		};

		class NotEnoughElementsException : public std::exception
		{
			public:
				virtual const char * what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, Span const &span);

template<typename Container>
void Span::addNumbers(typename Container::const_iterator rangeStart,
	typename Container::const_iterator rangeEnd)
{
	if (std::distance(rangeStart, rangeEnd) + (this->span.size()) > N)
		throw OverCapacityException();
	this->span.insert(rangeStart, rangeEnd);
}

#endif
