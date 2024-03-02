#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP

#include <stack>

template<typename T, typename C = std::deque<T>>
class MutantStack : public std::stack<T,C>
{
public:
	MutantStack();
	MutantStack(const MutantStack & source);
	~MutantStack();

	MutantStack &operator=(const MutantStack & source);

	using iterator
		= typename std::stack<T,C>::container_type::iterator;
	using const_iterator
		= typename std::stack<T,C>::container_type::const_iterator;
	using reverse_iterator
		= typename std::stack<T,C>::container_type::reverse_iterator;
	using const_reverse_iterator
		= typename std::stack<T,C>::container_type::const_reverse_iterator;

	iterator begin();
	const_iterator cbegin() const;
	reverse_iterator rbegin();
	const_reverse_iterator rbegin() const;
	iterator end();
	const_iterator cend() const;
	reverse_iterator rend();
	const_reverse_iterator rend() const;

};

#include "MutantStack.tpp"

#endif
