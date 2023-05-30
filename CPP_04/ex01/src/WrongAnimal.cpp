#include "../inc/WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): _type("Wrong Animal") {
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &obj) {
	*this = obj;
	std::cout << "Copy constructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &obj) {
	if (this == &obj)
		return *this;
	std::cout << "Copy assignment operator called" << std::endl;
	_type = obj._type;
	return *this;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor called" << std::endl;
}

std::string WrongAnimal::getType() const {
	return _type;
}

void WrongAnimal::makeSound() const {
	std::cout << "Generic WrongAnimal noises" << std::endl;
}
