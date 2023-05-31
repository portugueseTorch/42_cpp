#pragma once
#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	public:
		// Constructors and Destructors
		AForm();
		AForm(std::string name, int sign_grade, int exec_grade);
		AForm(const AForm &obj);
		AForm &operator=(const AForm &obj);
		virtual ~AForm();

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

	protected:
		virtual void execute(Bureaucrat const & executor) const = 0;

	private:
		const std::string	_name;
		bool				_signed;
		const int			_sign_grade;
		const int			_exec_grade;
};

std::ostream &operator<<(std::ostream &stream, const AForm &obj);

#endif
