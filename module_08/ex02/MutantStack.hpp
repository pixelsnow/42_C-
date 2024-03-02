#include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack(){};
		//MutantStack(const MutantStack & source);
		~MutantStack(){};

		//MutantStack &operator=(const MutantStack & source);

	using iterator = typename std::stack<T>::container_type::iterator;
	using const_iterator = typename std::stack<T>::container_type::const_iterator;
	using reverse_iterator = typename std::stack<T>::container_type::reverse_iterator;
	using const_reverse_iterator = typename std::stack<T>::container_type::const_reverse_iterator;


	iterator begin() {
		return this->c.begin();
	}

	const_iterator begin() const {
		return this->c.begin();
	}

	const_iterator cbegin() const {
		return this->c.cbegin();
	}

	reverse_iterator rbegin() {
		return this->c.rbegin();
	}

	const_reverse_iterator rbegin() const {
		return this->c.rbegin();
	}

	iterator end() {
		return this->c.end();
	}

	const_iterator cend() const {
		return this->c.cend();
	}

	reverse_iterator rend() {
		return this->c.rend();
	}

	const_reverse_iterator rend() const {
		return this->c.rend();
	}

};

#include "MutantStack.tpp"
