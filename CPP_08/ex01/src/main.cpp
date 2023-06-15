#include "../inc/Span.hpp"

int main() {
	{
		Span span(30);
		span.addNumber(1, 10);
		span.addNumber(4, 14);
		span.addNumber(5, -2, 84);
		std::cout << span << std::endl;

		std::cout << "Longest Span: " << span.longestSpan() << std::endl;
		std::cout << "Shortest Span: " << span.shortestSpan() << std::endl;
		std::cout << std::endl;
	}
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(1);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp << std::endl;
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
	}
}