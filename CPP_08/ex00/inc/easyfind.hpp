#pragma once
#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>
# include <vector>
# include <exception>

class NotFoundException: public std::exception
{
	public:
		virtual const char* what() const throw() { return "Needle not found"; }
};

template <typename T>
typename T::iterator easyfind(T &haystack, int needle) {
	typename T::iterator it = std::find(haystack.begin(), haystack.end(), needle);
	if (it != haystack.end())
		return it;
	throw NotFoundException();
}

#endif