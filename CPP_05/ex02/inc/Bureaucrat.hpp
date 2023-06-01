#pragma once
#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
	public:
		// Constructors and Destructors
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &obj);
		Bureaucrat &operator=(const Bureaucrat &obj);
		~Bureaucrat();

		// Dynamic Exceptions
		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		// Member Functions
		const std::string	&getName() const;
		int					getGrade() const;
		void				incrementGrade();
		void				decrementGrade();
		void				signForm(AForm &form);
		void				executeForm(AForm const & form);

	private:
		const std::string _name;
		int _grade;
};

std::ostream &operator<<(std::ostream &stream, const Bureaucrat &obj);

#endif
