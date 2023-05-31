#pragma once
#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
		// Constructors and Destructors
		Form();
		Form(std::string name, int sign_grade, int exec_grade);
		Form(const Form &obj);
		Form &operator=(const Form &obj);
		~Form();

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

		// Getters
		const std::string	&getName() const;
		bool				getSignedStatus() const;
		int					getSignGrade() const;
		int					getExecGrade() const;
		
		// Member Functions
		void				beSigned(Bureaucrat &obj);

	private:
		const std::string	_name;
		bool				_signed;
		const int			_sign_grade;
		const int			_exec_grade;
};

std::ostream &operator<<(std::ostream &stream, const Form &obj);

#endif
