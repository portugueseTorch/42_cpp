#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat: virtual public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(const WrongCat &obj);
		WrongCat &operator=(const WrongCat &obj);
		~WrongCat();

		void	makeSound() const;
};

#endif
