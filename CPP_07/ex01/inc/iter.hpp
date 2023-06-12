#pragma once
#ifndef ITER_HPP
# define ITER_FPP

# include <iostream>

template <typename T>
void iter(T *arr, size_t size, void (*func)(T &)) {
	for (size_t i = 0; i < size; i++)
		func(arr[i]);
}

template <typename T>
void increment(T &data) {
	data++;
}

template <typename T>
void display(T &data) {
	std::cout << data << "  ";
}

#endif