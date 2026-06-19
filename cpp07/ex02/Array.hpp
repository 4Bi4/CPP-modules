#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>

template <typename T>
class Array
{
public:
	Array();
	explicit Array(unsigned int n);
	Array(const Array &other);
	Array &operator=(const Array &other);
	~Array();

	T              &operator[](unsigned int index);
	T const        &operator[](unsigned int index) const;
	unsigned int    size() const;

private:
	T            *_data;
	unsigned int  _size;
};

template <typename T>
Array<T>::Array() : _data(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _data(new T[n]()), _size(n) {}

template <typename T>
Array<T>::Array(const Array &other) : _data(new T[other._size]()), _size(other._size)
{
	for (unsigned int i = 0; i < _size; ++i)
		_data[i] = other._data[i];
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
	if (this == &other)
		return (*this);
	T *tmp = new T[other._size]();
	for (unsigned int i = 0; i < other._size; ++i)
		tmp[i] = other._data[i];
	delete[] _data;
	_data = tmp;
	_size = other._size;
	return (*this);
}

template <typename T>
Array<T>::~Array()
{
	delete[] _data;
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw std::out_of_range("Array: index out of bounds");
	return (_data[index]);
}

template <typename T>
T const &Array<T>::operator[](unsigned int index) const
{
	if (index >= _size)
		throw std::out_of_range("Array: index out of bounds");
	return (_data[index]);
}

template <typename T>
unsigned int Array<T>::size() const
{
	return (_size);
}

#endif
