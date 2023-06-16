#pragma once
#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <algorithm>
# include <stack>
# include <exception>
# include <cstring>

# define debug(x) std::cout << x << std::endl;

class RPN
{
	public:
		RPN();
		RPN(std::string expression);
		RPN(const RPN &obj);
		RPN &operator=(const RPN &obj);
		~RPN();

		// GETTERS AND SETTERS
		std::string getExpression() const;
		std::stack<int> getStack() const;
		int getResult() const;
		void setExpression(std::string expression);

		// ENGINE
		void calculate();

		// EXCEPTIONS
		class MissingExpressionException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class ErrorException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

	private:
		std::stack<int> _stack;
		std::string _expression;
		int _result;
		void performOperation(char oper);
		static void validateInput(std::string expression);
};

#endif
