#include "../inc/AForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"

///// CONSTRUCTORS AND DESTRUCTORS /////
AForm::AForm(): _name("Template AForm"), _sign_grade(150), _exec_grade(150) {}

AForm::AForm(std::string name, int sign_grade, int exec_grade): _name(name), _signed(false) , _sign_grade(sign_grade), _exec_grade(exec_grade) {
	if (_sign_grade < 1 || _exec_grade < 1)
		throw GradeTooHighException();
	else if (_sign_grade > 150 || _exec_grade > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &obj): _name(obj.getName()), _signed(obj.getSignedStatus()), _sign_grade(obj.getSignGrade()), _exec_grade(obj.getExecGrade()) {
	if (_sign_grade < 1 || _exec_grade < 1)
		throw GradeTooHighException();
	else if (_sign_grade > 150 || _exec_grade > 150)
		throw GradeTooLowException();
}

AForm &AForm::operator=(const AForm &obj) {
	_signed = obj.getSignedStatus();
	return *this;
}

AForm::~AForm() {}

///// DYNAMIC EXCEPTIONS /////
const char *AForm::GradeTooLowException::what() const throw() {
	return "grade is too low";
}

const char *AForm::GradeTooHighException::what() const throw() {
	return "grade is too high";
}

const char *AForm::FormNotSignedException::what() const throw() {
	return "Form is not signed";
}

const char *AForm::FormAlreadySignedException::what() const throw() {
	return "Form is already signed";
}

///// GETTERS /////
const std::string &AForm::getName() const {
	return _name;
}

bool AForm::getSignedStatus() const {
	return _signed;
}

int AForm::getSignGrade() const {
	return _sign_grade;
}

int AForm::getExecGrade() const {
	return _exec_grade;
}

///// MEMBER FUNCTIONS /////
void AForm::beSigned(Bureaucrat &obj) {
	if (_sign_grade < obj.getGrade())
		throw GradeTooLowException();
	else if (_signed)
		throw FormAlreadySignedException();
	_signed = true;
}

void AForm::execute(Bureaucrat const &executor) const {
	if (!this->getSignedStatus())
		throw FormNotSignedException();
	else if (this->getExecGrade() < executor.getGrade())
		throw GradeTooLowException();
	try { concreteExecute(); } 
	catch (ShrubberyCreationForm::FileOpenException &e) { throw e; }
}

///// << OVERLOADER /////
std::ostream &operator<<(std::ostream &stream, const AForm &obj) {
	stream << "[ AFORM INFO ]" << std::endl;
	stream << "Name:\t\t" << obj.getName() << std::endl;
	stream << "Signed:\t\t" << obj.getSignedStatus() << std::endl;
	stream << "Min. signing grade:\t" << obj.getSignGrade() << std::endl;
	stream << "Min. execution grade:\t" << obj.getExecGrade() << std::endl;
	return stream;
}
