#include "../inc/Ice.hpp"

Ice::Ice(): AMateria("ice") {}

Ice::Ice(const Ice &obj): AMateria(obj) {
	*this = obj;
}

Ice &Ice::operator=(const Ice &obj) {
	if (this == &obj)
		return *this;
	_type = obj.getType();
	return *this;
}

Ice::~Ice() {}

AMateria *Ice::clone() const {
	AMateria *ice = new Ice;
	return ice;
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
