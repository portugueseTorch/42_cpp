#pragma once
#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <algorithm>
# include <vector>
# include <list>
# include <time.h>
# include <exception>
# include <limits.h>
# include <ctime>

template <typename T>
bool sorted(T &container) {
	typename T::iterator it = t.begin();
	typename T::iterator ite = t.end;
	for (; it != ite; it++) {
		if ((it + 1) != ite && *it > *(it + 1))
			return false;
	}
	return true;
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
		std::list<int> _lst;
		std::vector<std::string> _numbers;

		void validateInput();
		void mergeSortList();
		void mergeSortVector();
};

#endif
