#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
	public:
		Animal();
		Animal(const Animal &obj);
		Animal &operator=(const Animal &obj);
		virtual ~Animal();

		std::string getType() const;

		virtual void makeSound() const = 0;
	protected:
		std::string _type;
};

#endif
