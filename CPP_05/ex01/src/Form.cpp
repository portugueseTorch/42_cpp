#include "../inc/Form.hpp"

///// CONSTRUCTORS AND DESTRUCTORS /////
Form::Form(): _name("Template Form"), _sign_grade(150), _exec_grade(150) {}

Form::Form(std::string name, int sign_grade, int exec_grade): _name(name), _signed(false) , _sign_grade(sign_grade), _exec_grade(exec_grade) {
	if (_sign_grade < 1 || _exec_grade < 1)
		throw GradeTooHighException();
	else if (_sign_grade > 150 || _exec_grade > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &obj): _name(obj.getName()), _signed(obj.getSignedStatus()), _sign_grade(obj.getSignGrade()), _exec_grade(obj.getExecGrade()) {
	if (_sign_grade < 1 || _exec_grade < 1)
		throw GradeTooHighException();
	else if (_sign_grade > 150 || _exec_grade > 150)
		throw GradeTooLowException();
}

Form &Form::operator=(const Form &obj) {
	_signed = obj.getSignedStatus();
	return *this;
}

Form::~Form() {}

///// DYNAMIC EXCEPTIONS /////
const char *Form::GradeTooLowException::what() const throw() {
	return "grade is too low";
}

const char *Form::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

///// GETTERS /////
const std::string &Form::getName() const {
	return _name;
}

bool Form::getSignedStatus() const {
	return _signed;
}

int Form::getSignGrade() const {
	return _sign_grade;
}

int Form::getExecGrade() const {
	return _exec_grade;
}

///// MEMBER FUNCTIONS /////
void Form::beSigned(Bureaucrat &obj) {
	if (_sign_grade < obj.getGrade())
		throw GradeTooLowException();
	_signed = true;
}

///// << OVERLOADER /////
std::ostream &operator<<(std::ostream &stream, const Form &obj) {
	stream << "[ FORM INFO ]" << std::endl;
	stream << "Name:\t\t" << obj.getName() << std::endl;
	stream << "Signed:\t\t" << obj.getSignedStatus() << std::endl;
	stream << "Min. signing grade:\t" << obj.getSignGrade() << std::endl;
	stream << "Min. execution grade:\t" << obj.getExecGrade() << std::endl;
	return stream;
}
