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

	// Method to get an iterator to the beginning of the stack
	iterator begin() {
		return this->c.begin();
	}

	// Method to get a const_iterator to the beginning of the stack
	const_iterator begin() const {
		return this->c.begin();
	}

	// Method to get a const_iterator to the beginning of the stack
	const_iterator cbegin() const {
		return this->c.cbegin();
	}

	// Method to get a reverse_iterator to the beginning of the stack
	reverse_iterator rbegin() {
		return this->c.rbegin();
	}

	// Method to get a const_reverse_iterator to the beginning of the stack
	const_reverse_iterator rbegin() const {
		return this->c.rbegin();
	}

	// Method to get an iterator to the end of the stack
	iterator end() {
		return this->c.end();
	}

	// Method to get a const_iterator to the end of the stack
	const_iterator cend() const {
		return this->c.cend();
	}

	// Method to get a reverse_iterator to the end of the stack
	reverse_iterator rend() {
		return this->c.rend();
	}

	// Method to get a const_reverse_iterator to the end of the stack
	const_reverse_iterator rend() const {
		return this->c.rend();
	}

};

#include "MutantStack.tpp"
