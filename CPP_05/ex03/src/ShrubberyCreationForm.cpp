#include "../inc/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): _target("Unspecified") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("Shrubbery Creation Form", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj): AForm("Shrubbery Creation Form", 145, 137) {
	*this = obj;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj) {
	if (this == &obj)
		return *this;
	_target = obj.getTarget();
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

const std::string &ShrubberyCreationForm::getTarget() const {
	return _target;
}

const char *ShrubberyCreationForm::FileOpenException::what() const throw() {
	return "Error: failure opening file";
}

void ShrubberyCreationForm::concreteExecute() const {
	std::ofstream	out_file;

	out_file.open((_target + "_shrubbery").c_str(), std::ios::trunc);
	if (!out_file.is_open())
		throw FileOpenException();
	out_file << "       ###\n\
      #o###\n\
    #####o###\n\
   #o#\\#|#/###\n\
    ###\\|/#o#\n\
     # }|{  #\n\
       }|{" << std::endl;
	out_file.close();
}