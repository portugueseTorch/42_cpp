#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"
# include "LinkedList.hpp"

class MateriaSource: public IMateriaSource
{
	public:
		MateriaSource();
		MateriaSource(const MateriaSource &obj);
		MateriaSource &operator=(const MateriaSource &obj);
		~MateriaSource();

		void learnMateria(AMateria *m);
		AMateria* createMateria(std::string const & type);
	private:
		AMateria *_recipes[4];
		LinkedList _store;
		int	_num_recipes;
};

#endif
