#include "../inc/Span.hpp"

Span::Span(): _capacity(0) {}

Span::Span(unsigned int capacity): _capacity(capacity) {}

Span::Span(const Span &obj) { *this = obj; }

Span &Span::operator=(const Span &obj) {
	if (this == &obj)
		return *this;
	_capacity = obj._capacity;
	if (!_vec.empty())
		_vec.clear();
	_vec = obj._vec;
	return *this;
}

Span::~Span() {}

unsigned int Span::getCapacity() const {
	return _capacity;
}

const std::vector<int> &Span::getVector() const {
	return _vec;
}

/////////////////////////////////////////////////

void Span::addNumber() {
	if (_vec.size() >= _capacity)
		throw CapacityReachedException();
	srand(time(NULL));
	_vec.push_back(rand());
}

void Span::addNumber(int number) {
	if (_vec.size() >= _capacity)
		throw CapacityReachedException();
	_vec.push_back(number);
}

void Span::addNumber(int start, int end) {
	if (_vec.size() >= _capacity)
		throw CapacityReachedException();
	if (start < end) {
		for (int i = start; i <= end && _vec.size() < _capacity; i++)
			_vec.push_back(i);
	} else {
		for (int i = start; i >= end && _vec.size() < _capacity; i--)
			_vec.push_back(i);
	}
}

void Span::addNumber(int reps, int floor, int ceiling) {
	if (_vec.size() >= _capacity)
		throw CapacityReachedException();
	int range;
	if (floor < ceiling) {
		range = ceiling - floor;
		srand(time(NULL));
		for (int i = 0; i < reps && _vec.size() < _capacity; i++) {
			_vec.push_back(rand() % range + floor);
		}
	} else if (floor > ceiling) {
		range = floor - ceiling;
		srand(time(NULL));
		for (int i = 0; i < reps && _vec.size() < _capacity; i++) {
			_vec.push_back(rand() % range + ceiling);
		}
	} else {
		for (int i = 0; i < reps && _vec.size() < _capacity; i++)
			_vec.push_back(0);
	}
}

/////////////////////////////////////////////////

const char *Span::CapacityReachedException::what() const throw() {
	return "Container at full capacity";
}

const char *Span::NoSpanException::what() const throw() {
	return "No span found";
}

/////////////////////////////////////////////////
int Span::shortestSpan() {
	if (_vec.empty() || _vec.size() == 1)
		throw NoSpanException();
	std::vector<int> sorted = _vec;
	std::sort(sorted.begin(), sorted.end());

	std::vector<int> diffs(sorted.size());
	std::adjacent_difference(sorted.begin(), sorted.end(), diffs.begin());

	return *(std::min_element(++diffs.begin(), diffs.end()));
}

int Span::longestSpan() {
	if (_vec.empty() || _vec.size() == 1)
		throw NoSpanException();
	std::vector<int> sorted = _vec;
	std::sort(sorted.begin(), sorted.end());
	return sorted.back() - sorted.front();
}

std::ostream &operator<<(std::ostream &stream, const Span &obj) {
	stream << "{ ";
	for (unsigned int i = 0; i < obj.getVector().size(); i++) {
		stream << obj.getVector().at(i);
		i != obj.getVector().size() - 1 ? stream << ", " : stream << " ";
	}
	stream << "}";
	return stream;
}
