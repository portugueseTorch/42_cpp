#include "../inc/RobotomyRequestForm.hpp"
# include <cstdlib>
# include <time.h>

RobotomyRequestForm::RobotomyRequestForm(): _target("Unspecified") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("Robotomy Request", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj) {
	*this = obj;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &obj) {
	if (this == &obj)
		return *this;
	_target = obj.getTarget();
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

const std::string &RobotomyRequestForm::getTarget() const {
	return _target;
}

void RobotomyRequestForm::concreteExecute() const {
	std::cout << "    ✅ Mip morp zeeeeeet" << std::endl;
	srand(time(NULL));
	if (rand() % 2)
		std::cout << "    ✅ " << _target << " has been robotomized successfully!" << std::endl;
	else
		std::cout << "    ❌ " << _target << " robotomy failed." << std::endl;
}
