#ifndef SPAN_HPP
#define SPAN_HPP

#include <set>

class Span
{
	private:
		unsigned int N;
		std::multiset<int, std::greater<int>> span;
	public:
		Span();
		Span(unsigned int newN);
		Span(const Span & source);
		~Span();

		Span &operator=(const Span & source);

		void addNumber(int newNum);

		/* template<typename Container>
		void addNumber(typename Container::const_iterator & iterStart,
			typename Container::const_iterator & iterEnd); */
		template<typename Container>
		void addNumber(typename Container::const_iterator & range);

		unsigned int shortestSpan();
		unsigned int longestSpan();

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

#endif
