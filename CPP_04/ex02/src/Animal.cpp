#include "../inc/Animal.hpp"

Animal::Animal(): _type("Generic Animal") {
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal &obj) {
	*this = obj;
	std::cout << "Copy constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &obj) {
	if (this == &obj)
		return *this;
	std::cout << "Copy assignment operator called" << std::endl;
	_type = obj._type;
	return *this;
}

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType() const {
	return _type;
}
