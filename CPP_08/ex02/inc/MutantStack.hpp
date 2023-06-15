#pragma once
#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <algorithm>
# include <stack>
# include <list>
# include <iterator>

template <typename T>
void display(T &container) {
	typename T::iterator it = container.begin();
	typename T::iterator ite = container.end();
	std::cout << "{  ";
	for (; it != ite; it++) {
		std::cout << *it << "  ";
	}
	std::cout << "}" << std::endl;
}

template <class T>
class MutantStack: public std::stack<T>
{
	public:
		MutantStack<T>() {};
		~MutantStack<T>() {};

		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

		iterator begin() { return this->c.begin(); }
		iterator end() { return this->c.end(); }
		reverse_iterator rbegin() { return this->c.rbegin(); }
		reverse_iterator rend() { return this->c.rend(); }
		const_iterator cbegin() { return this->c.cbegin(); }
		const_iterator cend() { return this->c.cend(); }
		const_reverse_iterator crbegin() { return this->c.crbegin(); }
		const_reverse_iterator crend() { return this->c.crend(); }

};

#endif