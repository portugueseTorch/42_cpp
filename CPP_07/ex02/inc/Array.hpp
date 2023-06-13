#pragma once
#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <exception>

# define debug(x) std::cout << x << std::endl

template <class T>
class Array
{
	public:
		// CONSTRUCTORS
		Array<T>() { _size = 0; _array = new T[_size]; };
		Array<T>(unsigned int size) { _size = size; _array = new T[size]; };
		Array<T>(const Array &obj) {
			_size = obj.getSize();
			_array = new T[_size];
			for (unsigned int i = 0; i < _size; i++)
				_array[i] = obj[i];
		}
		Array<T> &operator=(const Array &obj) {
			if (&obj == this)
				return *this;
			delete[] _array;
			_size = obj.getSize();
			_array = new T[_size];
			for (unsigned int i = 0; i < _size; i++)
				_array[i] = obj[i];
			return *this;
		}

		// DESTRUCTORS
		~Array() { delete[] _array; }

		// GETTERS
		unsigned int getSize() const { return _size; };

		// OPERATORS
		T &operator[](int index) const {
			if (index < 0 || static_cast<unsigned int>(index) >= _size)
				throw InvalidIndexException();
			return _array[index];
		}

		// EXCEPTIONS
		class InvalidIndexException: public std::exception
		{
			public:
				virtual const char* what() const throw() { return "Invalid Index"; }
		};

	private:
		T *_array;
		unsigned int _size;
};

#endif
