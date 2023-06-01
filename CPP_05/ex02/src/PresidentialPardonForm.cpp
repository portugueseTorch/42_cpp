#include "../inc/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): _target("Unspecified") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("Presidential Pardon Form", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj) {
	*this = obj;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &obj) {
	if (this == &obj)
		return *this;
	_target = obj.getTarget();
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

const std::string &PresidentialPardonForm::getTarget() const {
	return _target;
}

void PresidentialPardonForm::concreteExecute() const {
	std::cout << "    ✅ " << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
