#include "../inc/PmergeMe.hpp"

PmergeMe::PmergeMe(std::vector<std::string> numbers): _numbers(numbers) {}

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
	if (sorted(_lst))
		return ;
}

void PmergeMe::mergeSortVector() {

}


///////////////////////////////////////

void PmergeMe::addNumber(std::string num) {
	_numbers.push_back(num);
}

///////////////////////////////////////

const char *PmergeMe::ErrorException::what() const throw() {
	return "Error";
}
