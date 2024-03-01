#include "easyfind.hpp"

#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE_BOLD "\033[1;34m"
#define RESET "\033[0m"

#include <iostream>
#include <regex>
//#include <iterator> // distance()

#include <array>
#include <vector>
#include <deque>
#include <forward_list>
#include <list>

const char * NotFoundException::what() const throw() {
	return "Value not found";
}

template<typename T>
void testCase(T & container, int testValue) {
	std::cout << "Test [" << testValue << "]:\n";
	try {
		typename T::iterator res = easyfind(container, testValue);
		std::cout << GREEN << "Value " <<  *res
			<< " found at index [" << std::distance(container.begin(), res) 
			<< "]" << RESET << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << RED << e.what() << RESET << std::endl;
	}
}

std::string trimName(const std::string& mangledName) {
	// Trim "IiNS_9allocatorIiEEEE" from the end
	std::regex endTrimPattern(R"(Ii.*$)");
	std::string trimmedEnd = std::regex_replace(mangledName,
		endTrimPattern, "");

	// Trim "NSt3__" and all numbers right after it from the beginning
	std::regex startTrimPattern(R"(^NSt3__\d+)");
	std::string trimmedStart = std::regex_replace(trimmedEnd,
		startTrimPattern, "");

	return trimmedStart;
}

template<typename T>
void test(T & container) {
	std::cout << BLUE_BOLD << "TESTING "
		<< trimName(typeid(container).name())
		<< ":" << RESET << std::endl;
	testCase(container, 1);
	testCase(container, 3);
	testCase(container, 0);
	testCase(container, -6);
}

int main(void) {
	std::array<int, 5> myArray{1, 2, 3, 1, 2};
	std::vector<int> myVector{1, 2, 3, 1, 2};
	std::deque<int> myDeque{1, 2, 3, 1, 2};
	std::forward_list<int> myFList{1, 2, 3, 1, 2};
	std::list<int> myList{1, 2, 3, 1, 2};

	test(myArray);
	test(myVector);
	test(myDeque);
	test(myFList);
	test(myList);
	
	return (0);
}
