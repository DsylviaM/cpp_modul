#include "Array.hpp"

template <typename T>
Array<T>::Array(): _data(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _data(new T[n]), _size(n)
{
	for (unsigned int it = 0; it < _size; ++it)
		_data[it] = 0;
}

template <typename T>
Array<T>::~Array()
{
	delete[] _data;
}

template <typename T>
Array<T>::Array(const Array& other)
{
	_size = other._size;
	_data = new T[_size];
	for (unsigned int it = 0; it < _size; ++it)
		this->_data[it] = other._data[it];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other)
{
	if (*this != other)
	{
		delete [] _data;
		_size = other._size;
		_data = new T[_size];
		for (unsigned int it = 0; it < _size; ++it)
			this->_data[it] = other._data[it];
	}
	return *this;
}

template<typename T>
T&	Array<T>::operator[](unsigned int index)
{
	if (index < 0 || index >= _size)
		throw std::exception();
	return _data[index];
}

template<typename T>
unsigned int	Array<T>::size() const
{
	return _size;
}

template<typename T>
std::ostream&	operator<<(std::ostream &out, Array<T>& other)
{
	int size = other.size();
	for (int i = 0; i < size; ++i)
	{
		out << other[i];
		if (i < size - 1)
			out << " ";
	}
	return out;
}
