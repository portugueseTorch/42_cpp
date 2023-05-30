#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat: virtual public Animal
{
	public:
		Cat();
		Cat(const Cat &obj);
		Cat &operator=(const Cat &obj);
		~Cat();

		virtual void	makeSound() const;
};

#endif
