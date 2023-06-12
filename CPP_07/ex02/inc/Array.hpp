#pragma once
#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <exception>

template <class T>
class Array
{
	public:
		Array<T>() { _size = 0; };
		Array<T>(unsigned int size) { _array = new T[size]; };
		Array<T>(const Array &obj);
		Array &operator=(const Array &obj);
		~Array();

		T &operator[]();
	private:
		T *_array;
		unsigned int _size;
};

#endif
