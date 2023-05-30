#include "../inc/Animal.hpp"
#include "../inc/Cat.hpp"
#include "../inc/Dog.hpp"
#include "../inc/WrongAnimal.hpp"
#include "../inc/WrongCat.hpp"
#include "../inc/ShallowCat.hpp"
#include <exception>

int main()
{
	std::cout << "\n-------------------------------------------" << std::endl;
	std::cout << "\n\tTESTING ARRAY:\n" << std::endl;
	{
		int	num_animals = 4;
		const Animal *animal_array[num_animals];

		for (int i = 0; i < num_animals; i++) {
			if (i < (num_animals / 2))
				animal_array[i] = new Dog;
			else
				animal_array[i] = new Cat;
		}
		std::cout << std::endl;
		for (int i = 0; i < num_animals; i++) {
			std::cout << "ANIMAL " << i + 1 << std::endl;
			std::cout << "   Type: " << animal_array[i]->getType() << "\n   Sound: ";
			animal_array[i]->makeSound();
		}
		std::cout << std::endl;
		for (int i = 0; i < num_animals; i++) {
			delete animal_array[i];
			std::cout << std::endl;
		}
	}

	std::cout << "\n-------------------------------------------" << std::endl;
	std::cout << "\n\tTESTING DEEP COPY\n" << std::endl;
	{
		Cat Batatinha;

		Batatinha.getBrain().setIdea("I think I might beat the crap out of my co-host.");
		Cat Companhia = Batatinha;
		std::cout << std::endl;
		std::cout << "Batatinha's ideas:" << std::endl;
		Batatinha.getBrain().displayIdeas();
		std::cout << "Companhia's ideas:" << std::endl;
		Companhia.getBrain().displayIdeas();

		std::cout << std::endl;
		Batatinha.getBrain().setIdea("There's no way this would ruin our show, right?...");
		std::cout << "Batatinha's ideas:" << std::endl;
		Batatinha.getBrain().displayIdeas();
		std::cout << "Companhia's ideas:" << std::endl;
		Companhia.getBrain().displayIdeas();
	}

	// std::cout << "\n-------------------------------------------" << std::endl;
	// std::cout << "\n\tTESTING SHALLOW COPY\n" << std::endl;
	// {
	// 	ShallowCat Batatinha;

	// 	Batatinha.getBrain().setIdea("I think I might beat the crap out of my co-host");
	// 	ShallowCat Companhia = Batatinha;
	// 	std::cout << std::endl;
	// 	std::cout << "Batatinha's ideas:" << std::endl;
	// 	Batatinha.getBrain().displayIdeas();
	// 	std::cout << "Companhia's ideas:" << std::endl;
	// 	Companhia.getBrain().displayIdeas();

	// 	std::cout << std::endl;
	// 	Batatinha.getBrain().setIdea("I guess we share the same brain. We're one and the same.");
	// 	std::cout << "Batatinha's ideas:" << std::endl;
	// 	Batatinha.getBrain().displayIdeas();
	// 	std::cout << "Companhia's ideas:" << std::endl;
	// 	Companhia.getBrain().displayIdeas();
	// }
	return 0;
}