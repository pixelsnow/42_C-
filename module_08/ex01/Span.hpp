template<typename T>
class Span {
	private:
		unsigned int N;
	public:
		Span();
		Span(const Span & source);
		~Span();

		Span &operator=(const Span & source);

		void addNumber(int newNum);
		void addNumber(const T::iterator & iterStart,
			const T::iterator & iterEnd);
		int shortestSpan();
		int longestSpan();

		class OverCapacityException : public std::exception
		{
			public:
				virtual const char * what() const throw();
		};
};
