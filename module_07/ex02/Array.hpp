#ifndef ARRAY_HPP
#define ARRAY_HPP

template<typename T>
class Array
{
	private:
		T* _arr;
		unsigned int _arrSize;
	public:
		Array();
		Array(unsigned int n);
		Array(Array const & source);

		~Array();

		Array &operator=(Array const & source);
		T &operator[](unsigned int n);

		unsigned int size() const;

		class IndexOutOfBoundsException : public std::exception
		{
			public:
				virtual const char * what() const throw();
		};
};

#include "Array.tpp"

#endif
