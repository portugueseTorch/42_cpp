#pragma once
#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <algorithm>
# include <vector>
# include <exception>
# include <time.h>
# include <numeric>

class Span
{
	public:
		// CONSTRUCTORS
		Span();
		Span(unsigned int capacity);
		Span(const Span &obj);
		Span &operator=(const Span &obj);

		// DESTRUCTORS
		~Span();

		// GETTERS
		unsigned int getCapacity() const;
		const std::vector<int> &getVector() const;

		// ADD NUMBERS
		void addNumber();
		void addNumber(int number);
		void addNumber(int start, int end);
		void addNumber(int reps, int floor, int ceiling);

		// SPAN FUNCTIONS
		int shortestSpan();
		int longestSpan();

		// EXCEPTIONS
		class CapacityReachedException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class NoSpanException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
	private:
		unsigned int _capacity;
		std::vector<int> _vec;
};

std::ostream &operator<<(std::ostream &stream, const Span &obj);

#endif
