#ifndef SHALLOWCAT_HPP
# define SHALLOWCAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class ShallowCat: virtual public Animal
{
	public:
		ShallowCat();
		ShallowCat(const ShallowCat &obj);
		ShallowCat &operator=(const ShallowCat &obj);
		~ShallowCat();

		virtual void	makeSound() const;
		Brain &getBrain() const;
	private:
		Brain *_brain;
};

#endif
