#ifndef EASYFIND_TPP
#define EASYFIND_TPP

#include <exception>

template<typename T>
typename T::iterator easyfind(T & haystack, int needle)
{
	typename T::iterator res;
	res = std::find(haystack.begin(), haystack.end(), needle);
	if (res == haystack.end())
	{
		throw NotFoundException();
	}
	return res;
}

#endif
