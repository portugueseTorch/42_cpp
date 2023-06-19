#pragma once
#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <algorithm>
# include <vector>
# include <list>
# include <utility>
# include <time.h>
# include <exception>
# include <limits.h>
# include <ctime>

# define debug(x) std::cout << x << std::endl

template <typename T>
bool sorted(T &container) {
	if (container.size() == 1)
		return true;
	typename T::iterator it = container.begin();
	typename T::iterator ite = container.end();
	for (; it != ite; it++) {
		if ((++it) != ite && *(--it) > *(++it))
			return false;
		--it;
	}
	return true;
}

template <typename T>
void display(T &container) {
	typename T::iterator it = container.begin();
	typename T::iterator ite = container.end();
	for (; it != ite; it++) {
		std::cout << *it << " ";
	}
}

class PmergeMe
{
	public:
		PmergeMe(std::vector<std::string> numbers);
		PmergeMe(const PmergeMe &obj);
		PmergeMe &operator=(const PmergeMe &obj);
		~PmergeMe();

		void addNumber(std::string num);

		void merge();

		class ErrorException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

	private:
		std::vector<int> _vec;
		std::vector<int> _vec_sorted;

		std::list<int> _lst;
		std::list<int> _lst_sorted;

		std::vector<std::string> _numbers;

		bool _even;

		void validateInput();
		void mergeSortList();
		void mergeSortVector();
};

#endif
