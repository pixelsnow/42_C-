#ifndef MUTANT_STACK_TPP
#define MUTANT_STACK_TPP

template<typename T, typename C>
MutantStack<T,C>::MutantStack() {}

template<typename T, typename C>
MutantStack<T,C>::MutantStack(const MutantStack & source)
{
	(void) source;
}

template<typename T, typename C>
MutantStack<T,C>::~MutantStack() {}

template<typename T, typename C>
MutantStack<T,C> & MutantStack<T,C>::operator=(const MutantStack & source)
{
	(void) source;
	//*this = source;
	return *this;
}

template<typename T, typename C>
typename MutantStack<T,C>::iterator MutantStack<T,C>::begin() {
	return this->c.begin();
}

template<typename T, typename C>
typename MutantStack<T,C>::const_iterator MutantStack<T,C>::cbegin() const
{
	return this->c.cbegin();
}

template<typename T, typename C>
typename MutantStack<T,C>::reverse_iterator MutantStack<T,C>::rbegin()
{
	return this->c.rbegin();
}

template<typename T, typename C>
typename MutantStack<T,C>::const_reverse_iterator MutantStack<T,C>::rbegin() const
{
	return this->c.rbegin();
}

template<typename T, typename C>
typename MutantStack<T,C>::iterator MutantStack<T,C>::end()
{
	return this->c.end();
}

template<typename T, typename C>
typename MutantStack<T,C>::const_iterator MutantStack<T,C>::cend() const
{
	return this->c.cend();
}

template<typename T, typename C>
typename MutantStack<T,C>::reverse_iterator MutantStack<T,C>::rend()
{
	return this->c.rend();
}

template<typename T, typename C>
typename MutantStack<T,C>::const_reverse_iterator MutantStack<T,C>::rend() const {
	return this->c.rend();
}

#endif