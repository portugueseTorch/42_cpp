#pragma once
#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include "ICharacter.hpp"

class Character: public ICharacter
{
	public:
		Character(std::string name);
		Character(const Character &obj);
		Character &operator=(const Character &obj);
		~Character();

		std::string const & getName() const;
		void equip(AMateria *m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
	private:
		std::string _name;
		AMateria *_inventory[4];
		LinkedList _dropped;
		int	_num_materia;
};

#endif
