#include "../inc/iter.hpp"

int main() {
	int arr1[] = { 0, 4, 2, -6, 8, 10, 32 };
	float arr2[] = { 0.2, 2.1, -2.1, -3.9, 8.0, 10, -92.56 };
	std::string arr3[] = { "Hello", "World", "Goodbye" };

	std::cout << "Array 1:" << std::endl;
	::iter(arr1, 6, increment);
	::iter(arr1, 6, display);
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Array 2:" << std::endl;
	::iter(arr2, 6, increment);
	::iter(arr2, 6, display);
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Array 3:" << std::endl;
	::iter(arr3, 3, display);
	std::cout << std::endl;
}