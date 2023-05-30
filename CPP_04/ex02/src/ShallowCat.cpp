#include "../inc/ShallowCat.hpp"

ShallowCat::ShallowCat() {
	_type = "ShallowCat";
	_brain = new Brain;
	std::cout << "ShallowCat default constructor called" << std::endl;
}

ShallowCat::ShallowCat(const ShallowCat &obj) {
	*this = obj;
	std::cout << "Copy ShallowCat constructor called" << std::endl;
}

ShallowCat	&ShallowCat::operator=(const ShallowCat &obj) {
	if (this == &obj)
		return *this;
	std::cout << "Copy ShallowCat assignment operator called" << std::endl;
	_type = obj.getType();
	_brain = obj._brain;
	return *this;
}

ShallowCat::~ShallowCat() {
	std::cout << "ShallowCat destructor called" << std::endl;
	delete _brain;
}

void	ShallowCat::makeSound() const {
	std::cout << "The ShallowCat goes meow" << std::endl;
}

Brain &ShallowCat::getBrain() const {
	return *_brain;
}
