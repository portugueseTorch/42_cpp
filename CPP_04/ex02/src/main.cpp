#include "../inc/Animal.hpp"
#include "../inc/Cat.hpp"
#include "../inc/Dog.hpp"
#include "../inc/WrongAnimal.hpp"
#include "../inc/WrongCat.hpp"
#include "../inc/ShallowCat.hpp"
#include <exception>

int main()
{
	{
		const Animal* dog = new Dog;
		const Animal* cat = new Cat;
		// const Animal animal;

		std::cout << std::endl;
		dog->makeSound();
		cat->makeSound();
		std::cout << std::endl;
		delete dog;
		delete cat;
	}
	return 0;
}