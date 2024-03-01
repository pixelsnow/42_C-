#ifndef ARRAY_TPP
#define ARRAY_TPP

template<typename T>
Array<T>::Array() : _arrSize(0), _arr(NULL) {}

template<typename T>
Array<T>::Array(unsigned int n) : _arrSize(n) {
	if (n < 0)
		throw IndexOutOfBoundsException();
	if (n == 0)
		this->_arr = NULL;
	else
		this->_arr = new T[n];
}

template<typename T>
Array<T>::Array(Array const & source) : _arrSize(source._arrSize) {
	this->_arr = new T[source._arrSize];
	for (unsigned int i = 0; i < this->_arrSize; i++)
		this->_arr[i] = source._arr[i];
}

template<typename T>
Array<T>::~Array() {
	delete[] this->_arr;
}

template<typename T>
Array<T>& Array<T>::operator=(Array const & source) {
	if (&source == this)
		return (*this);
	if (this->_arrSize)
		delete[] this->_arr;
	this->_arrSize = source._arrSize;
	this->_arr = new T[source._arrSize];
	for (unsigned int i = 0; i < this->_arrSize; i++)
		this->_arr[i] = source._arr[i];
	return *this;
}

template<typename T>
T& Array<T>::operator[](unsigned int n) {
	if (n < 0 || n >= this->_arrSize)
		throw IndexOutOfBoundsException();
	return this->_arr[n];
}

template<typename T>
unsigned int Array<T>::size() const {
	return this->_arrSize;
}

template<typename T>
const char * Array<T>::IndexOutOfBoundsException::what() const throw() {
	return "ERROR: Index out of bounds!";
}

#endif
