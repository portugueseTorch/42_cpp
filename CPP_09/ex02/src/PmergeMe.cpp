#include "../inc/PmergeMe.hpp"

PmergeMe::PmergeMe(std::vector<std::string> numbers): _numbers(numbers) {
	_even = numbers.size() % 2 == 0 ? true : false;
}

PmergeMe::PmergeMe(const PmergeMe &obj) { *this = obj; }

PmergeMe &PmergeMe::operator=(const PmergeMe &obj) {
	if (this == &obj)
		return *this;
	_numbers = obj._numbers;
	_vec = obj._vec;
	_lst = obj._lst;
	return *this;
}

PmergeMe::~PmergeMe() {}

///////////////////////////////////////

void PmergeMe::merge() {
	try {
		validateInput();
		
		// lst sort
		clock_t lst_start = clock();
		mergeSortList();
		clock_t lst_finish = clock() - lst_start;


		// vec sort
		clock_t vec_start = clock();
		mergeSortVector();
		clock_t vec_finish = clock() - vec_start;

		std::cout << "Before:\t";
		display(_numbers);
		std::cout << std::endl;

		std::cout << "After:\t";
		display(_vec_sorted);
		std::cout << std::endl;

		std::cout << "Time to process a range of " << _vec_sorted.size() \
			<< " elements with std::vector : " << (static_cast<double> (vec_finish) / (CLOCKS_PER_SEC)) * 1000000.0 << " us" << std::endl;
		std::cout << "Time to process a range of " << _vec_sorted.size() \
			<< " elements with std::list : " << (static_cast<double> (lst_finish) / (CLOCKS_PER_SEC)) * 1000000.0 << " us" << std::endl;

	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		exit (EXIT_FAILURE);
	}
}

void PmergeMe::validateInput() {
	std::vector<std::string>::iterator it = _numbers.begin();
	std::vector<std::string>::iterator ite = _numbers.end();

	for (; it != ite; it++) {
		if (it->find_first_not_of("0123456789+") != std::string::npos || \
			it->find_first_of('+') != it->find_last_of('+') || \
			strtol(it->c_str(), NULL, 10) > INT_MAX)
			throw ErrorException();
		int num = atoi(it->c_str());
		_vec.push_back(num);
		_lst.push_back(num);
	}
}

void PmergeMe::mergeSortList() {
	if (sorted(_lst)) {
		_lst_sorted = _lst;
		return;
	}

	std::list<std::pair<int,int> > pairs;
	if (_even) {
		for (std::list<int>::iterator it = _lst.begin(); it != _lst.end(); it++) {
			if (++it != _lst.end()) {
				if (*it > *(--it)) {
					pairs.push_back(std::make_pair(*(++it), *(--it)));
					it++;
				}
				else
					pairs.push_back(std::make_pair(*it, *(++it)));
			}
		}
	} else {
		for (std::list<int>::iterator it = _lst.begin(); it != --_lst.end(); it++) {
			if (++it != --_lst.end()) {
				if (*it > *(--it)) {
					pairs.push_back(std::make_pair(*(++it), *(--it)));
					it++;
				}
				else
					pairs.push_back(std::make_pair(*it, *(++it)));
			}
		}
		_lst_sorted.push_back(_lst.back());
	}

	for (std::list<std::pair<int,int> >::iterator it = pairs.begin(); it != pairs.end(); it++)
		_lst_sorted.insert(std::lower_bound(_lst_sorted.begin(), _lst_sorted.end(), it->first), it->first);

	for (std::list<std::pair<int,int> >::iterator it = pairs.begin(); it != pairs.end(); it++)
		_lst_sorted.insert(std::lower_bound(_lst_sorted.begin(), _lst_sorted.end(), it->second), it->second);
}

void PmergeMe::mergeSortVector() {
	if (sorted(_vec)) {
		_vec_sorted = _vec;
		return;
	}

	std::vector<std::pair<int,int> > pairs;
	if (_even) {
		for (size_t i = 0; i < _vec.size(); i += 2) {
			if (_vec[i] > _vec[i + 1])
				pairs.push_back(std::make_pair(_vec[i], _vec[i + 1]));
			else
				pairs.push_back(std::make_pair(_vec[i + 1], _vec[i]));
		}
	} else {
		for (size_t i = 0; i < _vec.size() - 1; i += 2) {
			if (_vec[i] > _vec[i + 1])
				pairs.push_back(std::make_pair(_vec[i], _vec[i + 1]));
			else
				pairs.push_back(std::make_pair(_vec[i + 1], _vec[i]));
		}
		_vec_sorted.push_back(_vec.back());
	}

	for (size_t i = 0; i < pairs.size(); i++)
		_vec_sorted.insert(std::lower_bound(_vec_sorted.begin(), _vec_sorted.end(), pairs[i].first), pairs[i].first);

	for (size_t i = 0; i < pairs.size(); i++)
		_vec_sorted.insert(std::lower_bound(_vec_sorted.begin(), _vec_sorted.end(), pairs[i].second), pairs[i].second);
}


///////////////////////////////////////

void PmergeMe::addNumber(std::string num) {
	_numbers.push_back(num);
}

///////////////////////////////////////

const char *PmergeMe::ErrorException::what() const throw() {
	return "Error";
}
