#include "../inc/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("Unspecified"), _grade(150) {}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name) {
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj): _name(obj.getName()) {
	_grade = obj.getGrade();
	if (_grade < 1)
		throw GradeTooHighException();
	else if (_grade > 150)
		throw GradeTooLowException();
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &obj) {
	if (this == &obj)
		return *this;
	_grade = obj.getGrade();
	if (_grade < 1)
		throw GradeTooHighException();
	else if (_grade > 150)
		throw GradeTooLowException();
	return *this;
}

Bureaucrat::~Bureaucrat() {}

const std::string &Bureaucrat::getName() const {
	return _name;
}

int	Bureaucrat::getGrade() const {
	return _grade;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "grade is too low";
}

void Bureaucrat::incrementGrade() {
	_grade--;
	if (_grade < 1)
		throw GradeTooHighException();
}

void Bureaucrat::decrementGrade() {
	_grade++;
	if (_grade > 150)
		throw GradeTooLowException();
}

void Bureaucrat::signForm(AForm &form) {
	try {
		form.beSigned(*this);
		std::cout << "    ✅ " << _name << " signed " << form.getName();
	} catch (AForm::FormAlreadySignedException &e) {
		std::cout << "    🟨 " << e.what();
	} catch (std::exception &e) {
		std::cout << "    ❌ " << _name << " couldn't sign " << form.getName() << " because " << e.what();
	}
}

void Bureaucrat::executeForm(AForm const &form) {
	try {
		form.execute(*this);
		std::cout << "    ✅ " << _name << " executed " << form.getName();
	} catch (std::exception &e) {
		std::cout << "    ❌ " << _name << " couldn't execute " << form.getName() << " because " << e.what();
	}
}

std::ostream &operator<<(std::ostream &stream, const Bureaucrat &obj) {
	stream << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return stream;
}
