#include "Array.hpp"

template<typename T>
Array<T>::Array() : size(0) {
	this->arr = new T[0];
}

template<typename T>
Array<T>::Array(unsigned int n) : size(0) {
	this->arr = new T[n];
}

template<typename T>
Array<T>::Array(Array const & source) {
	*this = source;
}

template<typename T>
Array<T>::~Array() {
	free(this->arr);
}

template<typename T>
Array<T>& Array<T>::operator=(Array const & source) {
	if (source == *this)
		return (*this);
	this->size = source.size;
	free (this->arr);
	this->arr = newT[source.size];
	for (unsigned int i = 0; i < this->size; i++)
		this[i] = source[i];
	return *this;
}

template<typename T>
T& Array<T>::operator[](unsigned int n) {
	if (n < 0 || n >= size)
		throw IndexOutOfBoundsException();
	return this->arr[n];
}

template<typename T>
unsigned int Array<T>::size() const {
	return this->size;
}

template<typename T>
const char * Array<T>::IndexOutOfBoundsException::what() const throw()
{
	return "ERROR: Index out of bounds!";
}
