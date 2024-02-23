template<typename T>
Array<T>::Array() : arrSize(0) {
	this->arr = new T[0];
}

template<typename T>
Array<T>::Array(unsigned int n) : arrSize(n) {
	this->arr = new T[n];
}

template<typename T>
Array<T>::Array(Array const & source) {
	*this = source;
}

template<typename T>
Array<T>::~Array() {
	delete[] this->arr;
}

template<typename T>
Array<T>& Array<T>::operator=(Array const & source) {
	if (&source == this)
		return (*this);
	this->arrSize = source.arrSize;
	free (this->arr);
	this->arr = new T[source.arrSize];
	for (unsigned int i = 0; i < this->arrSize; i++)
		this->arr[i] = source.arr[i];
	return *this;
}

template<typename T>
T& Array<T>::operator[](unsigned int n) {
	if (n < 0 || n >= this->arrSize)
		throw IndexOutOfBoundsException();
	return this->arr[n];
}

template<typename T>
unsigned int Array<T>::size() const {
	return this->arrSize;
}

template<typename T>
const char * Array<T>::IndexOutOfBoundsException::what() const throw()
{
	return "ERROR: Index out of bounds!";
}
