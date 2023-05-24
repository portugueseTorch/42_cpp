#include "../inc/Fixed.hpp"
#include "../inc/Point.hpp"

int main() {
	{
		Point a(0.0f, 0.0f);
		Point b(10.0f, 0.0f);
		Point c(5.0f, 10.0f);
		Point test(5.0f, 10.0f);
		std::cout << bsp(a, b, c, test) << std::endl;
	}

	{
		Point a(0.0f, -10.0f);
		Point b(-10.0f, 3.0f);
		Point c(4.0f, 10.0f);
		Point test(0.0f, 0.0f);
		std::cout << bsp(a, b, c, test) << std::endl;
	}

	return 0;
}

