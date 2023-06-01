#pragma once
#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern &obj);
		Intern &operator=(const Intern &obj);
		~Intern();

		AForm *makeForm(std::string form_type, std::string target);
	private:
		AForm *makePresidential(std::string target);
		AForm *makeRobotomy(std::string target);
		AForm *makeShrubbery(std::string target);
};

#endif
