#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <exception>

class NotFoundException : public std::exception
{
	public:
		virtual const char * what() const throw();
};

template<typename T>
typename T::iterator easyfind(T & haystack, int needle)
{
	typename T::iterator res = std::find(haystack.begin(), haystack.end(), needle);
	if (res == haystack.end())
	{
		throw NotFoundException();
	}
	return res;
}

/* template<typename T>
typename T::iterator easyfind(const T & haystack, int needle);

#include "easyfind.tpp" */

#endif
