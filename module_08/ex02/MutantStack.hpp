#include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack();
		MutantStack(const MutantStack & source);
		~MutantStack();

		MutantStack &operator=(const MutantStacks & source);

		using iterator = typename std::stack<T>::container_type::iterator;
	using const_iterator = typename std::stack<T>::container_type::const_iterator;
	using reverse_iterator = typename std::stack<T>::container_type::reverse_iterator;
	using const_reverse_iterator = typename std::stack<T>::container_type::const_reverse_iterator;




};

#include "MutantStack.tpp"
