#include "../inc/Character.hpp"

Character::Character(std::string name): _name(name), _num_materia(0) {
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(const Character &obj) {
	*this = obj;
}

Character &Character::operator=(const Character &obj) {
	if (this == &obj)
		return *this;
	for (int i = 0; i < 4; i++) {
		if (_inventory[i]) {
			delete _inventory[i];
			_inventory[i] = NULL;
		}
	}
	for (int i = 0; i < 4; i++) {
		if (obj._inventory[i])
			_inventory[i] = obj._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
	return *this;
}

Character::~Character() {
	for (int i = 0; i < 4; i++)
		if (_inventory[i])
			delete _inventory[i];
	_dropped.clearItems();
}

std::string const &Character::getName() const {
	return _name;
}

void Character::equip(AMateria* m) {
	if (_num_materia > 3) {
		if (m)
			_dropped.addNode(m);
		return ;
	} else if (!m)
		return ;
	int	i = 0;
	while (_inventory[i])
		i++;
	_inventory[i] = m;
	_num_materia++;
	std::cout << "Materia " << m->getType() << " successfuly added to the inventory!" << std::endl;
}

void Character::unequip(int idx) {
	if (idx > 3 || idx < 0 || _inventory[idx] == NULL)
		return ;
	_dropped.addNode(_inventory[idx]);
	_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
	if (idx > 3 || idx < 0 || _inventory[idx] == NULL)
		return ;
	_inventory[idx]->use(target);
}

