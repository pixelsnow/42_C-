#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>

class NotFoundException : public std::exception
{
	public:
		virtual const char * what() const throw();
};

template<typename T>
typename T::iterator easyfind(const T & haystack, int needle);

#include "easyfind.tpp"

#endif
