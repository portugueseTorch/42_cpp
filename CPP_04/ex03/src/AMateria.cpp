#include "../inc/AMateria.hpp"

AMateria::AMateria(): _type("none") {}

AMateria::AMateria(std::string const &type): _type(type) {}

AMateria::AMateria(const AMateria &obj): _type("none") {
	*this = obj;
}

AMateria &AMateria::operator=(const AMateria &obj) {
	if (this == &obj)
		return *this;
	_type = obj.getType();
	return *this;
}

AMateria::~AMateria() {}

std::string const &AMateria::getType() const {
	return _type;
}

void AMateria::use(ICharacter& target) {
	(void) target;
}
