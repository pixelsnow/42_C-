#ifndef SPAN_HPP
#define SPAN_HPP

#include <set>

class Span
{
	private:
		unsigned int N;
		std::multiset<int, std::greater<int> > span;
	public:
		Span();
		Span(unsigned int newN);
		Span(const Span & source);
		~Span();

		Span &operator=(const Span & source);

		void addNumber(int newNum);

		template<typename Container>
		void addNumber(typename Container::const_iterator & rangeStart,
			typename Container::const_iterator & rangeEnd);
		/* template<typename Container>
		void addNumber(typename Container::const_iterator & range); */

		unsigned int shortestSpan();
		unsigned int longestSpan();
		std::multiset<int, std::greater<int> >::const_iterator getBegin() const;
		std::multiset<int, std::greater<int> >::const_iterator getEnd() const;

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

#endif
