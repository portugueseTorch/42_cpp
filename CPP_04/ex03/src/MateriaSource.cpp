#include "../inc/MateriaSource.hpp"

MateriaSource::MateriaSource(): _num_recipes(0) {
	for (int i = 0; i < 4; i++)
		_recipes[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &obj) {
	*this = obj;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &obj) {
	if (this == &obj)
		return *this;
	for (int i = 0; i < 4; i++) {
		if (_recipes[i]) {
			delete _recipes[i];
			_recipes[i] = NULL;
		}
	}
	for (int i = 0; i < 4; i++) 
		_recipes[i] = obj._recipes[i]->clone();
	return *this;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++)
		if (_recipes[i])
			delete _recipes[i];
	_store.clearItems();
}

void MateriaSource::learnMateria(AMateria *m) {
	if (_num_recipes > 3) {
		if (m)
			_store.addNode(m);
		return ;
	} else if (!m)
		return ;
	int	i = 0;
	while (_recipes[i])
		i++;
	_recipes[i] = m;
	_num_recipes++;
	std::cout << "Materia " << m->getType() << " recipe successfuly learned!" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < 4; i++) {
		if (_recipes[i]) {
			if (_recipes[i]->getType() == type)
				return _recipes[i]->clone();
		}
	}
	return NULL;
}

