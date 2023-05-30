#include "../inc/Animal.hpp"
#include "../inc/Cat.hpp"
#include "../inc/Dog.hpp"
#include "../inc/WrongAnimal.hpp"
#include "../inc/WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	const WrongAnimal *lamina = new WrongAnimal();
	const WrongAnimal *tac = new WrongCat();

	std::cout << "\nGeneric Animal:" <<
	"\n    Type: " << meta->getType() <<
	"\n    Sound: "; meta->makeSound();

	std::cout << "\nDog:" <<
	"\n    Type: " << dog->getType() <<
	"\n    Sound: "; dog->makeSound();

	std::cout << "\nCat:" <<
	"\n    Type: " << cat->getType() <<
	"\n    Sound: "; cat->makeSound();

	std::cout << "\nWrong Animal:" <<
	"\n    Type: " << lamina->getType() <<
	"\n    Sound: "; lamina->makeSound();

	std::cout << "\nWrong Cat:" <<
	"\n    Type: " << tac->getType() <<
	"\n    Sound: "; tac->makeSound();

	std::cout << std::endl;

	delete meta;
	delete dog;
	delete cat;
	delete lamina;
	delete tac;
	return 0;
}