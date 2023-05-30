#include "../inc/Dog.hpp"

Dog::Dog() {
	_type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &obj) {
	*this = obj;
	std::cout << "Copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &obj) {
	if (this == &obj)
		return *this;
	std::cout << "Copy Dog assignment operator called" << std::endl;
	_type = obj.getType();
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
}

void	Dog::makeSound() const {
	std::cout << "The Dog goes woof" << std::endl;
}
