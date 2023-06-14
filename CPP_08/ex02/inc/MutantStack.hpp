#pragma once
#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <algorithm>
# include <stack>

template <class T>
class MutantStack: public std::stack
{
	public:
		MutantStack<T>() {  };
		MutantStack<T>(unsigned int size) {  };
		MutantStack<T>(const MutantStack &obj) {};
		MutantStack<T> &operator=(const MutantStack &obj) {};

	private:
		
};

#endif