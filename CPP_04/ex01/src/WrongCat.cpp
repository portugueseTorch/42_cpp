#include "../inc/WrongCat.hpp"

WrongCat::WrongCat() {
	_type = "Wrong Cat";
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &obj) {
	*this = obj;
	std::cout << "Copy WrongCat constructor called" << std::endl;
}

WrongCat	&WrongCat::operator=(const WrongCat &obj) {
	if (this == &obj)
		return *this;
	std::cout << "Copy WrongCat assignment operator called" << std::endl;
	_type = obj.getType();
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called" << std::endl;
}

void	WrongCat::makeSound() const {
	std::cout << "The WrongCat goes hgsfkjdsg" << std::endl;
}
