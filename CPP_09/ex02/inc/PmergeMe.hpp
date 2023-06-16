#pragma once
#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <algorithm>
# include <vector>
# include <list>
# include <time.h>

class PmergeMe
{
	public:
		PmergeMe(std::string numbers);
		PmergeMe(const PmergeMe &obj);
		PmergeMe &operator=(const PmergeMe &obj);
		~PmergeMe();

	private:
		
};

#endif
