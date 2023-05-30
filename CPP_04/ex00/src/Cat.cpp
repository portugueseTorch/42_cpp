#include "../inc/Cat.hpp"

Cat::Cat() {
	_type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &obj) {
	*this = obj;
	std::cout << "Copy Cat constructor called" << std::endl;
}

Cat	&Cat::operator=(const Cat &obj) {
	if (this == &obj)
		return *this;
	std::cout << "Copy Cat assignment operator called" << std::endl;
	_type = obj.getType();
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
}

void	Cat::makeSound() const {
	std::cout << "The Cat goes meow" << std::endl;
}
