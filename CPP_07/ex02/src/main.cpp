#include <iostream>
#include <cstdlib>
#include "../inc/Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
	std::cout << "\tTESTING STRING ALLOCATION" << std::endl;
	{
		Array<std::string> tracks(5);

		tracks[0] = std::string("É Só Inveja");
		tracks[1] = std::string ("Adolfo Dias");
		tracks[2] = std::string ("O Peixe");
		tracks[3] = std::string ("Chupa Teresa");
		tracks[4] = std::string ("Cabritinha");
		
		for (int i = 0; i < 5; i++)
			std::cout << i + 1 << ". " << tracks[i] << std::endl;
	}

	std::cout << "\n\tTESTING POINTER ALLOCATION" << std::endl;
	{
		Array<std::string *> tracks(5);

		tracks[0] = new std::string("É Só Inveja");
		tracks[1] = new std::string ("Adolfo Dias");
		tracks[2] = new std::string ("O Peixe");
		tracks[3] = new std::string ("Chupa Teresa");
		tracks[4] = new std::string ("Cabritinha");
		
		for (int i = 0; i < 5; i++)
			std::cout << i + 1 << ". " << *tracks[i] << "\t\t(" << tracks[i] << ")" << std::endl;
		
		for (int i = 0; i < 5; i++)
			delete tracks[i];
	}

	std::cout << "\n\tMAIN FROM THE SUBJECT" << std::endl;
	{
		Array<int> numbers(MAX_VAL);
		int* mirror = new int[MAX_VAL];
		srand(time(NULL));
		for (int i = 0; i < MAX_VAL; i++)
		{
			const int value = rand();
			numbers[i] = value;
			mirror[i] = value;
		}
		//SCOPE
		{
			Array<int> tmp = numbers;
			Array<int> test(tmp);
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			if (mirror[i] != numbers[i])
			{
				std::cerr << "didn't save the same value!!" << std::endl;
				return 1;
			}
		}
		std::cout << "Success: mirror and numbers are equal" << std::endl;
		try
		{
			numbers[-2] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			numbers[MAX_VAL] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			numbers[i] = rand();
		}
		delete [] mirror;//
	}
    return 0;
}