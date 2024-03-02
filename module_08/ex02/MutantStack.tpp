#ifndef MUTANT_STACK_TPP
#define MUTANT_STACK_TPP

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

#endif