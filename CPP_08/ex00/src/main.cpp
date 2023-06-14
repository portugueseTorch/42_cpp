#include "../inc/easyfind.hpp"

int main() {
	int arr1[] = { 0, 10, 20, 30, 40, 50 };
	int needle;
	{
		std::vector<int> vec1(arr1, arr1 + (sizeof(arr1) / sizeof(*arr1)));
		try
		{
			needle = 30;
			std::vector<int>::iterator it = easyfind(vec1, needle);
			std::cout << "Needle found: " << *it << std::endl;
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		try
		{
			needle = -30;
			std::vector<int>::iterator it = easyfind(vec1, needle);
			std::cout << "Needle found: " << *it << std::endl;
		}
		catch (std::exception &e) {
			std::cout << e.what() << ": " << needle << std::endl;
		}
	}
}